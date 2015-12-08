#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<vector>
using namespace cv;
using namespace std;

int main(){

	Mat img(1080,1920, CV_16UC3, Scalar(0,50000,50000)); // 16 bit depth with (B, G, R)

	if (img.empty()){
		cerr << "image not found!!..." << endl;
		return -1;
	}
	vector <int> comparam;
	comparam.push_back(CV_IMWRITE_JPEG_QUALITY); // compression tech
	comparam.push_back(98); // compression quality
	bool bsux = imwrite("xxx.jpeg",img,comparam);
	if (!bsux){
		cout << "something happened....";
		system("pause");
		return 0;
	}
	namedWindow("this", CV_WINDOW_NORMAL);


	imshow("this", img);

	waitKey(0);
	//system("pause");
	return 0;


}