#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main(){
  int t=0;
   namedWindow("canny",WINDOW_AUTOSIZE);
  createTrackbar("theshold","canny",&t,255/1.5);
  /* VideoCapture vidi(0);
  Mat a;
  namedWindow("video",WINDOW_AUTOSIZE);
  while(1)
    {
 
  vidi.read(a);
 
  imshow("video",a);
  */
  while(1){
    Mat a=imread("input.jpg",0);
  Mat b;//(a.rows,a.cols,CV_8UC1,Scalar(0));
  Canny(a,b,t,1.5*t,3);
  imshow("canny",b);
  imwrite("ext11.jpg",b);
 int i= waitKey(50);
 if(i==' ')
   break;}
  return 0;
}
