#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
//#include <vector>

//user-defined headers
#include "function_headers.h"

int main()
{
    cv::VideoCapture webcam(0);
    cv::Mat webFrame;

    std::vector<std::string> img_names;
    readImages(img_names);

    //fix::variable to hold the current image
    uint32_t img_number=4;
    cv::Mat currentSlide=cv::imread(img_names[img_number-1],cv::IMREAD_UNCHANGED);
    //resizing the current slide to fit my laptop screen 
    cv::resize(currentSlide,currentSlide,cv::Size((int)(1366/1.1),(int)(768/1.1)));
    //current img of the presentation
    //std::cout<<currentSlide.size().width<<" "<<currentSlide.size().height<<std::endl;
       
    
    //fix::have to update the window name to the name of the presentation
    cv::waitKey(0);
    
    uint32_t webcam_height=273,webcam_width=153; //web camera fixed dimensions
    bool isSuccess=webcam.read(webFrame);
    if(isSuccess)
    {
        while(true)
        {
            webcam.read(webFrame);
            //adjusting the webcam, making it smaller and fixing it on top right of the presentation
            cv::resize(webFrame,webFrame,cv::Size(webcam_height,webcam_width));
            //creating a region of interest in slide to place webcam
            //roi(Point(originx,originy),Size(width,height))
            cv::Rect roi(cv::Point((currentSlide.size().width-webcam_height),0),cv::Size(webcam_height,webcam_width)); 
            //cv::rectangle(currentSlide,roi,cv::Scalar(255,0,0));
            webFrame.copyTo(currentSlide(roi));


            //cv::imshow("Web Camera",webFrame);
            cv::imshow("Slide",currentSlide);

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
     
    return 0;
}
