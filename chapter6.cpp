#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;
/// <summary>
/// shape detector
/// </summary>
 
void getContours(Mat imgdil, Mat img)
{
	vector<vector<Point>> contours;
	vector<Vec4i>hierarchy;
	findContours(imgdil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
	for (int i = 0;i < contours.size();i++)
	{
		int area = contourArea(contours[i]);
		cout << area << endl;
		vector<vector<Point>> conPoly(contours.size());
		if (area > 1000)
		{   
			approxPolyDP(contours[i], conPoly[i], 3, true);
			drawContours(img, contours, i, Scalar(255, 0, 255), 2);
		}
	}
}
void main()
{
	string path = "shapes.png";
	Mat img = imread(path);
	Mat imgGRAY, imgblur, imgCanny, imgdialtion, imgero;
	cvtColor(img, imgGRAY, COLOR_BGR2GRAY);
	GaussianBlur(img, imgblur, Size(7, 7), 5, 0);
	Canny(imgblur, imgCanny, 50, 150);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgdialtion, kernel);
	getContours(imgdialtion, img);
	 
	imshow("imgdialtion", imgdialtion);
	 
	waitKey(0);
}