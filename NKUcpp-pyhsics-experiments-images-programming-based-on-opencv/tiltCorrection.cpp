//#include <iostream>
//#include"opencv2/opencv.hpp"
//using namespace std;
//using namespace cv;
//
//
//bool cmp_x(cv::Point pt1, cv::Point pt2)
//{
//	return (pt1.x < pt2.x);
//}
//
//cv::Point2f get_mid_pt(cv::Point2f pt1, cv::Point2f pt2)
//{
//	return cv::Point2f((pt1.x + pt2.x) / 2.0, (pt1.y + pt2.y) / 2.0);
//}
//
//double get_point_angle(cv::Point2f pointO, cv::Point2f pointA)
//{
//	double angle = 0;
//	cv::Point2f point;
//	double temp;
//	point = cv::Point2f((pointA.x - pointO.x), (pointA.y - pointO.y));
//
//	if ((0 == point.x) && (0 == point.y))
//	{
//		return 0;
//	}
//
//	if (0 == point.x)
//	{
//		angle = 90;
//		return angle;
//	}
//
//	if (0 == point.y)
//	{
//		angle = 0;
//		return angle;
//	}
//
//	temp = fabsf(float(point.y) / float(point.x));
//	temp = atan(temp);
//	temp = temp * 180 / CV_PI;
//
//	if ((0 < point.x) && (0 < point.y))
//	{
//		angle = 360 - temp;
//		return angle;
//	}
//
//	if ((0 > point.x) && (0 < point.y))
//	{
//		angle = 360 - (180 - temp);
//		return angle;
//	}
//
//	if ((0 < point.x) && (0 > point.y))
//	{
//		angle = temp;
//		return angle;
//	}
//
//	if ((0 > point.x) && (0 > point.y))
//	{
//		angle = 180 - temp;
//		return angle;
//	}
//
//	printf("sceneDrawing :: getAngle error!");
//	return -1;
//}
//
//int RotateImage(const cv::Mat& src, double angle, cv::Mat& dst, cv::Mat& rot_matrix, bool crop = true, int flags = cv::INTER_NEAREST,
//	int borderMode = cv::BORDER_CONSTANT, const cv::Scalar& borderValue = cv::Scalar())
//{
//	if (0 == src.cols * src.rows) { return 0; }
//	cv::Point2f center(src.cols / 2.0f, src.rows / 2.0f);
//	rot_matrix = cv::getRotationMatrix2D(center, angle, 1.0);
//	if (crop) {
//		if (dst.data == NULL) {
//			dst = cv::Mat(src.rows, src.cols, src.type());
//		}
//	}
//	else {
//		cv::Rect bbox = cv::RotatedRect(center, cv::Size2f(src.cols, src.rows), angle).boundingRect();
//		double* p = (double*)rot_matrix.data;
//		p[2] += bbox.width / 2.0 - center.x;
//		p[5] += bbox.height / 2.0 - center.y;
//		if (dst.rows != bbox.height || dst.cols != bbox.width) {
//			dst = cv::Mat(bbox.height, bbox.width, src.type());
//		}
//	}
//	cv::warpAffine(src, dst, rot_matrix, dst.size(), flags, borderMode, borderValue);
//	return 0;
//}
//
//
//int main(int argc, char* argv[])
//{
//	cv::Mat img = cv::imread("Resources/Resources/result1.jpg");
//
//	cv::Mat m_gray, m_bi;
//	cv::cvtColor(img, m_gray, COLOR_BGR2GRAY);
//	cv::threshold(m_gray, m_bi, 100, 255, THRESH_BINARY_INV);
//
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierarchy;
//	findContours(m_bi, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());
//
//	RotatedRect rt_rot_max, rt_tmp;
//	int max_szie = -1;
//	for (int i = 0; i < contours.size(); i++)
//	{
//		rt_tmp = minAreaRect(Mat(contours[i]));
//		if (rt_tmp.size.area() > max_szie)
//		{
//			max_szie = rt_tmp.size.area();
//			rt_rot_max = rt_tmp;
//		}
//	}
//	std::vector<cv::Point2f> v_pt(4);
//	rt_rot_max.points(v_pt.data());
//
//	std::sort(v_pt.begin(), v_pt.end(), cmp_x);
//
//	cv::Point2f pt_left = get_mid_pt(v_pt[0], v_pt[1]);
//	cv::Point2f pt_right = get_mid_pt(v_pt[2], v_pt[3]);
//
//	double ang = get_point_angle(pt_left, pt_right);
//	std::cout << "ang=" << ang << std::endl;
//
//	cv::circle(img, v_pt[0], 6, Scalar(50, 12, 189), 3);
//	cv::circle(img, v_pt[1], 6, Scalar(10, 255, 255), 3);
//	cv::circle(img, v_pt[2], 6, Scalar(150, 120, 19), 3);
//	cv::circle(img, v_pt[3], 6, Scalar(0, 0, 0), 3);
//
//	cv::Mat m_rot, rot_matrix;
//	RotateImage(img, -ang, m_rot, rot_matrix, false);
//
//	/*cv::imshow("m_rot", m_rot);
//	cv::imshow("m_bi", m_bi);
//	cv::imshow("m_gray", m_gray);
//	cv::imshow("img", img);*/
//	cv::Mat mask;
//	cv::cvtColor(m_rot, mask, cv::COLOR_BGR2GRAY); // 转换为灰度图像
//	cv::threshold(mask, mask, 1, 255, cv::THRESH_BINARY); // 将非黑色像素设置为255
//	cv::bitwise_not(mask, mask); // 取反，黑色变为白色
//
//	cv::Mat result;
//	m_rot.copyTo(result, mask); // 仅保留黑色像素
//	imshow("m_rot", m_rot);
//	//imwrite("result_corr3.jpg", m_rot);
//	cv::waitKey(0);
//
//	return 0;
//}
