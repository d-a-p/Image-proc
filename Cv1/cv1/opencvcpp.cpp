#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<iostream>
#include<stdlib.h>
using namespace cv;
using namespace std;

void salt(Mat & im,const int n)
{
	for (int i = 0; i < n; i++)
	{
		int r = rand() % im.rows;
		int c = rand() % im.cols;
		if (im.channels() == 2){
			im.at<uchar>(r, c) = 255;

		}
		if (im.channels() == 3)
		{
			im.at<Vec3b>(r, c) = 255;
			im.at<Vec3b>(r, c) = 255;
			im.at<Vec3b>(r, c) = 255;

		}
	}
}
void clolorReduce(Mat & im, const int n=64){
	
	int r = im.rows;
	int c = im.cols*im.channels();
	for (int i = 0; i < r; i++)
	{
		uchar* z = im.ptr<uchar>(i);
		uchar mask = 0xFF << n;
		for (int j = 0; j < c; j++)
		{
			z[j] = (z[j]&mask) +n/2;
		}
	}
}
void sharpen(Mat & im, Mat &res){

	res.create(im.size(), im.type());
	cout << im.rows << " " << im.cols;
	for (int i = 1; i < im.rows-1; i++)
	{
		const uchar* cur = im.ptr<const uchar>(i);
		const uchar* next = im.ptr<const uchar>(i + 1);
		const uchar* prev = im.ptr<const uchar>(i-1);
		uchar* op = res.ptr<uchar>(i);
		for (int j = 1; j < im.cols*im.channels()-1; j++)
		{
			 *op++ = saturate_cast<uchar>(5 * cur[j] - next[j] - prev[j] - cur[j + 1] - cur[j - 1]);
		}
	}
	res.row(0).setTo(Scalar(0));
	res.row(im.rows - 1).setTo(Scalar(0));
	res.col(0).setTo(Scalar(0));
	res.col(im.cols - 1).setTo(Scalar(0));
}

int main(int argc, char ** argv ){
		
	Mat image = imread("city.png"), result;
	Mat im2 = imread("dap.png");
	namedWindow("s", WINDOW_AUTOSIZE);
	imshow("s", image);
	
	//flip(image, result, -1);
	salt(image, 2000);
	//sharpen(image, result);
	//add(image, 200, result);

	namedWindow("dap", WINDOW_AUTOSIZE);
	imshow("dap", result); 

	
	waitKey(0);
	//imwrite("output.bmp", result);
	return 0;
}
