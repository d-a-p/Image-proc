#include<iostream>
#include<vector>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#define B_W 0								//histograam of black&white image or not
using namespace std;
using namespace cv;

int main(){


	Mat src = imread("city.png");
	if (src.empty())
	{
		cout << "Image cant ve loaded!!" << endl;
		return -1;
	}
	vector<Mat> channels;
	imshow("or", src);
	Mat dup;
#if B_W:
	cvtColor(src,src,CV_BGR2GRAY);
	equalizeHist(src,dup);
#else
	cvtColor(src, src, CV_BGR2YCrCb);
	split(src, channels);								//split img into channels
	equalizeHist(channels[0], channels[0]);
	merge(channels, src);
	cvtColor(src, dup, CV_YCrCb2BGR);


#endif
	namedWindow("or", WINDOW_AUTOSIZE);
	namedWindow("histogram equilized", WINDOW_AUTOSIZE);

	imshow("or", src);
	imshow("histogram equilized", dup);

	waitKey(0);
	destroyAllWindows();
	return 0;



}