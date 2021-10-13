/******************************************************************************
  Copyright (C), 2020-2099, Zhuhai QCWlink Co., Ltd.
 ******************************************************************************
  File Name     : mainthread.cpp
  Description   : 系统主线程
  Author        : LiangLiCan
  Created       : 2021/7/20
  History       :
1.Date          :
  Author        :
  Modification  :
******************************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "mainthread.h"
#include "commonfunction.h"
#include "yolov5detector.h"

CMainThread *CMainThread::m_pSelf = NULL;

CMainThread *CMainThread::Instance()
{
    if(NULL == m_pSelf)
    {
        m_pSelf = new CMainThread();
    }
    return m_pSelf;
}

CMainThread:: CMainThread()
{

}

CMainThread::~CMainThread()
{

}

int CMainThread::initSystem()
{
    printf("Init System Done!\n");
    return 0;
}

bool bOverlap(const cv::Rect& box1, const cv::Rect& box2)
{
	cv::Rect tmp = box1 & box2;
	return tmp.area();
}

void CMainThread::mainThread()
{
#if 0
    printf("main thread.....\n");
    // const char* imagepath = argv[1];
    // cv::Mat m = cv::imread(imagepath);
    const char* imagepath = "./20210612103154.jpg";
    uint64_t content_length = 0;
    struct stat statbuf;
    if (stat(imagepath, &statbuf) == -1)
    {
        printf("ERROR: Failed to stat file %s: ",imagepath);
//            perror(0);
           exit(-1);
    }
    content_length = statbuf.st_size;
    printf("buf size =%lu", content_length);

    unsigned char fileBuff[content_length];
    memset(fileBuff, 0, content_length);

    FILE *fp = fopen(imagepath, "rb");
    if (!fp)
    {
        printf("ERROR: fopen Failed ");
        exit(-1);
    }

    fread(fileBuff, 1, content_length, fp);

    fclose(fp);

    // vector<char> data(buffer, buffer + sizeof(buffer));
    std::vector<unsigned char> vBuff(fileBuff, fileBuff + sizeof(fileBuff));
    cv::Mat m = cv::imdecode(vBuff, CV_LOAD_IMAGE_COLOR);
    if (m.empty())
    {
        printf("cv::imdecode  failed\n");
        return ;
    }
    std::vector<Object> objects;

    CYolov5Detector CYolov5("/home/llc/work/pig/yolov5-ncnn/modules/yolov5/yolov5s.param", 
                            "/home/llc/work/pig/yolov5-ncnn/modules/yolov5/yolov5s.bin");
    CYolov5.detect(m, objects);
    CYolov5.drawObjects(m, objects);  
  
    while (1)
    {
        mSleep(100);
    }
#else
    CYolov5Detector CYolov5("/home/llc/work/pig/yolov5-ncnn/modules/yolov5/last.param", 
                            "/home/llc/work/pig/yolov5-ncnn/modules/yolov5/last.bin");

    // cv::VideoCapture cap("./WeChat_20210926113607.mp4"); // boat
    cv::VideoCapture cap("./WeChat_20210926114326.mp4"); // person
    
    if (!cap.isOpened())  
    {  
        return ;  
    }  
    int s32FrameNum = 0;
    cv::Mat frame;
    QC_BOOL bNeedDet = QC_TRUE;

    double fps=30;//每秒的帧数
    char file_out[]="recorded.avi";
    cv::VideoWriter recVid(file_out, cv::VideoWriter::fourcc('M','J','P','G'), fps, cv::Size(1280, 720));
    if (!recVid.isOpened())
    {
        printf("Error! Video file not opened...\n");
        return ;
    }

    while (1)  
    {  
        cap >> frame;  
        if (frame.empty())
            continue;
        
        ++s32FrameNum;
        std::vector<Object> objects;

        if(bNeedDet){
            CYolov5.detect(frame, objects);
        }

        // 画线
        // cv::line(frame, cv::Point(0, frame.rows/3*2), cv::Point(frame.cols, frame.rows/3*2), cv::Scalar(0, 0, 0xFF), 4);

        // if(objects.size() == 0){
        //     bNeedDet = QC_FALSE;
        // }
        // else
        // {
        //     // 判断是否越界
        //     if(!bOverlap(cv::Rect(0, frame.rows/3*2, frame.cols, frame.rows - frame.rows/3*2),
        //                  cv::Rect(objects.at(0).rect.x, objects.at(0).rect.y, objects.at(0).rect.width, objects.at(0).rect.height)))
        //     {
        //         bNeedDet = QC_FALSE;
        //         objects.clear();
        //     }

        // }


        CYolov5.drawObjects(frame, objects);  
    // // 保存图片
    // if(s32FrameNum == 60)
    // {
    //     cv::imwrite("./picture1.jpg", frame);
    // }
    // else if(s32FrameNum == 200)
    // {
    //     cv::imwrite("./picture2.jpg", frame);
    // }

        // 保存视频
        recVid << frame;
        // 一秒钟检测一帧
        if (s32FrameNum%25 == 0){
            bNeedDet = QC_TRUE;
        }
        // cv::imshow("当前视频", frame);  
        cv::waitKey(30);
    } 
#endif
}

