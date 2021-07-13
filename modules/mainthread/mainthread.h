/******************************************************************************
  Copyright (C), 2020-2099, Zhuhai QCWlink Co., Ltd.
 ******************************************************************************
  File Name     : mainthread.h
  Description   : 系统主线程
  Author        : LiangLiCan
  Created       : 2021/7/20
  History       :
1.Date          :
  Author        :
  Modification  :
******************************************************************************/
#ifndef _MAIN_THREAD_H_
#define _MAIN_THREAD_H_

class  CMainThread
{
public:
    ~CMainThread();
    static CMainThread* Instance();
    int initSystem();
    void mainThread();

private:
    CMainThread();

private:
    static CMainThread *m_pSelf;

};





#endif // _MAIN_THREAD_H_