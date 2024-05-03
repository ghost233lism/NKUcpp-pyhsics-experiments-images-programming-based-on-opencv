#include <iostream>
#include <opencv2/opencv.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

using namespace cv;
using namespace std;

int main() {
   
        string path = "Resources/Resources/result.jpg";
        // Read image
        Mat image = imread(path);
        if (image.empty()) {
            cout << "Could not open or find the image" << endl;
            return -1;
        }

        // Convert image to grayscale
        Mat gray;
        cvtColor(image, gray, COLOR_BGR2GRAY);

        // Initialize Tesseract API
        tesseract::TessBaseAPI tess;
        if (tess.Init(NULL, "chi_sim", tesseract::OEM_LSTM_ONLY) == -1) {
            cerr << "Could not initialize Tesseract." << endl;
            return -1;
        }
        tess.SetPageSegMode(tesseract::PSM_AUTO);

        // Set image data to Tesseract
        tess.SetImage(gray.data, gray.cols, gray.rows, 1, gray.step);

        // Recognize text
        tess.Recognize(0);

        // Get ResultIterator
        tesseract::ResultIterator* ri = tess.GetIterator();
        tesseract::PageIteratorLevel level = tesseract::RIL_WORD;

        // Iterate over all recognized words
        if (ri != nullptr) {
            do {
                const char* word = ri->GetUTF8Text(level);
                float conf = ri->Confidence(level);
                int x1, y1, x2, y2;
                ri->BoundingBox(level, &x1, &y1, &x2, &y2);

                // Draw rectangle on the image
                rectangle(image, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 0), 2);
                Rect rect(x1, y1, x2 - x1, y2 - y1);
                int area = rect.width * rect.height;
                if (area<1000000)
                {
                    image(rect).setTo(Scalar(255, 255, 255));
                }
                
            } while (ri->Next(level));
        }

        // Display the image
        imshow("Text Detection", image);
        imwrite("position.jpg", image);
        waitKey(0); // Wait for a key press to close the window

        // Clean up
        tess.End();
        if (ri != nullptr) {
            delete ri;
        }
    
   

    return 0;
}