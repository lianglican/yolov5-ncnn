/********************************************************
  File name: qctype.h
  Author:LiangLiCan
  Date: 2020/05/18
  Description: 定义旗云通用数据类型
********************************************************/
#ifndef _QC_TYPE_H_
#define _QC_TYPE_H_

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif // end of __cplusplus

#ifndef NULL
#define NULL				0L
#endif

#define QC_SUCCESS			0
#define QC_FAILURE			(-1)

typedef unsigned char           QC_U8;
typedef unsigned short          QC_U16;
typedef unsigned int            QC_U32;
typedef unsigned long           QC_ULONG;
typedef unsigned long long      QC_U64;

typedef  char                    QC_C8;
typedef  unsigned char           QC_S8;
typedef  short                   QC_S16;
typedef  int                     QC_S32;
typedef  long                    QC_SLONG;
typedef  long long               QC_S64;

typedef float                   QC_FLOAT;
typedef double                  QC_DOUBLE;
typedef void                    QC_VOID;

// c语言中虽然有布尔值这个概念，但没bool关键字
// 为了提高移植性，统一用枚举替代bool
typedef enum 
{
    QC_FALSE    = 0,
    QC_TRUE     = 1,
} QC_BOOL;

#ifndef NULL
#define NULL				0L
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif // __cplusplus

#endif // _QC_TYPE_H_