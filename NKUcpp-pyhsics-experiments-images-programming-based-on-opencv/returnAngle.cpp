//#include <iostream>
//#include <vector>
//#include <opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//
//
//bool cmp_x(Point pt1, Point pt2)
//{
//	// 比较函数，用于排序
//    return pt1.x < pt2.x;
//}
//Point2f get_mid_pt(Point2f pt1, Point2f pt2) 
//{
//	// 获取两点的中点
//    return Point2f((pt1.x + pt2.x) / 2.0, (pt1.y + pt2.y) / 2.0);
//}
//double get_point_angle(cv::Point2f pointO, cv::Point2f pointA)
//{
//	//获取点的角度
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
//double rotateAndReturnAngle(const string& imagePath) {
//    Mat img = imread(imagePath);
//    if (img.empty()) {
//        cerr << "Image not found" << endl;
//        return 0.0;
//    }
//
//    Mat m_gray, m_bi;
//    cvtColor(img, m_gray, COLOR_BGR2GRAY);
//    threshold(m_gray, m_bi, 100, 255, THRESH_BINARY_INV);
//
//    vector<vector<Point>> contours;
//    vector<Vec4i> hierarchy;
//    findContours(m_bi, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());
//
//    RotatedRect rt_rot_max, rt_tmp;
//    int max_size = -1;
//    for (int i = 0; i < contours.size(); i++) {
//        rt_tmp = minAreaRect(Mat(contours[i]));
//        if (rt_tmp.size.area() > max_size) {
//            max_size = rt_tmp.size.area();
//            rt_rot_max = rt_tmp;
//        }
//    }
//    vector<Point2f> v_pt(4);
//    rt_rot_max.points(v_pt.data());
//
//    sort(v_pt.begin(), v_pt.end(), cmp_x);
//
//    Point2f pt_left = get_mid_pt(v_pt[0], v_pt[1]);
//    Point2f pt_right = get_mid_pt(v_pt[2], v_pt[3]);
//
//    double ang = get_point_angle(pt_left, pt_right);
//    cout << "ang=" << ang << endl;
//
//    // 这里可以添加代码来显示或保存处理后的图像，如果需要的话
//
//    return ang; // 返回旋转角度
//}
//
//int main() {
//    string imagePath = "Resources/Resources/result1.jpg"; // 这里替换为你的图像路径
//    double rotationAngle = rotateAndReturnAngle(imagePath);
//    cout << "The image was rotated by: " << rotationAngle << " degrees" << endl;
//
//    // 其他代码...
//
//    return 0;
//}