#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int main(){
	Mat img = imread("city.png",CV_LOAD_IMAGE_COLOR);
	if (img.empty()){
		cout << "cant be loaded...!!";
		return -1;
	}
	//Mat imgH = img + Scalar(100,100,100);
	
	//img.convertTo(imgH,-1,2,0);                  // imgH = img*2+0;  -1 for same depth as input
	
	namedWindow("original", WINDOW_AUTOSIZE);
	

	int slidervalue = 50;
	createTrackbar("britness", "original", &slidervalue, 100);     // for trackbar

	int slidervL2 = 50;
	createTrackbar("contrass", "original", &slidervL2, 100);

	while (1)
	{
		Mat imgH;

		int brit = slidervalue - 50;
		float cont = slidervL2 / 50.0;
		img.convertTo(imgH,-1,cont,brit);

	
	
		imshow("original", imgH);
		int i = waitKey(50);
		if (i == 27){
			break;
		}
	
	}


	
	
	

	//waitKey(0);
	destroyAllWindows();

	return 0;
}