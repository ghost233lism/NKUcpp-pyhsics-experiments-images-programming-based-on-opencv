//#include<opencv2/imgcodecs.hpp>
//#include<opencv2/highgui.hpp>
//#include<opencv2/imgproc.hpp>
//#include<bits/stdc++.h>
//
//int main() {
//    // 读取图片
//    cv::Mat img = cv::imread("Resources/Resources/testforHSV.png");
//    if (img.empty()) {
//        std::cout << "Image load failed!" << std::endl;
//        return -1;
//    }
//
//    // 转换到HSV色彩空间
//    cv::Mat hsv;
//    cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);
//
//    // 定义蓝色的HSV范围
//    cv::Scalar lower_blue(0, 0, 146);
//    cv::Scalar upper_blue(255, 36, 255);
//
//    // 创建掩模
//    cv::Mat mask;
//    cv::inRange(hsv, lower_blue, upper_blue, mask);
//
//    // 反转掩模
//    cv::Mat mask_inv;
//    cv::bitwise_not(mask, mask_inv);
//
//    // 创建最终显示的图片
//    cv::Mat result = img.clone(); // 复制原图到结果图
//    result.setTo(cv::Scalar(255, 255, 255), mask); // 在掩模区域设置为白色
//
//    // 显示和保存结果
//    cv::imshow("Original", img);
//    cv::imshow("Mask", mask);
//    cv::imshow("Mask Inverted", mask_inv);
//    cv::imshow("Result", result);
//    cv::waitKey(0); // 等待按键
//
//    cv::imwrite("result.jpg", result);
//
//    return 0;
//}
