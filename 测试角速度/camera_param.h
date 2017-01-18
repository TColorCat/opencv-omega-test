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

	/*����궨��Ҫ�ĳ���
		const int imageWidth = 640;                             //����ͷ�ķֱ���  
		const int imageHeight = 480;
		const int boardWidth = 9;                               //����Ľǵ���Ŀ  
		const int boardHeight = 6;                              //����Ľǵ�����  
		const int boardCorner = boardWidth * boardHeight;       //�ܵĽǵ�����  
		const int frameNumber = 13;                             //����궨ʱ��Ҫ���õ�ͼ��֡��  
		const int squareSize = 20;                              //�궨��ڰ׸��ӵĴ�С ��λmm  
		const Size boardSize = Size(boardWidth, boardHeight);   //  
	*/
	namespace Const_param
	{
		const int imageWidth = 640;                             //����ͷ�ķֱ���  
		const int imageHeight = 480;
		const int boardWidth = 9;                               //����Ľǵ���Ŀ  
		const int boardHeight = 6;                              //����Ľǵ�����  
		const int boardCorner = boardWidth * boardHeight;       //�ܵĽǵ�����  
		const int frameNumber = 13;                             //����궨ʱ��Ҫ���õ�ͼ��֡��  
		const int squareSize = 20;                              //�궨��ڰ׸��ӵĴ�С ��λmm  
		const Size boardSize = Size(boardWidth, boardHeight);   //  
	}

	/*�������������ݽṹ��
	@  intrinsic������ڲ�
	@  distortion_coeff ����������
	//���
	@  rerse_vecs ��תʸ��
	@  trans_vecs ƽ��ʸ��
	*/
	struct parame_carmera
	{
		Mat intrinsic;                                          //����ڲ���  
		Mat distortion_coeff;                                   //����������  
		/*�ڲΣ�
			fx 0 cx
			0 fy cy
			0 0  1
			���������k1 k2 p1 p2 p3*/

		//���
		vector<Mat>rerse_vecs;//��תʸ�� 
		vector<Mat>tran_vecs;//ƽ��ʸ��
	};
	

	
	void guessCameraParam(parame_carmera& );

	/*����궨����ģ��ǵ��ʵ����������*/
	void calRealPoint(vector<vector<Point3f>>& obj, int boardwidth, int boardheight, int imgNumber, int squaresize);

	/*����궨�屻�������¼�µĽǵ�ͼ������*/
	void calImg_cornerPoint(vector<Mat>&imgs, vector<vector<Point2f>>&, const Size boardSize);

	/*���㵥Ŀ��������*/
	void calSingle_param(vector<vector<Point3f>>&objRealPoint,
							vector<vector<Point2f>>&img_corners,
							const Size& boardSize,
							parame_carmera&car);
	
}

#endif