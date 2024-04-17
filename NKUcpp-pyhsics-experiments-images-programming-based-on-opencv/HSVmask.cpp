#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<bits/stdc++.h>
using namespace std;
using namespace cv;

Mat imgHSV,mask;
int hmin = 0, smin = 0,vmin=0;
int hmax = 255, smax = 255, vmax = 255;
void main()
{
	string path = "Resources/Resources/ph2.jpg";
	Mat img = imread(path);

	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 255);
	createTrackbar("Hue Max", "Trackbars", &hmax, 255);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

		
	while (true)
	{

		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);

		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Image MASK", mask);
		waitKey(1);
	}
} 
