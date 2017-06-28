#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main(){
   namedWindow("output",WINDOW_AUTOSIZE);
   int g[9];
   int th=0;
   createTrackbar("theshold","output",&th,255);
   
   while(1){
     int  i,j,n,m,k=0;
  Mat img=imread("kk.jpg",0);

  Mat a(img.rows,img.cols,CV_8UC1,Scalar(0));
  
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
	sort(g,g+9); //important step ...
	int z=g[8]-g[0];
	if(z>th)
	  a.at<uchar>(i+1,j+1)=255;
	else
	  a.at<uchar>(i+1,j+1)=0;
	
       
      }

 
    imshow("output",a);
   i=waitKey(50);
  if(i==' ')
    break;}
  return 0;
   }
