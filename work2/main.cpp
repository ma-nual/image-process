#include <QtCore/QCoreApplication>
//#include <opencv2\opencv.hpp>
//#include <math.h>
//#include <iostream>

//using namespace std;
//using namespace cv;

//int thresh = 15;
//int max_count = 255;
//Mat img, img_gray;
//const char* output_title = "Harris Corner Dectction Result";
//void Harris_Demo(int, void *);

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);
//    img = imread("E:/store/cv work/11.jpg");
////    if (img.empty()) {
////            cout << "colud not load image..." << endl;
////            return -1;
////    }
//    namedWindow("input image", CV_WINDOW_NORMAL);
//    imshow("input image", img);
//    //以上是图像处理的标准开头
//    namedWindow(output_title, CV_WINDOW_NORMAL);
//    cvtColor(img, img_gray, CV_BGR2GRAY);

////    createTrackbar("Threshold", output_title, &thresh, max_count, Harris_Demo);
//    Harris_Demo(0, 0);

//    waitKey(0);
//    return a.exec();
//}

//void Harris_Demo(int, void *) {

//        Mat dst, norm_dst, normScaleDst;
//        dst = Mat::zeros(img_gray.size(), CV_32FC1);
//        //harris角点核心函数
//        int blockSize = 2;
//        int ksize = 3;
//        int k = 0.04;

//        cornerHarris(img_gray, dst, blockSize, ksize, k, BORDER_DEFAULT);
//        //上述输出的取值范围并不是0-255 需要按照最大最小值进行归一化
//        normalize(dst, norm_dst, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
//        convertScaleAbs(norm_dst, normScaleDst);

//        Mat resultImg = img.clone();
//        //用彩色来显示
//        for (int row = 0; row < resultImg.rows; row++) {
//                //定义每一行的指针
//                uchar* currentRow = normScaleDst.ptr(row);
//                for (int col = 0; col < resultImg.cols; col++) {
//                        int value = (int)*currentRow;
//                        if (value > thresh) {
//                                circle(resultImg, Point(col, row), 10, Scalar(0, 0, 255), 2, 8, 0);
//                        }
//                        currentRow++;
//                }
//        }

//        imshow(output_title, resultImg);
//}


//#include "opencv2/core/core.hpp"
//#include<cv.h>
//#include<highgui.h>

//using namespace cv;
//using namespace std;

//CvPoint pt1 = Point(0, 0);
//CvPoint pt2 = Point(0, 0);
//bool is_selecting = false;
//void cvMouseCallback(int mouseEvent, int x, int y, int flags, void* param)
//{
//    switch (mouseEvent)
//    {
//        case CV_EVENT_LBUTTONDOWN:
//        pt1 = Point(x, y);
//        pt2 = Point(x, y);
//        is_selecting = true;
//        break;
//        case CV_EVENT_MOUSEMOVE:
//        if (is_selecting)
//        pt2 = Point(x, y);
//        break;
//        case CV_EVENT_LBUTTONUP:
//        pt2 = Point(x, y);
//        is_selecting = false;
//        break;
//    }
//}


//int main()
//{
//    IplImage* img = cvLoadImage("E:/store/cv work/7.jpg");
//    IplImage* img_show = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 3);
//    cvNamedWindow("img", CV_WINDOW_NORMAL);
//    cvSetMouseCallback("img", cvMouseCallback);
//    bool shift_on = false;
//    while (true)
//    {
//        cvCopy(img, img_show);
//        cvRectangle(img_show, pt1, pt2, Scalar(0, 0, 255),10);
//        cvShowImage("img", img_show);
//        char key = cvWaitKey(10);
//        cvSetImageROI(img_show,cvRect(pt1.x, pt1.y, abs(pt2.x - pt1.x), abs(pt2.y - pt1.y)));
//        IplImage* roi = cvCreateImage(cvSize(abs(pt2.x - pt1.x), abs(pt2.y - pt1.y)), IPL_DEPTH_8U, 3);
//        cvCopy(img_show, roi);
//        cvResetImageROI(img_show);
//        cvSaveImage("ROI.jpg", roi);
//        if (key == 27) break;
//    }
//    return 0;
//}



#include "opencv2/core/core.hpp"
#include<cv.h>
#include<highgui.h>
#include "GLCM.h"

using namespace cv;
using namespace std;

int main()
{
    IplImage* img = cvLoadImage("ROI.jpg", 0);
    GLCM glcm;
    VecGLCM vec;
    GLCMFeatures features;
    glcm.initGLCM(vec);
    // 水平
    glcm.calGLCM(img, vec, GLCM::GLCM_HORIZATION);
    glcm.getGLCMFeatures(vec, features);

    cout << "水平" << endl;
    cout << "asm = " << features.energy << endl;
    cout << "eng = " << features.entropy << endl;
    cout << "Con = " << features.contrast << endl;
    cout << "Idm = " << features.idMoment << endl;

    // 垂直
    glcm.calGLCM(img, vec, GLCM::GLCM_VERTICAL);
    glcm.getGLCMFeatures(vec, features);

    cout << "垂直" << endl;
    cout << "asm = " << features.energy << endl;
    cout << "eng = " << features.entropy << endl;
    cout << "Con = " << features.contrast << endl;
    cout << "Idm = " << features.idMoment << endl;

    // 45 度
    glcm.calGLCM(img, vec, GLCM::GLCM_ANGLE45);
    glcm.getGLCMFeatures(vec, features);

    cout << "45度" << endl;
    cout << "asm = " << features.energy << endl;
    cout << "eng = " << features.entropy << endl;
    cout << "Con = " << features.contrast << endl;
    cout << "Idm = " << features.idMoment << endl;

    // 135 度
    glcm.calGLCM(img, vec, GLCM::GLCM_ANGLE135);
    glcm.getGLCMFeatures(vec, features);

    cout << "135度" << endl;
    cout << "asm = " << features.energy << endl;
    cout << "eng = " << features.entropy << endl;
    cout << "Con = " << features.contrast << endl;
    cout << "Idm = " << features.idMoment << endl;

    return 0;
}

