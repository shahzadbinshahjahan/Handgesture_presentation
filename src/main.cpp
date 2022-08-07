#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <vector>

//user-defined headers
#include "function_headers.h"

int main()
{
    cv::VideoCapture webcam(0);
    cv::Mat img;

    std::vector<std::string> img_names;
    readImages(img_names);
    /*
    bool isSuccess=webcam.read(img);
    if(isSuccess)
    {
        while(true)
        {
            webcam.read(img);
            cv::imshow("Web Camera",img);
            char keyEntered=cv::waitKey(1);
            if(keyEntered=='q')
            {
                std::cout<<std::endl<<"Exit. Thank you!"<<std::endl;
                break; //breaking the while loop, which will stop the video playing
            }
        }
    }
    else
     std::cout<<"Web/Video Camera disconnected";
     */
    return 0;
}
