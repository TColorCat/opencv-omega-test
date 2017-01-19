
#include "stdafx.h"
#include"camera_param.h"
#include <opencv2/opencv.hpp>  
#include <highgui.hpp>  
#include<iterator>

using namespace std;
using namespace cv;
/*
@struct parame_carmera&car
{
	@param instrinsic  Martix 3X3 ,is the instrinsic valus for camera
			fx 0 cx
			0 fy cy
			0 0  1
	@param distortion_coeff is the distortion values for camera
}*/
void camera_param::guessCameraParam(parame_carmera&car)
{
	/*分配内存*/
	car.intrinsic.create(3, 3, CV_64FC1);
	car.distortion_coeff.create(5, 1, CV_64FC1);

	/*
	fx 0 cx
	0 fy cy
	0 0  1
	*/
	car.intrinsic.at<double>(0, 0) = 256.8093262;   //fx         
	car.intrinsic.at<double>(0, 2) = 160.2826538;   //cx  
	car.intrinsic.at<double>(1, 1) = 254.7511139;   //fy  
	car.intrinsic.at<double>(1, 2) = 127.6264572;   //cy  

	car.intrinsic.at<double>(0, 1) = 0;
	car.intrinsic.at<double>(1, 0) = 0;
	car.intrinsic.at<double>(2, 0) = 0;
	car.intrinsic.at<double>(2, 1) = 0;
	car.intrinsic.at<double>(2, 2) = 1;

	/*
	k1 k2 p1 p2 p3
	*/
	car.distortion_coeff.at<double>(0, 0) = -0.193740;  //k1  
	car.distortion_coeff.at<double>(1, 0) = -0.378588;  //k2  
	car.distortion_coeff.at<double>(2, 0) = 0.028980;   //p1  
	car.distortion_coeff.at<double>(3, 0) = 0.008136;   //p2  
	car.distortion_coeff.at<double>(4, 0) = 0;          //p3 
}

/*
@ imgs is the prepared pictures for calibration 
@img_corner is the array of finded corner point on the pictures
@boardSize = number of corner points in row X number of corner points in col
*/
void camera_param::calImg_cornerPoint(vector<Mat>&imgs, vector<vector<Point2f>>&img_corners, const Size boardSize,
									const string&output)
{
	vector<Mat>::iterator it=imgs.begin() , end=imgs.end();
	int count = 1;
	for (; it != end; ++it)
	{
		
		Mat grayimg;
		cvtColor(*it, grayimg, CV_BGR2GRAY);
		vector<Point2f> corner;
		if (findChessboardCorners(*it, boardSize, corner, 0))
		{
			
			cornerSubPix(grayimg, corner, Size(5, 5), Size(-1, -1),
				TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 20, 0.1)
				);
			drawChessboardCorners(*it, boardSize, corner, 1);

			img_corners.push_back(corner);
			string temp = output;
			temp += to_string(count) + "P.jpg";

				imwrite( temp , *it);
		}
		else
			cout << "failed,no finded" << endl;
		++count;
	}

}

/*计算标定板上模块角点的实际物理坐标
@obj: the array of each picture's corner pointer in real 3D world
@boardwidth: number of corner points on row
@boardheight: number of corner points on col
@imgnumber: the number of imgs
@squaresize: the size of the block on the cheese picture 
*/
void camera_param::calRealPoint(vector<vector<Point3f>>& obj, int boardwidth, int boardheight, int imgNumber, int squaresize)
{
	vector<Point3f> imgpoint;
	for (int rowIndex = 0; rowIndex < boardheight; rowIndex++)
	{
		for (int colIndex = 0; colIndex < boardwidth; colIndex++)
		{
			//  imgpoint.at<Vec3f>(rowIndex, colIndex) = Vec3f(rowIndex * squaresize, colIndex*squaresize, 0);  
			imgpoint.push_back(Point3f(rowIndex * squaresize, colIndex * squaresize, 0));
		}
	}
	for (int imgIndex = 0; imgIndex < imgNumber; imgIndex++)
	{
		obj.push_back(imgpoint);
	}
}

/*
camera calibration for single camera
@objRealPoint: the 3D location of corner points in all the prepared pictures in real world
@img_corners: the 2D location of corner points in pictures
@boardSize : const param to camera
@car    :    pamera
*/
void camera_param::calSingle_param(vector<vector<Point3f>>&objRealPoint, 
									vector<vector<Point2f>>&img_corners, 
									const Size& boardSize, 
									parame_carmera&car)
{
	calibrateCamera(objRealPoint, img_corners, boardSize, car.intrinsic, car.distortion_coeff, car.rerse_vecs, car.tran_vecs, 0);
}





/*test  calImg_cornerPoint
@input input cheese picture
@output the result will be placed in this folder
*/
void camera_param::test_example::test_cal_img_cornerPoint(const string&input
														, const string&output)
{
	vector<Mat>corner;
	vector<vector<Point2f>>img_corners;


	corner.push_back(imread(input));
	camera_param::calImg_cornerPoint(corner, img_corners, camera_param::Const_param::boardSize,output);
}