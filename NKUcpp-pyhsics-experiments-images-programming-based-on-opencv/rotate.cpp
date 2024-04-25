//#include <opencv2/opencv.hpp>
//
//int main() {
//    // 读取图像
//    cv::Mat src = cv::imread("Resources/Resources/result1.jpg");
//    if (src.empty()) {
//        std::cout << "Could not open or find the image!" << std::endl;
//        return -1;
//    }
//
//    // 设置旋转中心；在这里我们选择图像的中心
//    cv::Point2f center(src.cols / 2.0F, src.rows / 2.0F);
//
//    // 获取旋转矩阵
//    double angle = -12.838; // 旋转角度
//    double scale = 1.0;  // 缩放比例
//    cv::Mat rot = cv::getRotationMatrix2D(center, angle, scale);
//
//    // 计算新图像的边界
//    cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), src.size(), (float)angle).boundingRect2f();
//
//    // 调整旋转矩阵以考虑平移
//    rot.at<double>(0, 2) += bbox.width / 2.0 - src.cols / 2.0;
//    rot.at<double>(1, 2) += bbox.height / 2.0 - src.rows / 2.0;
//
//    // 应用仿射变换
//    cv::Mat dst;
//    cv::warpAffine(src, dst, rot, bbox.size(), cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(255, 255, 255));
//
//    // 显示图像
//    cv::imshow("Rotated Image", dst);
//    cv::waitKey(0);
//
//    return 0;
//}
