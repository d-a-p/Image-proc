#include<iostream>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

int main(){


	VideoCapture vid(0);  // 0 for camera no. 0

	if (!vid.isOpened()){
		cerr << "vid cannot open..." << endl;
		system("pause");
		return 0;
	}

	double dwidth = vid.get(CV_CAP_PROP_FRAME_WIDTH);
	double dheight = vid.get(CV_CAP_PROP_FRAME_HEIGHT);
	cout << "w = " << dwidth << endl << "h = " << dheight << endl;

	Size frameS(static_cast<int>(dwidth),static_cast<int>(dheight));
	VideoWriter wrivid("xxx.mpeg", CV_FOURCC('M','P','E','G'), 20, frameS,true);  // (name, codecs, fps, framesize, isColor)
	if (!wrivid.isOpened()){
		cout << "somthing Happened";
		system("pause");
		return 0;
	}

	namedWindow("this", CV_WINDOW_NORMAL);
	while (1)
	{
		Mat frm;
		bool bsux = vid.read(frm);
		if (!bsux){
			cout << "may be end";
			break;
		}
		wrivid.write( frm);
		imshow("this", frm);
		if (waitKey(30) == 27){
			cout << "esc key";
			break;
		}
	}


	//system("pause");
	return 0;


}