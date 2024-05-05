#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#include<string>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

using namespace cv;

class Image
{
public:

	Image(std::string path)
	{
		img = imread(path);
		cvtColor(img, imgHSV, COLOR_BGR2HSV);//HSV
		cvtColor(img, imgGrey, COLOR_BGR2GRAY);//�Ҷ�ͼ��
	}
	Mat edge()
	{
		Mat se = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
		Mat edges, basic_grad;
		morphologyEx(imgGrey, basic_grad, MORPH_GRADIENT, se);
		threshold(basic_grad, edges, 0, 255, THRESH_BINARY | THRESH_OTSU);
		Mat kernel = getStructuringElement(MORPH_RECT, Size(30, 30));
		dilate(edges, edges, kernel);//����
		//imshow("edges", edges);
		return edges;//���һ��ͼ��ı�Ե���ҽ�������
	}
	Mat copyToWhite()
	{
		//Mat result = Mat::zeros(img.size(), img.type());
		Mat edges = edge();
		// ʹ��otsu����������ֵ��������Ե�����ת��Ϊ��ֵͼ��
		Mat binaryEdges;
		threshold(edges, binaryEdges, 0, 255, THRESH_BINARY | THRESH_OTSU);
		//imshow("binaryEdges", binaryEdges);
		// ����һ����ԭͼ�ߴ���ͬ��ȫ��ͼ��
		Mat whiteImage(cv::Size(img.size()), CV_8UC3, cv::Scalar(255, 255, 255));
		img.copyTo(whiteImage, binaryEdges); // ����Ե���ظ��Ƶ�ȫ��ͼ����
		// ����binaryEdges�ǵ�ͨ���ģ�������Ҫ������չΪ��ͨ����ƥ��ԭͼ��ͨ����
		binaryEdges.convertTo(binaryEdges, CV_8UC3);
		// ʹ��binaryEdges��Ϊ���룬��ԭͼ�еķǱ�Ե��������Ϊ��ɫ
		bitwise_and(img, img, whiteImage, binaryEdges); // ������Ե����
		// ��ʾ���
		return whiteImage;//��ͼ���б�Ե���������ȫ����Ϊ��ɫ
	}
	Mat clearOtherColors()
	{
		Mat preClearImage = copyToWhite();
		// ת����HSVɫ�ʿռ�
		Mat hsv;
		cvtColor(preClearImage, hsv, COLOR_BGR2HSV);

		// ������ɫ��HSV��Χ
		Scalar lower_blue(0, 0, 146);
		Scalar upper_blue(255, 36, 255);

		// ������ģ
		Mat mask;
		inRange(hsv, lower_blue, upper_blue, mask);

		// ��ת��ģ
		Mat mask_inv;
		bitwise_not(mask, mask_inv);
		// ����������ʾ��ͼƬ
		Mat result = preClearImage.clone(); // ����ԭͼ�����ͼ
		result.setTo(cv::Scalar(255, 255, 255), mask); // ����ģ��������Ϊ��ɫ
		// ��ʾ�ͱ�����
		//����HSV�����Ϊ��Ե�����������������
		return result;
	}
	Point2f getMiddlePoint(Point2f pt1, Point2f pt2)
	{
		// ��ȡ������е�
		return Point2f((pt1.x + pt2.x) / 2.0, (pt1.y + pt2.y) / 2.0);
	}
	double getPointAngle(Point2f pointO, Point2f pointA)
	{
		//��ȡ��ĽǶ�
		double angle = 0;
		Point2f point;
		double temp;
		point = Point2f((pointA.x - pointO.x), (pointA.y - pointO.y));

		if ((0 == point.x) && (0 == point.y))
		{
			return 0;
		}

		if (0 == point.x)
		{
			angle = 90;
			return angle;
		}

		if (0 == point.y)
		{
			angle = 0;
			return angle;
		}

		temp = fabsf(float(point.y) / float(point.x));
		temp = atan(temp);
		temp = temp * 180 / CV_PI;

		if ((0 < point.x) && (0 < point.y))
		{
			angle = 360 - temp;
			return angle;
		}

		if ((0 > point.x) && (0 < point.y))
		{
			angle = 360 - (180 - temp);
			return angle;
		}

		if ((0 < point.x) && (0 > point.y))
		{
			angle = temp;
			return angle;
		}

		if ((0 > point.x) && (0 > point.y))
		{
			angle = 180 - temp;
			return angle;
		}

		printf("sceneDrawing :: getAngle error!");
		return -1;
	}
	double getRotateAngle()
	{
		Mat imgDisRotate = clearOtherColors();
		Mat mGray, mBinary;
		cvtColor(imgDisRotate, mGray, COLOR_BGR2GRAY);
		threshold(mGray, mBinary, 100, 255, THRESH_BINARY_INV);

		std::vector<std::vector<Point>> contours;
		std::vector<Vec4i> hierarchy;
		findContours(mBinary, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());

		RotatedRect rtRotateMax, rtTemp;
		int maxSize = -1;
		for (int i = 0; i < contours.size(); i++) {
			rtTemp = minAreaRect(Mat(contours[i]));
			if (rtTemp.size.area() > maxSize) {
				maxSize = rtTemp.size.area();
				rtRotateMax = rtTemp;
			}
		}
		std::vector<Point2f> vPoint(4);
		rtRotateMax.points(vPoint.data());

		for (int i = 0; i < 4; i++)
		{
			for (int j = i; j < 4; j++)
			{
				if (vPoint[i].x > vPoint[j].x)
				{
					swap(vPoint[i], vPoint[j]);
				}
			}
		}
		Point2f ptLeft = getMiddlePoint(vPoint[0], vPoint[1]);
		Point2f ptRight = getMiddlePoint(vPoint[2], vPoint[3]);

		double ang = getPointAngle(ptLeft, ptRight);
		std::cout << "ang=" << ang << std::endl;

		return -ang; // ������ת�Ƕ�
	}
	double getRotateAngle(Mat imgDisRotate)
	{
		//�������أ����������ת�Ƕ�
		Mat mGray, mBinary;
		cvtColor(imgDisRotate, mGray, COLOR_BGR2GRAY);
		threshold(mGray, mBinary, 100, 255, THRESH_BINARY_INV);

		std::vector<std::vector<Point>> contours;
		std::vector<Vec4i> hierarchy;
		findContours(mBinary, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());

		RotatedRect rtRotateMax, rtTemp;
		int maxSize = -1;
		for (int i = 0; i < contours.size(); i++) {
			rtTemp = minAreaRect(Mat(contours[i]));
			if (rtTemp.size.area() > maxSize) {
				maxSize = rtTemp.size.area();
				rtRotateMax = rtTemp;
			}
		}
		std::vector<Point2f> vPoint(4);
		rtRotateMax.points(vPoint.data());

		for (int i = 0; i < 4; i++)
		{
			for (int j = i; j < 4; j++)
			{
				if (vPoint[i].x > vPoint[j].x)
				{
					swap(vPoint[i], vPoint[j]);
				}
			}
		}


		Point2f ptLeft = getMiddlePoint(vPoint[0], vPoint[1]);
		Point2f ptRight = getMiddlePoint(vPoint[2], vPoint[3]);

		double ang = getPointAngle(ptLeft, ptRight);
		std::cout << "ang=" << ang << std::endl;

		// ���������Ӵ�������ʾ�򱣴洦����ͼ�������Ҫ�Ļ�

		return -ang; // ������ת�Ƕ�
	}
	Mat rotate()
	{
		Mat src = clearOtherColors();
		if (src.empty()) {
			std::cout << "Could not open or find the image!" << std::endl;
		}

		// ������ת���ģ�����������ѡ��ͼ�������
		Point2f center(src.cols / 2.0F, src.rows / 2.0F);

		// ��ȡ��ת����
		double angle = getRotateAngle(); // ��ת�Ƕ�
		double scale = 1.0;  // ���ű���
		Mat rot = getRotationMatrix2D(center, angle, scale);

		// ������ͼ��ı߽�
		Rect2f bbox = RotatedRect(Point2f(), src.size(), (float)angle).boundingRect2f();

		// ������ת�����Կ���ƽ��
		rot.at<double>(0, 2) += bbox.width / 2.0 - src.cols / 2.0;
		rot.at<double>(1, 2) += bbox.height / 2.0 - src.rows / 2.0;

		// Ӧ�÷���任
		Mat dst;
		warpAffine(src, dst, rot, bbox.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(255, 255, 255));

		// ��ʾͼ��
		imshow("Rotated Image", dst);

		//waitKey(0);
		imgAfterRotate = dst;
		return dst;
	}
	Mat rotate(double angle)
	{
		//�������أ����ɶ����ת��ͼƬ
		//cout << "called" << endl;
		Mat src = clearOtherColors();
		if (src.empty()) {
			std::cout << "Could not open or find the image!" << std::endl;
		}

		// ������ת���ģ�����������ѡ��ͼ�������
		Point2f center(src.cols / 2.0F, src.rows / 2.0F);

		// ��ȡ��ת����

		double scale = 1.0;  // ���ű���
		Mat rot = getRotationMatrix2D(center, angle, scale);

		// ������ͼ��ı߽�
		Rect2f bbox = RotatedRect(Point2f(), src.size(), (float)angle).boundingRect2f();

		// ������ת�����Կ���ƽ��
		rot.at<double>(0, 2) += bbox.width / 2.0 - src.cols / 2.0;
		rot.at<double>(1, 2) += bbox.height / 2.0 - src.rows / 2.0;

		// Ӧ�÷���任
		Mat dst;
		warpAffine(src, dst, rot, bbox.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(255, 255, 255));

		// ��ʾͼ��
		imshow("Rotated Image", dst);

		//waitKey(0);
		imgAfterRotate = dst;
		return dst;
	}
	void eraseText()
	{
		Mat image = imgAfterRotate;
		if (image.empty()) {
			std::cout << "Could not open or find the image" << std::endl;
		}

		// Convert image to grayscale
		Mat gray;
		cvtColor(image, gray, COLOR_BGR2GRAY);

		// Initialize Tesseract API
		tesseract::TessBaseAPI tess;
		if (tess.Init(NULL, "chi_sim", tesseract::OEM_LSTM_ONLY) == -1) {
			std::cout << "Could not initialize Tesseract." << std::endl;
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
				//rectangle(image, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 0), 2);
				Rect rect(x1, y1, x2 - x1, y2 - y1);
				int area = rect.width * rect.height;
				if (area < 1000000)
				{
					image(rect).setTo(Scalar(255, 255, 255));
				}

			} while (ri->Next(level));
		}

		// Display the image
		imshow("Text Detection", image);
		//imwrite("phyAfterHandle.jpg", image);
		waitKey(0);
		imgOutput = image;
		// Clean up
		tess.End();
		if (ri != nullptr)
		{
			delete ri;
		}
	}
	void showImage()
	{
		imshow("img", img);
	}
	void showImageGrey()
	{
		imshow("imgGrey", imgGrey);
	}
	Mat getImgAfterRotate()
	{
		return imgAfterRotate;
	}
	void showOutputImage()
	{
		imshow("imgOutput", imgOutput);
	}
private:
	Mat img, imgHSV, imgGrey, imgAfterRotate, imgOutput;
};
