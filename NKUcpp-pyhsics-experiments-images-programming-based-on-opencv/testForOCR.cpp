//#include <opencv2/opencv.hpp>
//#include <tesseract/baseapi.h>
//#include <leptonica/allheaders.h>
//#include <iostream>
//#include <Windows.h>
//
//using namespace std;
////using std::string;
//void UTF8_to_GB2312(const char* utf8, string& gb2312_str)
//{
//    int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
//    wchar_t* wstr = new wchar_t[len + 1];
//    memset(wstr, 0, len + 1);
//    MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
//    len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
//    char* str = new char[len + 1];
//    memset(str, 0, len + 1);
//    WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
//    delete[] wstr;
//    gb2312_str = str;
//    delete[] str;
//    return;
//}
//int main() {
//    // 加载图片
//    cv::Mat image = cv::imread("Resources/Resources/testforOCR2.png");
//
//    // 检查图像是否成功加载
//    if (image.empty()) {
//        std::cerr << "Error: Unable to load image." << std::endl;
//        return -1;
//    }
//
//    // 将图像转换为灰度图像
//    cv::Mat grayImage;
//    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
//
//    // 初始化Tesseract OCR
//    tesseract::TessBaseAPI ocr;
//    ocr.Init(NULL, "eng"); // 指定语言为英语，你可以根据需要更改语言代码
//
//    // 设置图像数据
//    ocr.SetImage(grayImage.data, grayImage.cols, grayImage.rows, 1, grayImage.cols);
//
//    // 进行文字识别
//    ocr.Recognize(0);
//
//    // 获取识别结果
//    std::string text = ocr.GetUTF8Text();
//    string textOut;
//    const char* cstr = text.c_str();
//    UTF8_to_GB2312(cstr, textOut);
//    std::cout << "Detected Text: " << textOut << std::endl;
//    
//    // 显示结果
//    cv::imshow("Text Detection Result", image);
//    cv::waitKey(0);
//
//    // 释放资源
//    ocr.End();
//    return 0;
//}
