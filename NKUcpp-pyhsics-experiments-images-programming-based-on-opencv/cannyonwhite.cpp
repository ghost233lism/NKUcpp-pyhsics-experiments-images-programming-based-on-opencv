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
		cvtColor(img, imgGrey, COLOR_BGR2GRAY);//�Ҷ�ͼ��
	}
	/*void canny()
	{
		Mat imgCanny, imgDia, imgBlur;
		GaussianBlur(imgGrey, imgBlur, Size(3, 3), 3, 0);//��˹ģ��
		Canny(imgBlur, imgCanny, 25, 75);//��ȡ��Ե
		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		dilate(imgCanny, imgDia, kernel);//����
		//erode(imgDia, imgErode, kernel);//���ٺ��
		imshow("imgDia", imgDia);
	}*/
	Mat edge()
	{
		Mat se = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
		Mat edges,basic_grad;
		morphologyEx(imgGrey, basic_grad, MORPH_GRADIENT, se);
		threshold(basic_grad, edges, 0, 255, THRESH_BINARY | THRESH_OTSU);
		Mat kernel = getStructuringElement(MORPH_RECT, Size(30, 30));
		dilate(edges, edges, kernel);//����
		imshow("edges", edges);
		return edges;
	}
	Mat copyToWhite()
	{
		//Mat result = Mat::zeros(img.size(), img.type());
		Mat edges = edge();
		// ʹ��otsu����������ֵ��������Ե�����ת��Ϊ��ֵͼ��
		Mat binaryEdges;
		threshold(edges, binaryEdges, 0, 255, THRESH_BINARY | THRESH_OTSU);
		imshow("binaryEdges", binaryEdges);
		// ����һ����ԭͼ�ߴ���ͬ��ȫ��ͼ��
		Mat whiteImage(cv::Size(img.size()), CV_8UC3, cv::Scalar(255, 255, 255));
		img.copyTo(whiteImage, binaryEdges); // ����Ե���ظ��Ƶ�ȫ��ͼ����
		// ����binaryEdges�ǵ�ͨ���ģ�������Ҫ������չΪ��ͨ����ƥ��ԭͼ��ͨ����
		binaryEdges.convertTo(binaryEdges, CV_8UC3);
		// ʹ��binaryEdges��Ϊ���룬��ԭͼ�еķǱ�Ե��������Ϊ��ɫ
		bitwise_and(img, img, whiteImage, binaryEdges); // ������Ե����
		// ��ʾ���
		//imshow("Result Image", result);
		imshow("White", whiteImage);
		return whiteImage;
	}
	void clearOtherColors()
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

		imshow("result", result);
		imwrite("result1.jpg", result);
		// ��ʾ�ͱ�����
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


