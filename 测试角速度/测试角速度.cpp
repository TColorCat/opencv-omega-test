// ���Խ��ٶ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<cv.h>
#include<opencv.hpp>
#include<imgproc\imgproc.hpp>
#include<highgui\highgui.hpp>
#include"Test_function.h"
using namespace std;
using namespace cv;
int _tmain(int argc, _TCHAR* argv[])
{
	test_functions::Test_blur("F://2.jpg");
	
	return 0;
}

