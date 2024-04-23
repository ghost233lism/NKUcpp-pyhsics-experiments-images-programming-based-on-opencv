#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<bits/stdc++.h>
using namespace std;
using namespace cv;

class Image
{
public:

	Image(string path)
	{
		img = imread(path);
		cvtColor(img, imgHSV, COLOR_BGR2HSV);//HSV
		cvtColor(img, imgGrey, COLOR_BGR2GRAY);//灰度图像
	}
	/*void canny()
	{
		Mat imgCanny, imgDia, imgBlur;
		GaussianBlur(imgGrey, imgBlur, Size(3, 3), 3, 0);//高斯模糊
		Canny(imgBlur, imgCanny, 25, 75);//提取边缘
		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		dilate(imgCanny, imgDia, kernel);//扩大
		//erode(imgDia, imgErode, kernel);//减少厚度
		imshow("imgDia", imgDia);
	}*/
	Mat edge()
	{
		Mat se = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
		Mat edges,basic_grad;
		morphologyEx(imgGrey, basic_grad, MORPH_GRADIENT, se);
		threshold(basic_grad, edges, 0, 255, THRESH_BINARY | THRESH_OTSU);
		Mat kernel = getStructuringElement(MORPH_RECT, Size(30, 30));
		dilate(edges, edges, kernel);//扩大
		imshow("edges", edges);
		return edges;
	}
	Mat copyToWhite()
	{
		//Mat result = Mat::zeros(img.size(), img.type());
		Mat edges = edge();
		// 使用otsu方法进行阈值处理，将边缘检测结果转换为二值图像
		Mat binaryEdges;
		threshold(edges, binaryEdges, 0, 255, THRESH_BINARY | THRESH_OTSU);
		imshow("binaryEdges", binaryEdges);
		// 创建一个与原图尺寸相同的全白图像
		Mat whiteImage(cv::Size(img.size()), CV_8UC3, cv::Scalar(255, 255, 255));
		img.copyTo(whiteImage, binaryEdges); // 将边缘像素复制到全白图像上
		// 由于binaryEdges是单通道的，我们需要将其扩展为三通道以匹配原图的通道数
		binaryEdges.convertTo(binaryEdges, CV_8UC3);
		// 使用binaryEdges作为掩码，将原图中的非边缘像素设置为白色
		bitwise_and(img, img, whiteImage, binaryEdges); // 保留边缘像素
		// 显示结果
		//imshow("Result Image", result);
		imshow("White", whiteImage);
		return whiteImage;
	}
	void clearOtherColors()
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

		imshow("result", result);
		imwrite("result1.jpg", result);
		// 显示和保存结果
	}
	void showImage()
	{
		imshow("img", img);
	}
	void showImageGrey()
	{
		imshow("imgGrey", imgGrey);
	}

private:
	Mat img, imgHSV, imgGrey ;
};
int main()
{
	Image img("Resources/Resources/ph3.jpg");
	img.showImage();
	//img.showImageGrey();
	//img.canny();
	img.edge();
	//img.copyToWhite();
	img.clearOtherColors();
	waitKey(0);
	return 0;
}


