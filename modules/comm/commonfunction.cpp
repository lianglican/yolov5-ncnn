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


void mSleep(int  MilliSecond)
{
    struct timeval time;

    time.tv_sec = MilliSecond / 1000;           // seconds
    time.tv_usec = MilliSecond * 1000 % 1000000;// microsecond

    select(0, NULL, NULL, NULL, &time);
}