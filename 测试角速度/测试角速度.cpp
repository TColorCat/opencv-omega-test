// 测试角速度.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<ctime>
#include<string>
//#include<cv.h>
#include<opencv.hpp>
#include<imgproc\imgproc.hpp>
#include<highgui\highgui.hpp>
#include"Test_function.h"
#include"camera_param.h"
using namespace std;
using namespace cv;
using namespace test_functions;
int _tmain(int argc, _TCHAR* argv[])
{
	//clock_t start, finish;
	//start = clock();
	//test_functions::Test_blur("F://2.jpg");
	//test_functions::Test_using_selfcamera(0);
	//test_functions::Test_harris("F://2.jpg");

	//test_functions::Test_using_selfcamera(0, test_functions::methods::Test_harris, 10);

	camera_param::test_example::test_cal_img_cornerPoint("E://Opencv30//opencv//sources//samples//data//left01.jpg", "E://Opencv30//master pieces//single");
	
	
	//finish = clock();
	//cout << "using time" << finish - start << " ms" << endl;
	return 0;
}

