// 测试角速度.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<ctime>
//#include<cv.h>
#include<opencv.hpp>
#include<imgproc\imgproc.hpp>
#include<highgui\highgui.hpp>
#include"Test_function.h"
using namespace std;
using namespace cv;
int _tmain(int argc, _TCHAR* argv[])
{
	//clock_t start, finish;
	//start = clock();
	//test_functions::Test_blur("F://2.jpg");
	//test_functions::Test_using_selfcamera(0);
	//test_functions::Test_harris("F://2.jpg");

	test_functions::Test_using_selfcamera(0, test_functions::Test_harris, 10);

	
	//finish = clock();
	//cout << "using time" << finish - start << " ms" << endl;
	return 0;
}

