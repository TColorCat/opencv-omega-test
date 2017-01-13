// 测试角速度.cpp : 定义控制台应用程序的入口点。
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
	erode(img, eroderesult, sample);//图像腐蚀
	imshow("result", eroderesult);
	Mat blurresult;
	//图像模糊
	blur(img, blurresult, Size(3, 3));
	imshow("blurresult", blurresult);

	//边缘检测  灰度图，降噪，canny边缘检测
	Mat grayimg;
	cvtColor(img, grayimg, COLOR_BGR2GRAY);//灰度

	Mat edge;
	blur(grayimg, edge, Size(3, 3));//降噪

	Canny(edge, edge, 3, 9, 3);//寻边

	imshow("edge", edge);

	waitKey(0);
	return 0;
	return 0;
}

