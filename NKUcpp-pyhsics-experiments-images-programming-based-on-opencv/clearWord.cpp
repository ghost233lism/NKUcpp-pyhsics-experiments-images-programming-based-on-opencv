//#include<opencv2/imgcodecs.hpp>
//#include<opencv2/highgui.hpp>
//#include<opencv2/imgproc.hpp>
//#include<bits/stdc++.h>
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	Mat img = cv::imread("Resources/Resources/result1.jpg");
//	Mat gray;
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//
//	//图像二值化，筛选出白色区域部分
//	Mat thresh;
//	threshold(gray, thresh, 80, 255, THRESH_BINARY);
//	imshow("gray", gray);
//	imshow("thresh", thresh);
//	waitKey(0);
//}