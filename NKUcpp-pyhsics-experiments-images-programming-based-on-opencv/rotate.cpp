//#include <opencv2/opencv.hpp>
//
//int main() {
//    // ��ȡͼ��
//    cv::Mat src = cv::imread("Resources/Resources/result1.jpg");
//    if (src.empty()) {
//        std::cout << "Could not open or find the image!" << std::endl;
//        return -1;
//    }
//
//    // ������ת���ģ�����������ѡ��ͼ�������
//    cv::Point2f center(src.cols / 2.0F, src.rows / 2.0F);
//
//    // ��ȡ��ת����
//    double angle = -12.838; // ��ת�Ƕ�
//    double scale = 1.0;  // ���ű���
//    cv::Mat rot = cv::getRotationMatrix2D(center, angle, scale);
//
//    // ������ͼ��ı߽�
//    cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), src.size(), (float)angle).boundingRect2f();
//
//    // ������ת�����Կ���ƽ��
//    rot.at<double>(0, 2) += bbox.width / 2.0 - src.cols / 2.0;
//    rot.at<double>(1, 2) += bbox.height / 2.0 - src.rows / 2.0;
//
//    // Ӧ�÷���任
//    cv::Mat dst;
//    cv::warpAffine(src, dst, rot, bbox.size(), cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(255, 255, 255));
//
//    // ��ʾͼ��
//    cv::imshow("Rotated Image", dst);
//    cv::waitKey(0);
//
//    return 0;
//}
