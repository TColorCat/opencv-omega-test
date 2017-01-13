// ���Խ��ٶ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<cv.h>
#include<opencv.hpp>
#include<imgproc\imgproc.hpp>
#include<highgui\highgui.hpp>
using namespace std;
using namespace cv;
int _tmain(int argc, _TCHAR* argv[])
{
	Mat img = imread("F://2.jpg");

	imshow("picture", img);
	Mat sample = getStructuringElement(MORPH_RECT, Size(30, 30));
	imshow("select picture", sample);

	Mat eroderesult;
	erode(img, eroderesult, sample);//ͼ��ʴ
	imshow("result", eroderesult);
	Mat blurresult;
	//ͼ��ģ��
	blur(img, blurresult, Size(3, 3));
	imshow("blurresult", blurresult);

	//��Ե���  �Ҷ�ͼ�����룬canny��Ե���
	Mat grayimg;
	cvtColor(img, grayimg, COLOR_BGR2GRAY);//�Ҷ�

	Mat edge;
	blur(grayimg, edge, Size(3, 3));//����

	Canny(edge, edge, 3, 9, 3);//Ѱ��

	imshow("edge", edge);

	waitKey(0);
	return 0;
	return 0;
}

