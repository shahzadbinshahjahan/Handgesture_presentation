//this is just an implementation for developing
//actual definition will be done after finishing hand gestures and drawing on screen
#include <iostream>
#include <vector>

//this function will read all the images from a given path
void readImages(std::vector<std::string>& rimg_names)
{
    std::string path="Resources/test/";
    //std::vector<std::string> img_names;
    for(uint32_t i=0;i<9;i++)
    {
        char ch='0'+(i+1);
        path=path+ch+".png";
        rimg_names.push_back(path);
        //std::cout<<rimg_names[i]<<std::endl;
        path="Resources/test/";
    }
}