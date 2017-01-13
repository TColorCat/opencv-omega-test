
#include"stdafx.h"
#include"Test_function.h"

#include<cv.h>
#include<opencv.hpp>
#include<imgproc\imgproc.hpp>
#include<highgui\highgui.hpp>

using namespace cv;
void test_functions::Test_erobe(const std::string& filepath)
{
	Mat img = imread(filepath);

	imshow("picture", img);
	Mat sample = getStructuringElement(MORPH_RECT, Size(30, 30));
	imshow("select picture", sample);

	Mat eroderesult;
	erode(img, eroderesult, sample);//ͼ��ʴ
	imshow("result", eroderesult);
	waitKey(0);
}

void test_functions::Test_blur(const std::string& filepath)
{
	Mat img = imread(filepath);

	imshow("picture", img);
	Mat sample = getStructuringElement(MORPH_RECT, Size(30, 30));
	imshow("select picture", sample);

	
	Mat blurresult;
	//ͼ��ģ��
	blur(img, blurresult, Size(3, 3));
	imshow("blurresult", blurresult);
	waitKey(0);
}
void test_functions::Test_canny(const std::string& filepath)
{
	Mat img = imread(filepath);

	imshow("picture", img);
	
	//��Ե���  �Ҷ�ͼ�����룬canny��Ե���
	Mat grayimg;
	cvtColor(img, grayimg, COLOR_BGR2GRAY);//�Ҷ�

	Mat edge;
	blur(grayimg, edge, Size(3, 3));//����

	Canny(edge, edge, 3, 9, 3);//Ѱ��

	imshow("edge", edge);

	waitKey(0);
}

//template<typename T>
/*@param device id of the opened video capturing device (i.e. a camera index). If there is a single
    camera connected, just pass 0.
*/
void test_functions::Test_using_selfcamera(const int&in)
{
	//����ͷ������Ƶ
	VideoCapture capture(in);
	while (1)
	{
		Mat frame;
		capture >> frame;
		imshow("��ȡ��Ƶ", frame);
		waitKey(30);//��ʱ30ms
	}
}