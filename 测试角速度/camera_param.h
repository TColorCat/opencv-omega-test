#ifndef camera_param_h_
#define camera_param_h_

#include<iostream>
#include<string>
#include<cv.h>
//#include <cv.hpp> 
namespace camera_param
{
	//using namespace std;
	using cv::Point3f;
	using cv::Point2f;
	using cv::Size;
	using cv::Mat;
	using std::string;
	using std::vector;

	/*相机标定需要的常数
		const int imageWidth = 640;                             //摄像头的分辨率  
		const int imageHeight = 480;
		const int boardWidth = 9;                               //横向的角点数目  
		const int boardHeight = 6;                              //纵向的角点数据  
		const int boardCorner = boardWidth * boardHeight;       //总的角点数据  
		const int frameNumber = 13;                             //相机标定时需要采用的图像帧数  
		const int squareSize = 20;                              //标定板黑白格子的大小 单位mm  
		const Size boardSize = Size(boardWidth, boardHeight);   //  
	*/
	namespace Const_param
	{
		const int imageWidth = 640;                             //摄像头的分辨率  
		const int imageHeight = 480;
		const int boardWidth = 9;                               //横向的角点数目  
		const int boardHeight = 6;                              //纵向的角点数据  
		const int boardCorner = boardWidth * boardHeight;       //总的角点数据  
		const int frameNumber = 13;                             //相机标定时需要采用的图像帧数  
		const int squareSize = 20;                              //标定板黑白格子的大小 单位mm  
		const Size boardSize = Size(boardWidth, boardHeight);   //  
	}

	/*相机内外参数数据结构区
	@  intrinsic：相机内参
	@  distortion_coeff 相机畸变参数
	//外参
	@  rerse_vecs 旋转矢量
	@  trans_vecs 平移矢量
	*/
	struct parame_carmera
	{
		Mat intrinsic;                                          //相机内参数  
		Mat distortion_coeff;                                   //相机畸变参数  
		/*内参：
			fx 0 cx
			0 fy cy
			0 0  1
			畸变参数：k1 k2 p1 p2 p3*/

		//外参
		vector<Mat>rerse_vecs;//旋转矢量 
		vector<Mat>tran_vecs;//平邑矢量
	};
	

	
	void guessCameraParam(parame_carmera& );

	/*计算标定板上模块角点的实际物理坐标*/
	void calRealPoint(vector<vector<Point3f>>& obj, int boardwidth, int boardheight, int imgNumber, int squaresize);

	/*计算标定板被摄像机记录下的角点图像坐标*/
	void calImg_cornerPoint(vector<Mat>&imgs, vector<vector<Point2f>>&, const Size boardSize);

	/*计算单目相机内外参*/
	void calSingle_param(vector<vector<Point3f>>&objRealPoint,
							vector<vector<Point2f>>&img_corners,
							const Size& boardSize,
							parame_carmera&car);
	
}

#endif