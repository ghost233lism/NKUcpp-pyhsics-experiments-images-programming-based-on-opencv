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
//		cvtColor(img, imgGrey, COLOR_BGR2GRAY);//�Ҷ�ͼ��
//		
//		
//	}
//	void canny()
//	{
//		Mat imgCanny, imgDia, imgBlur;
//		GaussianBlur(imgGrey, imgBlur, Size(3, 3), 3, 0);//��˹ģ��
//		Canny(imgBlur, imgCanny, 25, 75);//��ȡ��Ե
//		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
//		dilate(imgCanny, imgDia, kernel);//����
//		//erode(imgDia, imgErode, kernel);//���ٺ��
//		imshow("imgDia", imgDia);
//	}
//	Mat edge()
//	{
//		Mat se = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
//		Mat edges,basic_grad;
//		morphologyEx(imgGrey, basic_grad, MORPH_GRADIENT, se);
//		threshold(basic_grad, edges, 0, 255, THRESH_BINARY | THRESH_OTSU);
//		Mat kernel = getStructuringElement(MORPH_RECT, Size(4, 4));
//		dilate(edges, edges, kernel);//����
//		imshow("edges", edges);
//		return edges;
//	}
//	void createMask()
//	{
//		//Mat result = Mat::zeros(img.size(), img.type());
//
//		Mat edges = edge();
//		// ʹ��otsu����������ֵ��������Ե�����ת��Ϊ��ֵͼ��
//		Mat binaryEdges;
//		threshold(edges, binaryEdges, 0, 255, THRESH_BINARY | THRESH_OTSU);
//
//		// ����һ����ԭͼ�ߴ���ͬ��ȫ��ͼ��
//		Mat whiteImage(cv::Size(img.size()), CV_8UC3, cv::Scalar(255, 255, 255));
//		img.copyTo(whiteImage, binaryEdges); // ����Ե���ظ��Ƶ�ȫ��ͼ����
//
//		// ����binaryEdges�ǵ�ͨ���ģ�������Ҫ������չΪ��ͨ����ƥ��ԭͼ��ͨ����
//		binaryEdges.convertTo(binaryEdges, CV_8UC3);
//
//		// ʹ��binaryEdges��Ϊ���룬��ԭͼ�еķǱ�Ե��������Ϊ��ɫ
//		bitwise_and(img, img, whiteImage, binaryEdges); // ������Ե����
//
//		// ��ʾ���
//		//imshow("Result Image", result);
//		imshow("White", whiteImage);
//	}
//	void showImage()
//	{
//		imshow("img", img);
//	}
//	void showImageGrey()
//	{
//		imshow("imgGrey", imgGrey);
//	}
//
//private:
//	Mat img, imgHSV, imgGrey ;
//
//};
//int main()
//{
//	Image img("Resources/Resources/ph2.jpg");
//	img.showImage();
//	img.showImageGrey();
//	img.canny();
//	img.edge();
//	img.createMask();
//	waitKey(0);
//	return 0;
//}
//
//
