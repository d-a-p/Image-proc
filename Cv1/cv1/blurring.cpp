#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int main(){
	

	Mat src = imread("city.png");
	if (src.empty())
	{
		cout << "Image cant ve loaded!!" << endl;
		return -1;
	}

	imshow("or", src);
	Mat dup;
	cvtColor();

	namedWindow("or", WINDOW_AUTOSIZE);
	namedWindow("blu", WINDOW_AUTOSIZE);

	for (int i = 1; i < 29; i=i+2)
	{
		cout << "kernal is square and hight is " << i<< endl;
	//	blur(src, dup, Size(i, i));								//normal blur
		GaussianBlur(src, dup, Size(i, i), 0, 0);				// gaussian blur
		medianBlur(src, dup, i);								// median blur
		bilateralFilter(src, dup, i, i, i);						// bilateral smoothing
		
		
		
		imshow("blu", dup);
		int c = waitKey(2000);
		if (c == 27){
			return 0;
		}
		
	
	}
	waitKey(2000);
	return 0;



}