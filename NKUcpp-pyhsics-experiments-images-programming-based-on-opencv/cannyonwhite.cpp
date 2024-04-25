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
//	}
//	/*void canny()
//	{
//		Mat imgCanny, imgDia, imgBlur;
//		GaussianBlur(imgGrey, imgBlur, Size(3, 3), 3, 0);//��˹ģ��
//		Canny(imgBlur, imgCanny, 25, 75);//��ȡ��Ե
//		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
//		dilate(imgCanny, imgDia, kernel);//����
//		//erode(imgDia, imgErode, kernel);//���ٺ��
//		imshow("imgDia", imgDia);
//	}*/
//	Mat edge()
//	{
//		Mat se = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
//		Mat edges,basic_grad;
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
//		if (ang > 180||ang<10)
//		{
//			return 0;
//		}
//		return -ang; // ������ת�Ƕ�
//		//���е����⣬����Ƕ���ֵ����ȷ��
//	}
//	void rotate()
//	{
//		Mat src = clearOtherColors();
//	
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
//		waitKey(0);
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
//};
//int main()
//{
//	Image img("Resources/Resources/ph2.jpg");
//	//img.showImage();
//	//img.showImageGrey();
//	//img.canny();
//	//img.edge();
//	//img.copyToWhite();
//	//img.clearOtherColors();
//	//img.rotateAndReturnAngle();
//	img.rotate();
//	waitKey(0);
//	return 0;
//}
//
//
