#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

int main()
{
    cv::VideoCapture webcam(0);
    cv::Mat img;

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
                std::cout<<"Exit. Thank you!";
                break; //breaking the while loop, which will stop the video playing
            }
        }
    }
    else
     std::cout<<"Web/Video Camera disconnected";
}