#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()
{int i,j,k;
  Mat img=imread("read.jpg",0);
  int a[256];
    int r=img.rows;
  int c=img.cols;
  for(i=0;i<256;i++)
    a[i]=0;
  for(i=0;i<r;i++)
    for(j=0;j<c;j++)
      {
	a[img.at<uchar>(i,j)]++;
      }int max=a[0];
   for(i=0;i<256;i++)
     a[i]/=2;
  for(i=0;i<256;i++)
    if(max<a[i])
      max=a[i];
  Mat n(max+10,256,CV_8UC1,Scalar(0));
  for(i=0;i<256;i++)
    for(j=max+10-a[i];j<=max;j++)
      {
	n.at<uchar>(j,i)=255;
      }
  namedWindow("his",WINDOW_AUTOSIZE);
  imshow("his",n);
  waitKey(0);
  return 0;
}
