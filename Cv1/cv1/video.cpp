#include<iostream>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

int main(){


	//VideoCapture vid("C:/\Users/\DAP/\Videos/\ddd.mp4");
	VideoCapture vid(0);  // 0 for camera no. 0

	if (!vid.isOpened()){
		cerr << "vid cannot open..." << endl;
		system("pause");
		return 0;
	}

	double dwidth = vid.get(CV_CAP_PROP_FRAME_WIDTH);
	double dheight = vid.get(CV_CAP_PROP_FRAME_HEIGHT);
	cout << "w = " << dwidth << endl << "h = " << dheight << endl;


	double fps = vid.get(CV_CAP_PROP_FPS);
	cout << fps << endl;
	namedWindow("this", CV_WINDOW_NORMAL);
	while (1)
	{
		Mat frm;
		bool bsux = vid.read(frm);
		if (!bsux){
			cout << "may be end";
			break;
		}
		imshow("this", frm);

		if (waitKey(30) == 27){
			cout << "esc key";
			break;
		}
	}


	system("pause");
	return 0;


}