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

void CMainThread::mainThread()
{
    printf("main thread.....\n");
    // const char* imagepath = argv[1];
    // cv::Mat m = cv::imread(imagepath);
    const char* imagepath = "./_20210521154052.jpg";
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

    CYolov5Detector CYolov5("/home/llc/work/pig/cproject/modules/yolov5/yolov5s.param", 
                            "/home/llc/work/pig/cproject/modules/yolov5/yolov5s.bin");
    CYolov5.detect(m, objects);
    CYolov5.drawObjects(m, objects);    
    while (1)
    {
        mSleep(100);
    }
}