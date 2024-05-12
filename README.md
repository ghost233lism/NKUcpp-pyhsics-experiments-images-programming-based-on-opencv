# NKUcpp-pyhsics-experiments-images-programming-based-on-opencv
## NKU-Experimenter 你的物理实验报告拯救者，现已加入物理实验拯救计划全家桶[doge]
## 本仓库为南开大学C++2024大作业代码仓库
## 声明：本项目100%独立自主完成，创意100%原创，没有任何参考项目和模仿项目！！！看在独立创意和解决大物实验报告问题的份上，给一颗star吧，送人star，手有余香，求求啦
---
## 注意
众所周知，在使用第三方库的情况下，没有配置环境是不能直接运行源代码的，如果想运行源代码的话，需要配置第三方库。另外一种简单的直接使用桌面程序的方法就是利用vs2022的release功能，配置好相应的dll文件，就可以直接使用，本人尝试realease了文件，但是目前测试还未成功，如果感兴趣，可以点击右侧的release下载测试，如果能成功运行那就太棒啦！
如果你想build from source code，那么请你仔细阅读该文档最后的环境配置教程，本项目使用了QT、opencv库和Tesseract库，其中tesseract库的配置十分困难，国内的blog提到的方法均以失效，只能按照官方文档中的配置方法进行配置。
## Motivation
在完成物理实验报告时，往往需要加入物理实验原理图，通常有两个办法：

1、使用word图形插入绘制

2、拍照或扫描物理实验书上的实验原理图并粘贴到实验报告文件中。

然而，这两种方法都面临问题。

第一种方法十分麻烦，word绘图调整绘图元素之间的位置十分不便，而且，有些物理元素不适宜使用word绘制。

第二种方法同样面临着问题，一方面是直接拍照容易造成原理图扭曲，并且因为物理教材背景色不是白色，直接粘贴会显得十分突兀。另一方面，即使使用扫描功能，也无法避免图片扭曲的问题，使用手机自带的文档抓取功能并不能很好地识别原理图（往往会把文字部分包含进来）。并且，使用扫描功能会丢失原理图色彩信息。

因此，我开发了本项目希望实现物理实验图像的识别、切割、处理、导出集一体的一站式操作。
## 实现功能
1、对输入的图片进行处理，实现自动矫正、扭转

2、自动提取图片中的物理原理图信息，并将其切割下来

3、对物理原理图中的关键元素进行加强

4、将物理原理图的背景换成白色或透明并导出。
## 工具（语言）需求
1、C++

2、OpenCv库

3、TesseractOCR库 用于文字检测和定位

4、Qt Tool

## 实现思路
1、利用opencv库对图片进行处理，变化为HSV图像。

2、进行边缘检测

3、提取关键（感兴趣）区域，用长方形框选

4、处理框选出的图像，生成旋转矩阵（角度）

6、擦除文字

7、更换背景

8、输出图像

9、图形化界面开发


## to do list
- [ √] 设计类的结构
- [ √ ] 实现边缘检测
- [  √] 实现图片提取
- [  √] 设计图形化界面（可选）

## How to build
### 下载QT（已经下载并配置vs可以跳过）
https://www.qt.io/cs/c/?cta_guid=074ddad0-fdef-4e53-8aa8-5e8a876d6ab4&signature=AAH58kH0egoaNdhWUkb3CrMH5KBkxAFAfg&utm_referrer=https%3A%2F%2Fwww.qt.io%2Fdownload&portal_id=149513&pageId=12602948080&placement_guid=99d9dd4f-5681-48d2-b096-470725510d34&click=f34c55ec-9f2b-4b50-976e-f0f8c1bfb6b5&redirect_url=APefjpGBiX0UKTIp6IKtiCZ_FHyffB4SznUymVuFkbA7PJudjDP-LiROcddjXL6Z3cuRp8XZgXFoq1NutMCf1VURrhBJn-YU4hV6ePQgE2wFsyY2KeST8hBnUN-lRDcNZLw3w7T2y9G_5Uibtr25F8P-NQXQbV1hQ6xtbfVTgRn5yaBqx6BYIX8KbIvskrCYGUBLY1LnTcvgiibot5YJuEYf_W3PlZBgHCIKZfNmMYtbFvgLKmHHliE8BjNT7oUH-GOgillhZB2NQRbL3v4viOYWd5F6NcUtAQ&hsutk=197f600d7cf052bbf3ee41923cc41e7f&canon=https%3A%2F%2Fwww.qt.io%2Fdownload-open-source 

下载opensourceuser版QT tool

按照提示开始安装