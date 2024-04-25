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
//	}
//	/*void canny()
//	{
//		Mat imgCanny, imgDia, imgBlur;
//		GaussianBlur(imgGrey, imgBlur, Size(3, 3), 3, 0);//高斯模糊
//		Canny(imgBlur, imgCanny, 25, 75);//提取边缘
//		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
//		dilate(imgCanny, imgDia, kernel);//扩大
//		//erode(imgDia, imgErode, kernel);//减少厚度
//		imshow("imgDia", imgDia);
//	}*/
//	Mat edge()
//	{
//		Mat se = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
//		Mat edges,basic_grad;
//		morphologyEx(imgGrey, basic_grad, MORPH_GRADIENT, se);
//		threshold(basic_grad, edges, 0, 255, THRESH_BINARY | THRESH_OTSU);
//		Mat kernel = getStructuringElement(MORPH_RECT, Size(30, 30));
//		dilate(edges, edges, kernel);//扩大
//		//imshow("edges", edges);
//		return edges;//检测一个图像的边缘并且进行扩大
//	}
//	Mat copyToWhite()
//	{
//		//Mat result = Mat::zeros(img.size(), img.type());
//		Mat edges = edge();
//		// 使用otsu方法进行阈值处理，将边缘检测结果转换为二值图像
//		Mat binaryEdges;
//		threshold(edges, binaryEdges, 0, 255, THRESH_BINARY | THRESH_OTSU);
//		//imshow("binaryEdges", binaryEdges);
//		// 创建一个与原图尺寸相同的全白图像
//		Mat whiteImage(cv::Size(img.size()), CV_8UC3, cv::Scalar(255, 255, 255));
//		img.copyTo(whiteImage, binaryEdges); // 将边缘像素复制到全白图像上
//		// 由于binaryEdges是单通道的，我们需要将其扩展为三通道以匹配原图的通道数
//		binaryEdges.convertTo(binaryEdges, CV_8UC3);
//		// 使用binaryEdges作为掩码，将原图中的非边缘像素设置为白色
//		bitwise_and(img, img, whiteImage, binaryEdges); // 保留边缘像素
//		// 显示结果
//		//imshow("Result Image", result);
//		//imshow("White", whiteImage);
//		return whiteImage;//把图像中边缘以外的像素全部变为白色
//	}
//	Mat clearOtherColors()
//	{
//		Mat preClearImage = copyToWhite();
//		// 转换到HSV色彩空间
//		Mat hsv;
//		cvtColor(preClearImage, hsv, COLOR_BGR2HSV);
//
//		// 定义蓝色的HSV范围
//		Scalar lower_blue(0, 0, 146);
//		Scalar upper_blue(255, 36, 255);
//
//		// 创建掩模
//		Mat mask;
//		inRange(hsv, lower_blue, upper_blue, mask);
//
//		// 反转掩模
//		Mat mask_inv;
//		bitwise_not(mask, mask_inv);
//		// 创建最终显示的图片
//		Mat result = preClearImage.clone(); // 复制原图到结果图
//		result.setTo(cv::Scalar(255, 255, 255), mask); // 在掩模区域设置为白色
//
//		//imshow("result", result);
//		//imwrite("result1.jpg", result);
//		// 显示和保存结果
//		//利用HSV清除因为边缘扩大带来的无用像素
//		return result;
//	}
//	
//	bool cmp_x(Point pt1, Point pt2)
//	{
//		// 比较函数，用于排序
//		return pt1.x < pt2.x;
//	}
//	Point2f get_mid_pt(Point2f pt1, Point2f pt2)
//	{
//		// 获取两点的中点
//		return Point2f((pt1.x + pt2.x) / 2.0, (pt1.y + pt2.y) / 2.0);
//	}
//	double get_point_angle(Point2f pointO, Point2f pointA)
//	{
//		//获取点的角度
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
//		// 这里可以添加代码来显示或保存处理后的图像，如果需要的话
//		if (ang > 180||ang<10)
//		{
//			return 0;
//		}
//		return -ang; // 返回旋转角度
//		//还有点问题，这个角度阈值不好确定
//	}
//	void rotate()
//	{
//		Mat src = clearOtherColors();
//	
//		if (src.empty()) {
//			std::cout << "Could not open or find the image!" << std::endl;
//		}
//
//		// 设置旋转中心；在这里我们选择图像的中心
//		Point2f center(src.cols / 2.0F, src.rows / 2.0F);
//
//		// 获取旋转矩阵
//		double angle = getRotateAngle(); // 旋转角度
//		double scale = 1.0;  // 缩放比例
//		Mat rot = getRotationMatrix2D(center, angle, scale);
//
//		// 计算新图像的边界
//		Rect2f bbox = RotatedRect(Point2f(), src.size(), (float)angle).boundingRect2f();
//
//		// 调整旋转矩阵以考虑平移
//		rot.at<double>(0, 2) += bbox.width / 2.0 - src.cols / 2.0;
//		rot.at<double>(1, 2) += bbox.height / 2.0 - src.rows / 2.0;
//
//		// 应用仿射变换
//		Mat dst;
//		warpAffine(src, dst, rot, bbox.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(255, 255, 255));
//
//		// 显示图像
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
