// 测试角速度.cpp : 定义控制台应用程序的入口点。
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

