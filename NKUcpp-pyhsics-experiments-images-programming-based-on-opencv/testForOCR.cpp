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
//    // ����ͼƬ
//    cv::Mat image = cv::imread("Resources/Resources/testforOCR2.png");
//
//    // ���ͼ���Ƿ�ɹ�����
//    if (image.empty()) {
//        std::cerr << "Error: Unable to load image." << std::endl;
//        return -1;
//    }
//
//    // ��ͼ��ת��Ϊ�Ҷ�ͼ��
//    cv::Mat grayImage;
//    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
//
//    // ��ʼ��Tesseract OCR
//    tesseract::TessBaseAPI ocr;
//    ocr.Init(NULL, "eng"); // ָ������ΪӢ�����Ը�����Ҫ�������Դ���
//
//    // ����ͼ������
//    ocr.SetImage(grayImage.data, grayImage.cols, grayImage.rows, 1, grayImage.cols);
//
//    // ��������ʶ��
//    ocr.Recognize(0);
//
//    // ��ȡʶ����
//    std::string text = ocr.GetUTF8Text();
//    string textOut;
//    const char* cstr = text.c_str();
//    UTF8_to_GB2312(cstr, textOut);
//    std::cout << "Detected Text: " << textOut << std::endl;
//    
//    // ��ʾ���
//    cv::imshow("Text Detection Result", image);
//    cv::waitKey(0);
//
//    // �ͷ���Դ
//    ocr.End();
//    return 0;
//}
