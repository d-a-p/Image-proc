#include<iostream>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

int main(){

	Mat img = imread("dap.png", CV_LOAD_IMAGE_UNCHANGED);
//	Mat img(500,1000, CV_8UC1, Scalar(0,0,100));


	if (img.empty()){
		cerr << "image not found!!..." << endl;
		return -1;
	}
	
	namedWindow("this", CV_WINDOW_NORMAL);
	
	
	imshow("this", img);

	waitKey(0);
	system("pause");
	return 0;


}