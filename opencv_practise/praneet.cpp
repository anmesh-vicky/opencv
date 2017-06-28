#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	/*Mat a(400,400, CV_8UC3, Scalar(0,0,0));
	namedWindow("praneet", WINDOW_AUTOSIZE);
	for (int i = 100; i < 300; i++)
	{
	for (int j = 100; j < 300; j++)
	{
	a.at<Vec3b>(i, j)[2] = 255;
	}
	}
	imshow("praneet", a);
	waitKey(0);
	return 0;

	Mat a = imread("C:\\Users\\abcd\\Pictures\\Camera Roll\\p.jpg", 1);
	int r = a.rows, p = a.cols, i, j;
	for (i = 0; i <r; i++)
	{
	for (j = 0; j <p; j++)
	{
	if (a.at<Vec3b>(i, j)[1] <= 235)
	a.at<Vec3b>(i, j)[1] += 20;

	else
	a.at<Vec3b>(i, j)[1] = 255;
	if (a.at<Vec3b>(i, j)[2] <= 235)
	a.at<Vec3b>(i, j)[2] += 20;

	else
	a.at<Vec3b>(i, j)[2] = 255;
	if (a.at<Vec3b>(i, j)[0] <= 235)
	a.at<Vec3b>(i, j)[0] += 20;

	else
	a.at<Vec3b>(i, j)[0] = 255;



	}
	}
	namedWindow("praneet", WINDOW_AUTOSIZE);

	imshow("praneet", a);
	waitKey(0);
	return 0;
	}*/
	Mat a = imread("image.jpg", 1);
	int r = a.rows, p = a.cols, i, j;

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < p; j++)
		{
			for (int k = 0; k <= 2; k++)
				a.at<Vec3b>(i, j)[k] = a.at<Vec3b>(i, p - j - 1)[k];
		}
	}
	namedWindow("praneet", WINDOW_AUTOSIZE);

	imshow("praneet", a);
	waitKey(0);
	return 0;
}
