#include"imageClass.h"

int main()
{
	Image img("Resources/Resources/ph7.jpg");
	img.showImage();
	img.rotate();
	waitKey(1);
	std::string order;
	while (true)
	{
		std::cout << "ͼ���Ƿ���Ҫ�������ɣ�[Y]/[N]" << std::endl;
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
			std::cout << "ָ�����" << std::endl;
		}
	}
	return 0;
}