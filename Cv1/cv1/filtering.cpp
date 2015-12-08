#include<iostream>
#include<opencv/cv.h>
#include<opencv2\highgui.hpp>
using namespace std;
int main(){
	IplImage* img = cvLoadImage("city.png"), *imgerod, *imgdilat, *imginv;
	imgerod = img;   // just to init imgerod to not get an error
	imgdilat = img;
	imginv = img;
	cvNamedWindow("WINDAP");
	cvShowImage("WINDAP", img);

	//eroding
	//*
	cvErode(img, imgerod, 0, 2);  // ( src, dest, [ structuring element used for erosion ], [ number of times, erosion is applied] ) 
								  //  if structuring element is 0 , a 3*3 rect structuring elements is used
	
	cvNamedWindow("Eroded");
	cvShowImage("Eroded", imgerod);
	//*

	//dilating - opposite of eroding
	//*
	cvDilate(img,imgdilat, 0 ,2);
	cvNamedWindow("Dilated");
	cvShowImage("Dilated", imgdilat);
	//*

	// inverting - like taking negative of image
	//*
	cvNot(imgdilat, imginv);
	cvNamedWindow("Inverted");
	cvShowImage("Inverted", imginv);
	//*

	cvWaitKey(0);
	cvReleaseImage(&imgerod);
	cvReleaseImage(&imgdilat);
	cvReleaseImage(&imginv);
	cout << "Getting out of here..." << endl;
}