#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;
/// <summary>
/// color detector
/// </summary>
int hmin = 0, smin = 0, vmin =0;
int hmax = 179, smax = 255, vmax = 255;
void main()
{
	Mat imghsv,mask;

	string path = "lambo.png";
	Mat img = imread(path);
	cvtColor(img, imghsv, COLOR_BGR2HSV);
	namedWindow("trackbar", (640, 200));
	createTrackbar("hmin", "trackbar", &hmin, 179);
	createTrackbar("hmax", "trackbar", &hmax, 179);
	createTrackbar("smin", "trackbar", &smin, 255);
	createTrackbar("smax", "trackbar", &smax, 255);
	createTrackbar("vmin", "trackbar", &vmin,255);
	createTrackbar("vmax", "trackbar", &vmax, 255);
	while(true){
	Scalar lower(hmin, smin, vmin);
	Scalar upper(hmax, smax, vmax);
	inRange(imghsv, lower, upper, mask);
	imshow("image", img);
	imshow("imshsv", imghsv);
	imshow("img mask", mask);
	waitKey(1);
	}
}