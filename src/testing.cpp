#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    // read the image from samples folder
    cv::Mat img = cv::imread("../samples/starry_night.jpg", cv::IMREAD_COLOR);

    if(img.empty())
    {
        std::cout << "Could not read the image ! " << std::endl;
        return 1;
    }

    // cerate an image holder to get the green channel
    cv::Mat channel;

    // Extract green plane
    cv::extractChannel(img, channel, 2);

    // Resize image for display
    cv::resize(channel, channel, cv::Size(), 0.20, 0.20);
    
    // Get a named window
    cv::namedWindow("Green Color plane");

    // show the green plane (gray image)
    imshow("Green Color plane", channel);
    
    int k = cv::waitKey(0);
    return 0;
}