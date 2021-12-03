#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;
/// <summary>
/// drawing shapes
/// </summary>
void main()
{
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 0));
	
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255),FILLED);
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255));
	putText(img, "SUDARSAN REDDY", Point(137, 262), FONT_HERSHEY_COMPLEX, 0.75, Scalar(0, 69, 255), 2);
imshow("img", img);
	waitKey(0);

}