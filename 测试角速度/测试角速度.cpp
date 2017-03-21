// 测试角速度.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>  
#include "opencv2/core/core.hpp"  
#include "opencv2/features2d/features2d.hpp"  
#include "opencv2/highgui/highgui.hpp"   
#include "opencv2/legacy/legacy.hpp"   
#include <vector>  
#include"Test_function.h"
#include"ORB_application.h"
using namespace cv;
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	//test_functions::methods::ORB_test();

	Mat img_1 = imread("book-1.bmp");
	Mat img_2 = imread("book-reference.bmp");

	ORB_application::ORB_two_pictures(img_1, img_2);

	return 0;
}

