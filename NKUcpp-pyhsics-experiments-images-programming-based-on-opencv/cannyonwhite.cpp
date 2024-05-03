//#include<opencv2/imgcodecs.hpp>
//#include<opencv2/highgui.hpp>
//#include<opencv2/imgproc.hpp>
//#include<bits/stdc++.h>
//#include <tesseract/baseapi.h>
//#include <leptonica/allheaders.h>
//using namespace std;
//using namespace cv;
//
//class Image
//{
//public:
//
//	Image(string path)
//	{
//		img = imread(path);
//		cvtColor(img, imgHSV, COLOR_BGR2HSV);//HSV
//		cvtColor(img, imgGrey, COLOR_BGR2GRAY);//�Ҷ�ͼ��
//	}
//	Mat edge()
//	{
//		Mat se = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
//		Mat edges, basic_grad;
//		morphologyEx(imgGrey, basic_grad, MORPH_GRADIENT, se);
//		threshold(basic_grad, edges, 0, 255, THRESH_BINARY | THRESH_OTSU);
//		Mat kernel = getStructuringElement(MORPH_RECT, Size(30, 30));
//		dilate(edges, edges, kernel);//����
//		//imshow("edges", edges);
//		return edges;//���һ��ͼ��ı�Ե���ҽ�������
//	}
//	Mat copyToWhite()
//	{
//		//Mat result = Mat::zeros(img.size(), img.type());
//		Mat edges = edge();
//		// ʹ��otsu����������ֵ��������Ե�����ת��Ϊ��ֵͼ��
//		Mat binaryEdges;
//		threshold(edges, binaryEdges, 0, 255, THRESH_BINARY | THRESH_OTSU);
//		//imshow("binaryEdges", binaryEdges);
//		// ����һ����ԭͼ�ߴ���ͬ��ȫ��ͼ��
//		Mat whiteImage(cv::Size(img.size()), CV_8UC3, cv::Scalar(255, 255, 255));
//		img.copyTo(whiteImage, binaryEdges); // ����Ե���ظ��Ƶ�ȫ��ͼ����
//		// ����binaryEdges�ǵ�ͨ���ģ�������Ҫ������չΪ��ͨ����ƥ��ԭͼ��ͨ����
//		binaryEdges.convertTo(binaryEdges, CV_8UC3);
//		// ʹ��binaryEdges��Ϊ���룬��ԭͼ�еķǱ�Ե��������Ϊ��ɫ
//		bitwise_and(img, img, whiteImage, binaryEdges); // ������Ե����
//		// ��ʾ���
//		//imshow("Result Image", result);
//		//imshow("White", whiteImage);
//		return whiteImage;//��ͼ���б�Ե���������ȫ����Ϊ��ɫ
//	}
//	Mat clearOtherColors()
//	{
//		Mat preClearImage = copyToWhite();
//		// ת����HSVɫ�ʿռ�
//		Mat hsv;
//		cvtColor(preClearImage, hsv, COLOR_BGR2HSV);
//
//		// ������ɫ��HSV��Χ
//		Scalar lower_blue(0, 0, 146);
//		Scalar upper_blue(255, 36, 255);
//
//		// ������ģ
//		Mat mask;
//		inRange(hsv, lower_blue, upper_blue, mask);
//
//		// ��ת��ģ
//		Mat mask_inv;
//		bitwise_not(mask, mask_inv);
//		// ����������ʾ��ͼƬ
//		Mat result = preClearImage.clone(); // ����ԭͼ�����ͼ
//		result.setTo(cv::Scalar(255, 255, 255), mask); // ����ģ��������Ϊ��ɫ
//
//		//imshow("result", result);
//		//imwrite("result1.jpg", result);
//		// ��ʾ�ͱ�����
//		//����HSV�����Ϊ��Ե�����������������
//		return result;
//	}
//
//	bool cmp_x(Point pt1, Point pt2)
//	{
//		// �ȽϺ�������������
//		return pt1.x < pt2.x;
//	}
//	Point2f get_mid_pt(Point2f pt1, Point2f pt2)
//	{
//		// ��ȡ������е�
//		return Point2f((pt1.x + pt2.x) / 2.0, (pt1.y + pt2.y) / 2.0);
//	}
//	double get_point_angle(Point2f pointO, Point2f pointA)
//	{
//		//��ȡ��ĽǶ�
//		double angle = 0;
//		Point2f point;
//		double temp;
//		point = Point2f((pointA.x - pointO.x), (pointA.y - pointO.y));
//
//		if ((0 == point.x) && (0 == point.y))
//		{
//			return 0;
//		}
//
//		if (0 == point.x)
//		{
//			angle = 90;
//			return angle;
//		}
//
//		if (0 == point.y)
//		{
//			angle = 0;
//			return angle;
//		}
//
//		temp = fabsf(float(point.y) / float(point.x));
//		temp = atan(temp);
//		temp = temp * 180 / CV_PI;
//
//		if ((0 < point.x) && (0 < point.y))
//		{
//			angle = 360 - temp;
//			return angle;
//		}
//
//		if ((0 > point.x) && (0 < point.y))
//		{
//			angle = 360 - (180 - temp);
//			return angle;
//		}
//
//		if ((0 < point.x) && (0 > point.y))
//		{
//			angle = temp;
//			return angle;
//		}
//
//		if ((0 > point.x) && (0 > point.y))
//		{
//			angle = 180 - temp;
//			return angle;
//		}
//
//		printf("sceneDrawing :: getAngle error!");
//		return -1;
//	}
//	double getRotateAngle()
//	{
//		Mat imgDisRotate = clearOtherColors();
//		Mat m_gray, m_bi;
//		cvtColor(imgDisRotate, m_gray, COLOR_BGR2GRAY);
//		threshold(m_gray, m_bi, 100, 255, THRESH_BINARY_INV);
//
//		vector<vector<Point>> contours;
//		vector<Vec4i> hierarchy;
//		findContours(m_bi, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());
//
//		RotatedRect rt_rot_max, rt_tmp;
//		int max_size = -1;
//		for (int i = 0; i < contours.size(); i++) {
//			rt_tmp = minAreaRect(Mat(contours[i]));
//			if (rt_tmp.size.area() > max_size) {
//				max_size = rt_tmp.size.area();
//				rt_rot_max = rt_tmp;
//			}
//		}
//		vector<Point2f> v_pt(4);
//		rt_rot_max.points(v_pt.data());
//
//		for (int i = 0; i < 4; i++)
//		{
//			for (int j = i; j < 4; j++)
//			{
//				if (v_pt[i].x > v_pt[j].x)
//				{
//					swap(v_pt[i], v_pt[j]);
//				}
//			}
//		}
//
//
//		Point2f pt_left = get_mid_pt(v_pt[0], v_pt[1]);
//		Point2f pt_right = get_mid_pt(v_pt[2], v_pt[3]);
//
//		double ang = get_point_angle(pt_left, pt_right);
//		cout << "ang=" << ang << endl;
//
//		// ���������Ӵ�������ʾ�򱣴洦����ͼ�������Ҫ�Ļ�
//		
//		return -ang; // ������ת�Ƕ�
//	}
//	double getRotateAngle(Mat imgDisRotate)
//	{
//		//�������أ����������ת�Ƕ�
//		//cout << "called" << endl;
//		//imshow("imgDisRotate", imgDisRotate);
//		Mat m_gray, m_bi;
//		cvtColor(imgDisRotate, m_gray, COLOR_BGR2GRAY);
//		threshold(m_gray, m_bi, 100, 255, THRESH_BINARY_INV);
//
//		vector<vector<Point>> contours;
//		vector<Vec4i> hierarchy;
//		findContours(m_bi, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());
//
//		RotatedRect rt_rot_max, rt_tmp;
//		int max_size = -1;
//		for (int i = 0; i < contours.size(); i++) {
//			rt_tmp = minAreaRect(Mat(contours[i]));
//			if (rt_tmp.size.area() > max_size) {
//				max_size = rt_tmp.size.area();
//				rt_rot_max = rt_tmp;
//			}
//		}
//		vector<Point2f> v_pt(4);
//		rt_rot_max.points(v_pt.data());
//
//		for (int i = 0; i < 4; i++)
//		{
//			for (int j = i; j < 4; j++)
//			{
//				if (v_pt[i].x > v_pt[j].x)
//				{
//					swap(v_pt[i], v_pt[j]);
//				}
//			}
//		}
//
//
//		Point2f pt_left = get_mid_pt(v_pt[0], v_pt[1]);
//		Point2f pt_right = get_mid_pt(v_pt[2], v_pt[3]);
//
//		double ang = get_point_angle(pt_left, pt_right);
//		cout << "ang=" << ang << endl;
//
//		// ���������Ӵ�������ʾ�򱣴洦����ͼ�������Ҫ�Ļ�
//		
//		return -ang; // ������ת�Ƕ�
//	}
//	Mat rotate()
//	{
//		Mat src = clearOtherColors();
//		if (src.empty()) {
//			std::cout << "Could not open or find the image!" << std::endl;
//		}
//
//		// ������ת���ģ�����������ѡ��ͼ�������
//		Point2f center(src.cols / 2.0F, src.rows / 2.0F);
//
//		// ��ȡ��ת����
//		double angle = getRotateAngle(); // ��ת�Ƕ�
//		double scale = 1.0;  // ���ű���
//		Mat rot = getRotationMatrix2D(center, angle, scale);
//
//		// ������ͼ��ı߽�
//		Rect2f bbox = RotatedRect(Point2f(), src.size(), (float)angle).boundingRect2f();
//
//		// ������ת�����Կ���ƽ��
//		rot.at<double>(0, 2) += bbox.width / 2.0 - src.cols / 2.0;
//		rot.at<double>(1, 2) += bbox.height / 2.0 - src.rows / 2.0;
//
//		// Ӧ�÷���任
//		Mat dst;
//		warpAffine(src, dst, rot, bbox.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(255, 255, 255));
//
//		// ��ʾͼ��
//		imshow("Rotated Image", dst);
//		
//		//waitKey(0);
//		imgAfterRotate = dst;
//		return dst;
//	}
//	Mat rotate(double angle)
//	{
//		//�������أ����ɶ����ת��ͼƬ
//		//cout << "called" << endl;
//		Mat src = clearOtherColors();
//		if (src.empty()) {
//			std::cout << "Could not open or find the image!" << std::endl;
//		}
//
//		// ������ת���ģ�����������ѡ��ͼ�������
//		Point2f center(src.cols / 2.0F, src.rows / 2.0F);
//
//		// ��ȡ��ת����
//		
//		double scale = 1.0;  // ���ű���
//		Mat rot = getRotationMatrix2D(center, angle, scale);
//
//		// ������ͼ��ı߽�
//		Rect2f bbox = RotatedRect(Point2f(), src.size(), (float)angle).boundingRect2f();
//
//		// ������ת�����Կ���ƽ��
//		rot.at<double>(0, 2) += bbox.width / 2.0 - src.cols / 2.0;
//		rot.at<double>(1, 2) += bbox.height / 2.0 - src.rows / 2.0;
//
//		// Ӧ�÷���任
//		Mat dst;
//		warpAffine(src, dst, rot, bbox.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(255, 255, 255));
//
//		// ��ʾͼ��
//		imshow("Rotated Image", dst);
//
//		//waitKey(0);
//		imgAfterRotate = dst;
//		return dst;
//	}
//	void eraseText()
//	{
//		Mat image = imgAfterRotate;
//		if (image.empty()) {
//			cout << "Could not open or find the image" << endl;
//		}
//
//		// Convert image to grayscale
//		Mat gray;
//		cvtColor(image, gray, COLOR_BGR2GRAY);
//
//		// Initialize Tesseract API
//		tesseract::TessBaseAPI tess;
//		if (tess.Init(NULL, "chi_sim", tesseract::OEM_LSTM_ONLY) == -1) {
//			cerr << "Could not initialize Tesseract." << endl;
//		}
//		tess.SetPageSegMode(tesseract::PSM_AUTO);
//
//		// Set image data to Tesseract
//		tess.SetImage(gray.data, gray.cols, gray.rows, 1, gray.step);
//
//		// Recognize text
//		tess.Recognize(0);
//
//		// Get ResultIterator
//		tesseract::ResultIterator* ri = tess.GetIterator();
//		tesseract::PageIteratorLevel level = tesseract::RIL_WORD;
//
//		// Iterate over all recognized words
//		if (ri != nullptr) {
//			do {
//				const char* word = ri->GetUTF8Text(level);
//				float conf = ri->Confidence(level);
//				int x1, y1, x2, y2;
//				ri->BoundingBox(level, &x1, &y1, &x2, &y2);
//
//				// Draw rectangle on the image
//			   // rectangle(image, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 0), 2);
//				Rect rect(x1, y1, x2 - x1, y2 - y1);
//				int area = rect.width * rect.height;
//				if (area < 1000000)
//				{
//					image(rect).setTo(Scalar(255, 255, 255));
//				}
//
//			} while (ri->Next(level));
//		}
//
//		// Display the image
//		imshow("Text Detection", image);
//		//imwrite("phyAfterHandle.jpg", image);
//		waitKey(0);
//		imgOutput = image;
//		//imwrite("position.jpg", image);
//		//waitKey(0); // Wait for a key press to close the window
//		// Clean up
//		tess.End();
//		if (ri != nullptr) {
//			delete ri;
//		}
//	}
//	void showImage()
//	{
//		imshow("img", img);
//	}
//	void showImageGrey()
//	{
//		imshow("imgGrey", imgGrey);
//	}
//	Mat getResult()
//	{
//		return imgAfterRotate;
//	}
//	void showOutputImage()
//	{
//		imshow("imgOutput", imgOutput);
//	}
//private:
//	Mat img, imgHSV, imgGrey,imgAfterRotate,imgOutput;
//};
//int main()
//{
//	Image img("Resources/Resources/phy.jpg");
//	img.showImage();
//	img.rotate();
//	waitKey(1);
//	string order;
//	while (true)
//	{
//		cout << "ͼ���Ƿ���Ҫ�������ɣ�[Y]/[N]" << endl;
//		cin >> order;
//		if (order == "Y")
//		{
//			double angle=img.getRotateAngle(img.getResult());
//			img.rotate(angle);
//			waitKey(1);
//		}
//		else if (order == "N")
//		{
//			img.eraseText();
//			break;
//		}
//		else
//		{
//			cout << "ָ�����" << endl;
//		}
//	}
//	return 0;
//}
//
//
