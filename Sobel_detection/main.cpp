#include <QtCore/QCoreApplication>
#include "core/core.hpp"
#include "highgui/highgui.hpp"
#include "imgproc/imgproc.hpp"
#include "iostream"

using namespace std;
using namespace cv;

int main(int argc,char *argv[])
{
    Mat image=imread("E:/store/cv work/10.jpg",0);
    Mat imageX=Mat::zeros(image.size(),CV_16SC1);
    Mat imageY=Mat::zeros(image.size(),CV_16SC1);
    Mat imageXY=Mat::zeros(image.size(),CV_16SC1);
    Mat imageX8UC;
    Mat imageY8UC;
    Mat imageXY8UC;
    if(!image.data)
    {
        return -1;
    }
    GaussianBlur(image,image,Size(3,3),0); //��˹�˲��������
    uchar *P=image.data;
    uchar *PX=imageX.data;
    uchar *PY=imageY.data;
    int step=image.step;
    int stepXY=imageX.step;
    for(int i=1;i<image.rows-1;i++)
    {
        for(int j=1;j<image.cols-1;j++)
        {			//ͨ��ָ�����ͼ����ÿһ������
            PX[i*imageX.step+j*(stepXY/step)]=abs(P[(i-1)*step+j+1]+P[i*step+j+1]*2+P[(i+1)*step+j+1]-P[(i-1)*step+j-1]-P[i*step+j-1]*2-P[(i+1)*step+j-1]);
            PY[i*imageX.step+j*(stepXY/step)]=abs(P[(i+1)*step+j-1]+P[(i+1)*step+j]*2+P[(i+1)*step+j+1]-P[(i-1)*step+j-1]-P[(i-1)*step+j]*2-P[(i-1)*step+j+1]);
        }
    }
    addWeighted(imageX,0.5,imageY,0.5,0,imageXY);//�ں�X��Y����
    convertScaleAbs(imageX,imageX8UC);
    convertScaleAbs(imageY,imageY8UC);
    convertScaleAbs(imageXY,imageXY8UC);   //ת��Ϊ8bitͼ��

    Mat imageSobelx;
    Mat imageSobely;
    Mat imageSobel;
    Sobel(image,imageSobelx,CV_8UC1,1,0); //Opencv��Sobel����
    Sobel(image,imageSobely,CV_8UC1,0,1);
    imageSobel = imageSobelx | imageSobely;
    imageSobely.release();
    threshold(imageSobel,imageSobel,0,255,CV_THRESH_OTSU);

    namedWindow("Source Image",CV_WINDOW_NORMAL);
    imshow("Source Image",image);
    namedWindow("X Direction",CV_WINDOW_NORMAL);
    imshow("X Direction",imageX8UC);
    namedWindow("Y Direction",CV_WINDOW_NORMAL);
    imshow("Y Direction",imageY8UC);
    namedWindow("XY Direction",CV_WINDOW_NORMAL);
    imshow("XY Direction",imageXY8UC);
    namedWindow("Opencv Soble",CV_WINDOW_NORMAL);
    imshow("Opencv Soble",imageSobel);
    waitKey();

    return 0;
}

