//#include<opencv2/imgcodecs.hpp>
//#include<opencv2/highgui.hpp>
//#include<opencv2/imgproc.hpp>
//#include<bits/stdc++.h>
//
//int main() {
//    // ��ȡͼƬ
//    cv::Mat img = cv::imread("Resources/Resources/testforHSV.png");
//    if (img.empty()) {
//        std::cout << "Image load failed!" << std::endl;
//        return -1;
//    }
//
//    // ת����HSVɫ�ʿռ�
//    cv::Mat hsv;
//    cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);
//
//    // ������ɫ��HSV��Χ
//    cv::Scalar lower_blue(0, 0, 146);
//    cv::Scalar upper_blue(255, 36, 255);
//
//    // ������ģ
//    cv::Mat mask;
//    cv::inRange(hsv, lower_blue, upper_blue, mask);
//
//    // ��ת��ģ
//    cv::Mat mask_inv;
//    cv::bitwise_not(mask, mask_inv);
//
//    // ����������ʾ��ͼƬ
//    cv::Mat result = img.clone(); // ����ԭͼ�����ͼ
//    result.setTo(cv::Scalar(255, 255, 255), mask); // ����ģ��������Ϊ��ɫ
//
//    // ��ʾ�ͱ�����
//    cv::imshow("Original", img);
//    cv::imshow("Mask", mask);
//    cv::imshow("Mask Inverted", mask_inv);
//    cv::imshow("Result", result);
//    cv::waitKey(0); // �ȴ�����
//
//    cv::imwrite("result.jpg", result);
//
//    return 0;
//}
