#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int main()
{
    cv::VideoCapture cam(0);
    cv::Mat webImg;
    cv::Mat slideImg=cv::imread("../Resources/test/1.png");

    int w_height=120,w_width=200;
    //cv::Mat overlayImage
    while(true)
    {
        cam.read(webImg);

        //
        cv::resize(webImg,webImg,cv::Size(w_height,w_width));
        cv::Rect roi(cv::Point(slideImg.size().width-w_width,0),cv::Size(w_height,w_width));
        webImg.copyTo(slideImg(roi));
        //
        //cv::imshow("webcam",webImg);
        cv::imshow("slide",slideImg);
        cv::waitKey(1);
    }
}