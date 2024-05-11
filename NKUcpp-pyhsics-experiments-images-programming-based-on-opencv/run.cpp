#include"imageClass.h"

int main()
{
	Image img("Resources/Resources/ph10.jpg");
	img.showImage();
	img.rotate();
	waitKey(1);
	std::string order;
	while (true)
	{
		std::cout << "图像是否需要重新生成？[Y]/[N]" << std::endl;
		std::cin >> order;
		if (order == "Y")
		{
			double angle = img.getRotateAngle(img.getImgAfterRotate());
			img.rotate(angle);
			waitKey(1);
		}
		else if (order == "N")
		{
			img.eraseText();
			img.showOutputImage();
			waitKey(0);
			break;
		}
		else
		{
			std::cout << "指令错误" << std::endl;
		}
	}
	return 0;
}