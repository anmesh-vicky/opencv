#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
 Mat a=imread("pea1.gif",0);
Mat b(sqrt(a.rows*a.rows+a.cols*a.cols)/2,180,CV_8UC1,Scalar(0));

int main()
{int i,j,n;
  for(i=0;i<a.rows;i++)
    for(j=0;j<a.cols;j++)
      if(a.at<uchar>(i,j)==255)
	{
	  for(n=0;n<180;n++)
	    {   float p=CV_PI*n/180;
	  float d=i*cos(p)+j*sin(p);
	  if(d>0)
	  if(b.at<uchar>((int)d/2,n)<255)
	    b.at<uchar>((int)d/2,n)+=3;}
	}
  namedWindow("grap",WINDOW_AUTOSIZE);
    imshow("grap",b);
    
  waitKey(0);
  return 0;
}
