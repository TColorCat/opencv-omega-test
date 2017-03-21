
#include"stdafx.h"
#include"Test_function.h"

//#include<cv.h>
#include<opencv.hpp>
#include<imgproc\imgproc.hpp>


#include <iostream>  
#include "opencv2/core/core.hpp"  
#include "opencv2/features2d/features2d.hpp"  
#include "opencv2/highgui/highgui.hpp"   
#include "opencv2/legacy/legacy.hpp"   
#include <vector>  

using namespace std;
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


int test_functions::methods::ORB_test()
{
	Mat img_1 = imread("book-1.bmp");
	Mat img_2 = imread("book-reference.bmp");
	if (!img_1.data || !img_2.data)
	{
		cout << "error reading images " << endl;
		return -1;
	}

	//1.orbºÏ≤‚Ãÿ’˜µ„≤¢Ã·»°Ãÿ’˜÷µ
	ORB orb;
	vector<KeyPoint> keyPoints_1, keyPoints_2;
	Mat descriptors_1, descriptors_2;
	orb(img_1, Mat(), keyPoints_1, descriptors_1);
	orb(img_2, Mat(), keyPoints_2, descriptors_2);
	

	imshow("img1", descriptors_1);
	imshow("img2", descriptors_2);

	//2.BruteForceMatcher∆•≈‰
	BruteForceMatcher<HammingLUT> matcher;  //“≤ø…“‘ π”√ruteForce<Hamming>
	vector<DMatch> matches;
	matcher.match(descriptors_1, descriptors_2, matches);

	//3.π˝¬À∆•≈‰µ„
	double max_dist = 0; double min_dist = 100;
	//-- Quick calculation of max and min distances between keypoints
	for (int i = 0; i < descriptors_1.rows; i++)
	{
		double dist = matches[i].distance;
		if (dist < min_dist) min_dist = dist;
		if (dist > max_dist) max_dist = dist;
	}
	printf("-- Max dist : %f \n", max_dist);
	printf("-- Min dist : %f \n", min_dist);
	//-- Draw only "good" matches (i.e. whose distance is less than 0.6*max_dist )
	//-- PS.- radiusMatch can also be used here.
	std::vector< DMatch > good_matches;
	for (int i = 0; i < descriptors_1.rows; i++)
	{
		if (matches[i].distance < 0.6*max_dist)
		{
			good_matches.push_back(matches[i]);
		}
	}

	//4-1.ªÊ÷∆∆•≈‰µ„
	Mat img_matches;
	drawMatches(img_1, keyPoints_1, img_2, keyPoints_2,
		good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
		vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

	//4-2.∏˘æ›∆•≈‰µ„ªÊ÷∆ƒø±ÍŒª÷√
	// localize the object
	std::vector<Point2f> obj;
	std::vector<Point2f> scene;
	for (size_t i = 0; i < good_matches.size(); ++i)
	{
		// get the keypoints from the good matches
		obj.push_back(keyPoints_1[good_matches[i].queryIdx].pt);
		scene.push_back(keyPoints_2[good_matches[i].trainIdx].pt);
	}
	Mat H = findHomography(obj, scene, CV_RANSAC);
	// get the corners from the image_1
	std::vector<Point2f> obj_corners(4);
	obj_corners[0] = cvPoint(0, 0);
	obj_corners[1] = cvPoint(img_1.cols, 0);
	obj_corners[2] = cvPoint(img_1.cols, img_1.rows);
	obj_corners[3] = cvPoint(0, img_1.rows);
	std::vector<Point2f> scene_corners(4);

	perspectiveTransform(obj_corners, scene_corners, H);

	// draw lines between the corners (the mapped object in the scene - image_2)
	line(img_matches, scene_corners[0] + Point2f(img_1.cols, 0), scene_corners[1] + Point2f(img_1.cols, 0), Scalar(255, 0, 0));
	line(img_matches, scene_corners[1] + Point2f(img_1.cols, 0), scene_corners[2] + Point2f(img_1.cols, 0), Scalar(255, 0, 0));
	line(img_matches, scene_corners[2] + Point2f(img_1.cols, 0), scene_corners[3] + Point2f(img_1.cols, 0), Scalar(255, 0, 0));
	line(img_matches, scene_corners[3] + Point2f(img_1.cols, 0), scene_corners[0] + Point2f(img_1.cols, 0), Scalar(255, 0, 0));
	imshow("Match", img_matches);

	cvWaitKey();

	return 0;
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

void test_functions::Test_using_selfcamera()
{
	VideoCapture capture(0);
	while (1)
	{
		Mat frame;
		capture >> frame;
		
		//Mat result = ;
		imshow("∂¡»° ”∆µ", frame);
		waitKey(30);//—” ±30ms
	}
}
