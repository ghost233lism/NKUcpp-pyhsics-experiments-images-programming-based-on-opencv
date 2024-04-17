//#include<opencv2/imgcodecs.hpp>
//#include<opencv2/highgui.hpp>
//#include<opencv2/imgproc.hpp>
//#include<bits/stdc++.h>
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
//		cvtColor(img, imgGrey, COLOR_BGR2GRAY);//灰度图像
//		GaussianBlur(imgGrey, imgBlur, Size(3, 3), 3, 0);//高斯模糊
//		Canny(imgBlur, imgCanny, 25, 75);//提取边缘
//
//		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
//		dilate(imgCanny, imgDia, kernel);//扩大
//		//erode(imgDia, imgErode, kernel);//减少厚度
//	}
//	void showImage()
//	{
//		imshow("img", img);
//	}
//	void showImageGrey()
//	{
//		imshow("imgGrey", imgGrey);
//	}
//	void showImageCanny()
//	{
//		imshow("imgCanny", imgCanny);
//	}
//
//private:
//	Mat img, imgHSV, imgGrey,imgBlur,imgCanny,imgDia;
//	
//};
//int main()
//{
//	Image img("Resources/Resources/phy.jpg");
//	img.showImage();
//	img.showImageGrey();
//	img.showImageCanny();
//	waitKey(0);
//	return 0;
//}
//
//
