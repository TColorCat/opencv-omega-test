
#include"stdafx.h"
#include"Test_function.h"

//#include<cv.h>
#include<opencv.hpp>
#include<imgproc\imgproc.hpp>
#include<highgui\highgui.hpp>

using namespace cv;

void test_functions::methods::Test_erobe(const std::string& filepath)
{
	Mat img = imread(filepath);

	imshow("picture", img);
	Mat sample = getStructuringElement(MORPH_RECT, Size(30, 30));
	imshow("select picture", sample);

	Mat eroderesult;
	erode(img, eroderesult, sample);//ÕºœÒ∏Ø ¥
	imshow("result", eroderesult);
	waitKey(0);
}

void test_functions::methods::Test_blur(const std::string& filepath)
{
	Mat img = imread(filepath);

	imshow("picture", img);
	Mat sample = getStructuringElement(MORPH_RECT, Size(30, 30));
	imshow("select picture", sample);

	
	Mat blurresult;
	//ÕºœÒƒ£∫˝
	blur(img, blurresult, Size(3, 3));
	imshow("blurresult", blurresult);
	waitKey(0);
}
void test_functions::methods::Test_canny(const std::string& filepath)
{
	Mat img = imread(filepath);

	imshow("picture", img);
	
	//±ﬂ‘µºÏ≤‚  ª“∂»Õº£¨Ωµ‘Î£¨canny±ﬂ‘µºÏ≤‚
	Mat grayimg;
	cvtColor(img, grayimg, COLOR_BGR2GRAY);//ª“∂»

	Mat edge;
	blur(grayimg, edge, Size(3, 3));//Ωµ‘Î

	Canny(edge, edge, 3, 9, 3);//—∞±ﬂ

	imshow("edge", edge);

	waitKey(0);
}

void test_functions::methods::Test_harris(const std::string&filepath)
{
	Mat srcimg = imread(filepath, 0);
	imshow("origin", srcimg);
	Mat cornerStrength;
	cornerHarris(srcimg, cornerStrength, 2, 3, 0.01);
	Mat harriscorner;

	threshold(cornerStrength, harriscorner, 0.00001, 255, THRESH_BINARY);

	imshow("final", harriscorner);
	waitKey(0);
	
}

/*overload input mat*/
cv::Mat test_functions::methods::Test_erobe(const Mat& img)//input Mat
{
	//imshow("picture", img);
	Mat sample = getStructuringElement(MORPH_RECT, Size(30, 30));
	imshow("select picture", sample);

	Mat eroderesult;
	erode(img, eroderesult, sample);//ÕºœÒ∏Ø ¥
	return eroderesult;
}
cv::Mat  test_functions::methods::Test_blur(const Mat& img)
{
	//imshow("picture", img);
	Mat sample = getStructuringElement(MORPH_RECT, Size(30, 30));
	imshow("select picture", sample);


	Mat blurresult;
	//ÕºœÒƒ£∫˝
	blur(img, blurresult, Size(3, 3));
	return blurresult;
}
cv::Mat  test_functions::methods::Test_canny(const Mat& img)
{
	//imshow("picture", img);

	//±ﬂ‘µºÏ≤‚  ª“∂»Õº£¨Ωµ‘Î£¨canny±ﬂ‘µºÏ≤‚
	Mat grayimg;
	cvtColor(img, grayimg, COLOR_BGR2GRAY);//ª“∂»

	Mat edge;
	blur(grayimg, edge, Size(3, 3));//Ωµ‘Î

	Canny(edge, edge, 3, 9, 3);//—∞±ﬂ

	return edge;
}
cv::Mat  test_functions::methods::Test_harris(const Mat&srcimg)
{
	//imshow("origin", srcimg);
	Mat cornerStrength;
	cornerHarris(srcimg, cornerStrength, 2, 3, 0.01);
	Mat harriscorner;

	threshold(cornerStrength, harriscorner, 0.00001, 255, THRESH_BINARY);

	return harriscorner;
	
}
/*

@Attention: captured camera on self-computer img is RGB-type.
it is recommanded to match the img-type between input-camera and methods needed img-type
@param id is the opened video capturing device (i.e. a camera index).
If there is a single camera connected, just pass 0.
@param Mat(*pi)(const cv::Mat&) is a function pointer to get img processing methods
@param int wait is a parameter for waitKey() in each frame process;
*/
void test_functions::Test_using_selfcamera(const int&id,cv::Mat(*pi)(const cv::Mat&),int wait)
{
	//…„œÒÕ∑∂¡»Î ”∆µ
	VideoCapture capture(id);
	while (1)
	{
		Mat frame;
		capture >> frame;
		Mat grayimg;
		cvtColor(frame, grayimg, COLOR_BGR2GRAY);//ª“∂»
		//Mat result = ;
		imshow("∂¡»° ”∆µ", (*pi)(grayimg));
		waitKey(wait);//—” ±30ms
	}
}