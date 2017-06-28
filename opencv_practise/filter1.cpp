#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()
{float  g[9];
  Mat img=imread("lisa.png",0);
  int  i,j,n,m,k=0;
  int r=img.rows,c=img.cols;
  for(i=0;i<r-3;i+=1)
    for(j=0;j<c-3;j+=1)
      {
	for(n=i;n<i+3;n++)
	  for(m=j;m<j+3;m++)
	    {
	      g[k]=img.at<uchar>(n,m);
	      k++;
	    }k=0;
	sort(g,g+9);//important step ...
	img.at<uchar>(i+1,j+1)=g[4];
       
      }

  namedWindow("output",WINDOW_AUTOSIZE);
    imshow("output",img);
  waitKey(0);
  return 0;
}
	  
