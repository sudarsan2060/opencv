
#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;

/// <summary>
/// resize image and crop;
/// </summary>
void main()
{
	string path = "pic.png";
	Mat img = imread(path);
	Mat rimg,imgcrop;

	Rect roi(100, 100, 300, 250);
	imgcrop = img(roi);

	//cout << img.size()<<endl;
	resize(img, rimg,Size(640,480));
	imshow("image", img);
	imshow("rimage", rimg);
	imshow("cropimage", imgcrop);
	waitKey(0);

}