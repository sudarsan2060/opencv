
#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;

/* convert color to grey image  
void main()
{
	string path = "pic.png";
	Mat img=imread(path);
	Mat imgGRAY;
	cvtColor(img, imgGRAY, COLOR_BGR2GRAY);
	imshow("image", img);
	imshow("image gray", imgGRAY);
	waitKey(0);

}  
*/
/* image blur*/
void main()
{
	string path = "pic.png";
	Mat img = imread(path);
	Mat imgGRAY,imgblur,imgCanny,imgdialation,imgero;
	cvtColor(img, imgGRAY, COLOR_BGR2GRAY);
	GaussianBlur(img, imgblur, Size(7, 7), 5, 0);
	Canny(imgblur, imgCanny, 50, 150);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgdialation, kernel);
	erode(imgCanny, imgero, kernel);
	imshow("image", img);
	imshow("image gray", imgGRAY);
	imshow("imageblur", imgblur);
	imshow("imgCanny", imgCanny);
	imshow("imgdialtion", imgdialation);
	imshow("imgero", imgero);
	waitKey(0);

}