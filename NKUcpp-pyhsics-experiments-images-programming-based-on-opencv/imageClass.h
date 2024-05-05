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
		cvtColor(img, imgGrey, COLOR_BGR2GRAY);//灰度图像
	}
	Mat edge()
	{
		Mat se = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
		Mat edges, basic_grad;
		morphologyEx(imgGrey, basic_grad, MORPH_GRADIENT, se);
		threshold(basic_grad, edges, 0, 255, THRESH_BINARY | THRESH_OTSU);
		Mat kernel = getStructuringElement(MORPH_RECT, Size(30, 30));
		dilate(edges, edges, kernel);//扩大
		//imshow("edges", edges);
		return edges;//检测一个图像的边缘并且进行扩大
	}
	Mat copyToWhite()
	{
		//Mat result = Mat::zeros(img.size(), img.type());
		Mat edges = edge();
		// 使用otsu方法进行阈值处理，将边缘检测结果转换为二值图像
		Mat binaryEdges;
		threshold(edges, binaryEdges, 0, 255, THRESH_BINARY | THRESH_OTSU);
		//imshow("binaryEdges", binaryEdges);
		// 创建一个与原图尺寸相同的全白图像
		Mat whiteImage(cv::Size(img.size()), CV_8UC3, cv::Scalar(255, 255, 255));
		img.copyTo(whiteImage, binaryEdges); // 将边缘像素复制到全白图像上
		// 由于binaryEdges是单通道的，我们需要将其扩展为三通道以匹配原图的通道数
		binaryEdges.convertTo(binaryEdges, CV_8UC3);
		// 使用binaryEdges作为掩码，将原图中的非边缘像素设置为白色
		bitwise_and(img, img, whiteImage, binaryEdges); // 保留边缘像素
		// 显示结果
		return whiteImage;//把图像中边缘以外的像素全部变为白色
	}
	Mat clearOtherColors()
	{
		Mat preClearImage = copyToWhite();
		// 转换到HSV色彩空间
		Mat hsv;
		cvtColor(preClearImage, hsv, COLOR_BGR2HSV);

		// 定义蓝色的HSV范围
		Scalar lower_blue(0, 0, 146);
		Scalar upper_blue(255, 36, 255);

		// 创建掩模
		Mat mask;
		inRange(hsv, lower_blue, upper_blue, mask);

		// 反转掩模
		Mat mask_inv;
		bitwise_not(mask, mask_inv);
		// 创建最终显示的图片
		Mat result = preClearImage.clone(); // 复制原图到结果图
		result.setTo(cv::Scalar(255, 255, 255), mask); // 在掩模区域设置为白色
		// 显示和保存结果
		//利用HSV清除因为边缘扩大带来的无用像素
		return result;
	}
	Point2f getMiddlePoint(Point2f pt1, Point2f pt2)
	{
		// 获取两点的中点
		return Point2f((pt1.x + pt2.x) / 2.0, (pt1.y + pt2.y) / 2.0);
	}
	double getPointAngle(Point2f pointO, Point2f pointA)
	{
		//获取点的角度
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

		return -ang; // 返回旋转角度
	}
	double getRotateAngle(Mat imgDisRotate)
	{
		//函数重载，多次生成旋转角度
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

		// 这里可以添加代码来显示或保存处理后的图像，如果需要的话

		return -ang; // 返回旋转角度
	}
	Mat rotate()
	{
		Mat src = clearOtherColors();
		if (src.empty()) {
			std::cout << "Could not open or find the image!" << std::endl;
		}

		// 设置旋转中心；在这里我们选择图像的中心
		Point2f center(src.cols / 2.0F, src.rows / 2.0F);

		// 获取旋转矩阵
		double angle = getRotateAngle(); // 旋转角度
		double scale = 1.0;  // 缩放比例
		Mat rot = getRotationMatrix2D(center, angle, scale);

		// 计算新图像的边界
		Rect2f bbox = RotatedRect(Point2f(), src.size(), (float)angle).boundingRect2f();

		// 调整旋转矩阵以考虑平移
		rot.at<double>(0, 2) += bbox.width / 2.0 - src.cols / 2.0;
		rot.at<double>(1, 2) += bbox.height / 2.0 - src.rows / 2.0;

		// 应用仿射变换
		Mat dst;
		warpAffine(src, dst, rot, bbox.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(255, 255, 255));

		// 显示图像
		imshow("Rotated Image", dst);

		//waitKey(0);
		imgAfterRotate = dst;
		return dst;
	}
	Mat rotate(double angle)
	{
		//函数重载，生成多次旋转后图片
		//cout << "called" << endl;
		Mat src = clearOtherColors();
		if (src.empty()) {
			std::cout << "Could not open or find the image!" << std::endl;
		}

		// 设置旋转中心；在这里我们选择图像的中心
		Point2f center(src.cols / 2.0F, src.rows / 2.0F);

		// 获取旋转矩阵

		double scale = 1.0;  // 缩放比例
		Mat rot = getRotationMatrix2D(center, angle, scale);

		// 计算新图像的边界
		Rect2f bbox = RotatedRect(Point2f(), src.size(), (float)angle).boundingRect2f();

		// 调整旋转矩阵以考虑平移
		rot.at<double>(0, 2) += bbox.width / 2.0 - src.cols / 2.0;
		rot.at<double>(1, 2) += bbox.height / 2.0 - src.rows / 2.0;

		// 应用仿射变换
		Mat dst;
		warpAffine(src, dst, rot, bbox.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(255, 255, 255));

		// 显示图像
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
