#include<iostream>
#include<stdio.h>
#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    Mat image = imread("123.png", CV_LOAD_IMAGE_UNCHANGED);

    if(! image.data)  //check for valid input
    {
        cout << "coud not open or find the image" << std::endl;
            return -1;
    }

    namedWindow("input image", CV_WINDOW_AUTOSIZE);
    imshow("input image", image);

    Mat yuvchannel[3];
    Mat rgbchannel[3];
    split(image, yuvchannel);

    rgbchannel[0] = (yuvchannel[0] + (0.956*yuvchannel[1]) + (0.621*yuvchannel[2]));
    rgbchannel[1] = (yuvchannel[0] - (0.272*yuvchannel[1]) - (0.647*yuvchannel[2]));
    rgbchannel[2] = (yuvchannel[0] - (1.106*yuvchannel[1]) + (1.703*yuvchannel[2]));

    namedWindow("r image", CV_WINDOW_AUTOSIZE);
    imshow("r image",rgbchannel[0]);

    namedWindow("g image", CV_WINDOW_AUTOSIZE);
    imshow("g image", rgbchannel[1]);

    namedWindow("b image", CV_WINDOW_AUTOSIZE);
    imshow("b image", rgbchannel[2]);

    Mat img2(image.rows, image.cols, CV_8UC3);

    merge(rgbchannel, 3, img2);

    namedWindow("output", CV_WINDOW_AUTOSIZE);
    imshow("output", img2);

    waitKey(0);
    return 0;
}
