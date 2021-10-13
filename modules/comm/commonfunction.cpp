/******************************************************************************
  Copyright (C), 2020-2099, Zhuhai QCWlink Co., Ltd.
 ******************************************************************************
  File Name     : commonfunction.cpp
  Description   : 公共函数定义
  Author        : LiangLiCan
  Created       : 2021/7/16
  History       : 
1.Date          :
  Author        :
  Modification  :
******************************************************************************/
#include <time.h>
#include <sys/types.h>
#include "commonfunction.h"
#include <sys/timeb.h>

void mSleep(int  MilliSecond)
{
    struct timeval time;

    time.tv_sec = MilliSecond / 1000;           // seconds
    time.tv_usec = MilliSecond * 1000 % 1000000;// microsecond

    select(0, NULL, NULL, NULL, &time);
}


/*******************************************
* Function Name : getSysDataTime
* Parameter     : 
* Description   : 获取时间存入 dataTime
* RETURN VALUE	：
* Author        : LiangLiCan
* Created       :
********************************************/
QC_S32 getSysDataTime(QC_TIME_S &dataTime)
{
    //struct timeval stRealTime;
    struct tm stTmpTime;
    struct timeb curTime;
    ftime(&curTime);

    //if (gettimeofday(&stRealTime, NULL) == QC_SUCCESS) // 获取格林威治时间
    {
        localtime_r(&curTime.time, &stTmpTime); // 获取系统时间
        dataTime.year   = stTmpTime.tm_year + 1900;
        dataTime.month  = stTmpTime.tm_mon + 1;
        dataTime.day    = stTmpTime.tm_mday;
        dataTime.hour   = stTmpTime.tm_hour;
        dataTime.minute = stTmpTime.tm_min;
        dataTime.second = stTmpTime.tm_sec;
        dataTime.msec   = curTime.millitm;
        return QC_SUCCESS;
    }
    return QC_FAILURE;
}