#pragma once
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
using namespace cv;

class Histogram{
	int histsize[1];				//no. of bins
	float hranges[2];
	const float* ranges[1];
	int channels[1];
public:
	Histogram()
	{
		histsize[0] = 256;
		hranges[0] = 0.0;
		hranges[1] = 255.0;
		ranges[0] = hranges;
		channels[0] = 0;
	}
	MatND getHist(const Mat &image)
	{
		MatND hist;
		cvCalcHist(&image, 1, channels, , hist, 1, histsize, ranges);
		cv
	}


};
