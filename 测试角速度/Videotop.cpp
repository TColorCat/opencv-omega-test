#include "stdafx.h"
#include"video_to_pictures.h"

#include<opencv.hpp>
#include<imgproc\imgproc.hpp>
#include<highgui\highgui.hpp>
using namespace cv;
void toPicture::VedioTo::videotoP( cv::VideoCapture& capture, const std::string& outfolder)
{
	int count = 0;
//	VideoCapture capture(id);
	while (capture.grab())
	{
		Mat frame;
		capture >> frame;
		Mat grayimg;
		cv::cvtColor(frame, grayimg, cv::COLOR_BGR2GRAY);//»Ò¶È
		

		 imwrite(outfolder + std::to_string(count) + "P.jpg", grayimg);
		count++;
	}
}