
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
	erode(img, eroderesult, sample);//ͼ��ʴ
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
	//ͼ��ģ��
	blur(img, blurresult, Size(3, 3));
	imshow("blurresult", blurresult);
	waitKey(0);
}
void test_functions::methods::Test_canny(const std::string& filepath)
{
	Mat img = imread(filepath);

	imshow("picture", img);
	
	//��Ե���  �Ҷ�ͼ�����룬canny��Ե���
	Mat grayimg;
	cvtColor(img, grayimg, COLOR_BGR2GRAY);//�Ҷ�

	Mat edge;
	blur(grayimg, edge, Size(3, 3));//����

	Canny(edge, edge, 3, 9, 3);//Ѱ��

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
	erode(img, eroderesult, sample);//ͼ��ʴ
	return eroderesult;
}
cv::Mat  test_functions::methods::Test_blur(const Mat& img)
{
	//imshow("picture", img);
	Mat sample = getStructuringElement(MORPH_RECT, Size(30, 30));
	imshow("select picture", sample);


	Mat blurresult;
	//ͼ��ģ��
	blur(img, blurresult, Size(3, 3));
	return blurresult;
}
cv::Mat  test_functions::methods::Test_canny(const Mat& img)
{
	//imshow("picture", img);

	//��Ե���  �Ҷ�ͼ�����룬canny��Ե���
	Mat grayimg;
	cvtColor(img, grayimg, COLOR_BGR2GRAY);//�Ҷ�

	Mat edge;
	blur(grayimg, edge, Size(3, 3));//����

	Canny(edge, edge, 3, 9, 3);//Ѱ��

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
	//����ͷ������Ƶ
	VideoCapture capture(id);
	while (1)
	{
		Mat frame;
		capture >> frame;
		Mat grayimg;
		cvtColor(frame, grayimg, COLOR_BGR2GRAY);//�Ҷ�
		//Mat result = ;
		imshow("��ȡ��Ƶ", (*pi)(grayimg));
		waitKey(wait);//��ʱ30ms
	}
}