/******************************************************************************
  Copyright (C), 2020-2099, Zhuhai QCWlink Co., Ltd.
 ******************************************************************************
  File Name     : main.cpp
  Description   : 系统主线程
  Author        : LiangLiCan
  Created       : 2021/7/20
  History       :
1.Date          :
  Author        :
  Modification  :
******************************************************************************/
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "mainthread.h"

int main()
{
	printf("main thread pid=%d \n", getpid());
    
    /* 捕获SIGPIPE信号 */
    signal(SIGPIPE, SIG_IGN);

    CMainThread *pCMainThr = CMainThread::Instance();

	/* 对系统进行初始化 */
    pCMainThr->initSystem();

	/* 开启主线程 */
    pCMainThr->mainThread();

    return 0;
}