#define PATH "image.jpg"
#define BorderR 255
#define BorrderG 252
#define BorderB 121

#define TroubleR 255
#define TroubleG 37
#define TroubleB 1
#include <stdio.h>
#include <opencv2/opencv.hpp>




using namespace std;
using namespace cv;

bool IsColour(Vec3b intensity, int B, int G, int R) {
    // print individual component [B G R]
    int blue = intensity.val[0];
    int green = intensity.val[1];
    int red = intensity.val[2];
    return (B == blue) && (R == red) && (G == green);
}
int main(int argc, char** argv)
{

    cv::Mat img;  // variable image of datatype Matrix
    img = cv::imread(PATH);

    int width = cv::shape[1]-1;
    int height = cv:shape[0];
    int borders = 0;
    for (int i = 0; i < width; i++) {
        if (IsColour(img.at<Vec3b>(i, 10), BorderB, BorderG, BorderR) && !IsColour(img.at<Vec3b>(10, i + 1), BorderB, BorderG, BorderR)) {
            borders++;
        }
    }
    int widthP = (width + 1) / (borders - 2);
    bool arr[width - 1];
    for (int i = 0; i < width - 1; i++)
        arr[i] = true;
    for (int i = 0; i < width - 1; i++) {
        for (int y = 0; y < height; y++) {
            for (int j = widthP * i; j < widthP * (i + 1); j++) {
                if (IsColour(img.at<Vec3b>(j, y), TroubleB, TroubleG, TroubleR))
                    arr[i] = false;
            }
            if (!arr[i]) {
                cout << i;
                return 0;
            }
        }
    }
    return 0;
}