
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
	erode(img, eroderesult, sample);//Í¼Ïñ¸¯Ê´
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
	//Í¼ÏñÄ£ºý
	blur(img, blurresult, Size(3, 3));
	imshow("blurresult", blurresult);
	waitKey(0);
}
void test_functions::Test_canny(const std::string& filepath)
{
	Mat img = imread(filepath);

	imshow("picture", img);
	
	//±ßÔµ¼ì²â  »Ò¶ÈÍ¼£¬½µÔë£¬canny±ßÔµ¼ì²â
	Mat grayimg;
	cvtColor(img, grayimg, COLOR_BGR2GRAY);//»Ò¶È

	Mat edge;
	blur(grayimg, edge, Size(3, 3));//½µÔë

	Canny(edge, edge, 3, 9, 3);//Ñ°±ß

	imshow("edge", edge);

	waitKey(0);
}