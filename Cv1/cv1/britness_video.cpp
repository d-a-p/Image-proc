#include<iostream>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int main(){
	VideoCapture cap("C:\\Users\\DAP\\Desktop\\TEMP-DESK\\Fox_Stevenson&Curbi-Hoohah.mp4");
	if (!cap.isOpened()){
		cout << "cant open it...!!!";
		return -1;
	}

	namedWindow("original", WINDOW_AUTOSIZE);
	namedWindow("high", WINDOW_AUTOSIZE);
	namedWindow("loe", WINDOW_AUTOSIZE);

	while (1)
	{
		Mat frame;
		bool bsuxes = cap.read(frame);
		if (!bsuxes){
			cout << "somthin happen...!!!";
			return - 1;
		}
		Mat fH = frame + Scalar(100,100,100);
		Mat fL = frame - Scalar(100,100,100);

		imshow("original",frame);
		imshow("high", fH);
		imshow("low", fL);
		if (waitKey(30) == 27){
			break;
		}
		
	}

	return 0;
}