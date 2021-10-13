/******************************************************************************
  Copyright (C), 2020-2099, Zhuhai QCWlink Co., Ltd.
 ******************************************************************************
  File Name     : qccommondatatype.h
  Description   : 通用数据结构类型定义
  Author        : LiangLiCan
  Created       : 2020/7/15
  History       :
1.Date          :
  Author        :
  Modification  :
******************************************************************************/

#ifndef _QCCOMMONDATATYPE_H_
#define _QCCOMMONDATATYPE_H_
#include "qctype.h"

#define MAX_PATH_LEN 128
#define MAX_NAME_LENS 16

#define EDGE_ALIGN(x, align)  ((((x)-1)/(align)+1)*(align))

/// 数组大小
#define ARRY_SIZE(A) (sizeof(A)/sizeof(A[0]))

#ifndef QC_MIN
#define QC_MIN(x, y) ((x) < (y) ? (x) : (y))
#endif
#ifndef QC_MAX
#define QC_MAX(x, y) ((x) > (y) ? (x) : (y))
#endif

/***********************************************************
    判断年月日的合法性，注意年月日时分秒都是unsigned char
    类型的
************************************************************/
#define VALID_YEAR(year) (year <= 99)
#define VALID_MONTH(month) ((month >= 1) && (month <= 12))
#define VALID_DAY(day) ((day >= 1) && (day <= 31))
#define VALID_HOUR(hour) (hour <= 23)
#define VALID_MINUTE(minute) (minute <= 59)
#define VALID_SECOND(second) (second <= 59)

typedef enum _OSS_TYPE_E
{
	OSS_ALIBABA, // 阿里云
	OSS_HUAWEI,  // 华为云
	OSS_BAIDU, 	 // 百度云
	OSS_YIDONG,  // 移动
    OSS_DROPBOX, //
    OSS_NGINX, // 存储本地，可通过nginx配置访问路径
    OSS_BUTT
}OSS_TYPE_E;

typedef enum _STREAM_TYPE_E
{
	ST_BIGSTREAM 	= 0,		/* 大码流 */
	ST_SMALLSTREAM 	= 1,		/* 小码流 */
	ST_MOBILESTREAM = 2,		/* 手机码流 */
	ST_BUTT,
}STREAM_TYPE_E;

/*制式*/
typedef enum _tvsystem_
{	
    TS_PAL, 	/* PAL  */
    TS_NTSC,   	/* NTSC */
    TS_INVALID
}TV_SYSTEM_E;

// 视频格式
typedef enum _QC_VIDEO_FORMAT_E_
{
    QC_VIDEO_TYPE_H264,
    QC_VIDEO_TYPE_AVI,
    QC_VIDEO_TYPE_MP4,
    QC_VIDEO_TYPE_BUTT
}QC_VIDEO_TYPE_E;

/* 星期 */
typedef enum _WEEK_
{
    WK_SUNDAY,
    WK_MONDAY,
    WK_TUESDAY,
    WK_WEDNESDAY,
    WK_THURSDAY,
    WK_FRIDAY,
    WK_SATURDAY
}WEEK_E;

// 串口设备索引
typedef enum _SERIAL_DEV_E
{
	SD_CTRL_BOARD, 		// 控制板
	SD_NET_MODULE,	// EC20网络模块
	SD_BUTT,
}SERIAL_DEV_E;
/* 串口波特率定义 */
typedef enum _BAUD_RATE_E
{
    BR_1200,
    BR_2400, // 1
    BR_4800,
    BR_9600,
    BR_14400,
    BR_19200, // 5
    BR_38400,
    BR_57600,
    BR_115200,
    BR_230400,
    BR_380400, // 10
    BR_460800,
    BR_921600,
    BR_BUTT,
}BAUD_RATE_E;

typedef enum _FrameBufferGraph_
{
	HIFB_HD0 = 0,
	HIFB_HD1 = 1,
	HIFB_SD0 = 2,
	HIFB_SD1 = 3,
	HIFB_MAX = 4
}HIFBGraph_e;

typedef enum _LAYER_E
{
	LAYER_G4 = 0,    // 图形层
	LAYER_HC0 = 1,   // 鼠标层
	LAYER_HC1 = 2,   // 鼠标层
}LAYER_E;


/* 分辨率模式，目前只用来标识D1 、960 */
typedef enum _RESOLUTION_MODE_E
{	
	RESOLUTION_MODE_D1 = 0,
	RESOLUTION_MODE_960H = 1,
}RESOLUTION_MODE_E;

typedef enum _FRAME_TYPE_E
{
    FT_IFRAME,
    FT_PFRAME,
    FT_AFRAME,
    FT_ALLFRAME,
    FT_VIR_IFRAME,
    FT_INVALID
}FRAME_TYPE_E;

typedef enum _DATE_FMT_E
{
    DATE_FMT_BIAS_MDY,  /* 08/21/2007，即月日年 */
    DATE_FMT_LINE_YMD,  /* 2007-08-21，即年月日 */
    DATE_FMT_BIAS_DMY,  /* 21/08/2007，即日月年 */
    DATE_FMT_BUTT,
}DATE_FMT_E;

/* 24,12AM/PM 小时格式 */
typedef enum _TIME_MODE_E
{
    TIME_MODE_24_HHMMSS,    /* 时分秒*/
    TIME_MODE_12_HHMMSS,    /* 12 小时制 时分秒*/
    TIME_MODE_24_HHMM,      /* 时分*/
    TIME_MODE_12_HHMM,      /* 12 小时制 时分*/
    TIME_MODE_BUTT,
}TIME_MODE_E;

/***************************************************
    图片类型
 **************************************************/
typedef enum _PICTURE_TYPE_E
{
    QC_PT_BITMAP,
    QC_PT_GIF,
	QC_PT_PNG,
    QC_PT_UNKNOWN
}PICTURE_TYPE_E;

typedef enum _MEDIA_WND_DEV_E
{
	MEDIA_WND_DEV_HDMI,
	MEDIA_WND_DEV_VGA,
 	MEDIA_WND_DEV_VOUT,
 	MEDIA_WND_DEV_VSPOT,
 	MEDIA_WND_DEV_BUTT
}MEDIA_WND_DEV_E;

/*分屏模式*/
typedef enum _OUTPUT_MODE_E
{
	OM_ONE,
	OM_FOUR,
//	OM_EIGHT,
	OM_NINE,
	OM_TEN_5X5,
	OM_TEN_4X4,
	OM_THIRTEEN_5X5,
	OM_THIRTEEN_4X4,
	OM_FOURTEEN,
	OM_SIXTEEN,
	OM_PIP,		/* 1+1画中画*/
	OM_PIP2,	/* 1+2画中画*/
	OM_ZOOMIN,	/* 电子放大*/
	OM_BUTT,
    OM_INVALID,
}OUTPUT_MODE_E;

typedef enum _INIT_DEV_E
{
	INIT_VOUT,
	INIT_VGA,
	INIT_HDMI,
	INIT_AUTO,
	INIT_INVALID,
}INIT_DEV_E;

typedef struct _QC_POINT_S
{
    QC_S32 x;
    QC_S32 y;
}QC_POINT_S;

typedef struct _QC_SIZE_S
{
    QC_S32 w;
    QC_S32 h;
}QC_SIZE_S;

/* 日期 */
typedef struct _QC_TIME_S
{
    QC_U16 year; 	// 1970~20xx
    QC_U8 month; 	// 1~12
    QC_U8 day; 		// 1~31
    QC_U8 hour; 	// 0~23
    QC_U8 minute; 	// 0~59
    QC_U8 second; 	// 0~59
    QC_U16 msec; 	// 0~999
    QC_U8 reserved[3];
}QC_TIME_S;

typedef struct _QC_RECT_S
{
    QC_S32 x;
    QC_S32 y;
    QC_S32 w;
    QC_S32 h;
}QC_RECT_S;

/* 新增一个分数类型，可用在因整除除不尽带来的误差太大时表示结果 */
typedef struct _QC_FRACTION_S
{
    QC_S32 num;  // 分子
    QC_S32 den;  // 分母
}QC_FRACTION_S;

typedef struct _FRAME_INFO_S
{
    QC_U64 pts;
    QC_S32 FrameLen;
    FRAME_TYPE_E enType;
}FRAME_INFO_S;

/* 分辨率模式 */
typedef enum _RES_MODE_E_
{
    SUPPORT_D1,
    SUPPORT_960H,
    SUPPORT_720P,
    SUPPORT_1080P,
    SUPPORT_3W,
    SUPPORT_4W,
    SUPPORT_5W,
}RES_MODE_E;

/* 分辨率 */
typedef enum _RESOLUTION_E
{
	RES_QCIF,	/*176x144*/
	RES_CIF,	/*352x288*/
	RES_2CIF,	/*352x576*/
	RES_HD1,	/*704x288*/
	RES_D1,		/*704x576*/

	RES_WQCIF,	/*236x144*/
	RES_WCIF,	/*464x288*/
	RES_W2CIF,	/*464x576*/
	RES_WHD1,	/*928x288*/
	RES_WD1,	/*928x576  由960变成928解决有黑边问题*/

	RES_QVGA,    /* 320 * 240 */
	RES_VGA,     /* 640 * 480 */    
	RES_XGA,     /* 1024 * 768 */   
	RES_SXGA,    /* 1400 * 1050 */    
	RES_UXGA,    /* 1600 * 1200 */    
	RES_QXGA,    /* 2048 * 1536 */

	RES_WVGA,    /* 854 * 480 */
	RES_WSXGA,   /* 1680 * 1050 */      
	RES_WUXGA,   /* 1920 * 1200 */
	RES_WQXGA,   /* 2560 * 1600 */

	RES_HD720P,   /* 1280 * 720 */
	RES_HD1080P,  /* 1920 * 1080 */
	RES_HD1080P_CIF,/* 960*1080 */
	RES_FULL_WD1, 	/* 960x576 */

	RES_3M, 		/* 1920*1536*/
    RES_5M,         /* 2592*1944*/
	RES_HD720P_CIF, /* 640 * 720 */
	RES_4M,         /* 2560*1440*/
	RES_LOREX_SNAP, /* 320*180*/
	RES_432X320, 	/* 432*320*/
	RES_8M,      	/* 3840*2160*/
	RES_640X360, 	/* 640*360*/
	RES_5M_HALF,	/* 1280*1944*/
	RES_4M_HALF,	/* 1280*1440*/
	RES_3M_HALF,	/* 1024*1536*/
	RES_BUTT
}RESOLUTION_E;

const QC_SIZE_S TABLE_PAL_GET_SIZE_BY_RES[RES_BUTT] = 
{
	{176, 144}, //RES_QCIF,
	{352, 288}, //RES_CIF,
	{352, 576}, //RES_2CIF,
	{704, 288}, //RES_HD1,
	{704, 576}, //RES_D1,

	{236, 144}, //RES_WQCIF,
	{464, 288}, //RES_WCIF,
	{464, 576}, //RES_W2CIF,
	{928, 288},	//RES_WHD1,
	{928, 576}, //RES_WD1,   由960变成928解决有黑边问题

	{320,  240}, //RES_QVGA
	{640,  480}, //RES_VGA
	{1024, 768}, //RES_XGA
	{1400, 1050}, //RES_SXGA
	{1600, 1200}, //RES_UXGA
	{2048, 1536}, //RES_QXGA

	{854,  480}, //RES_WVGA
	{1680, 1050}, //RES_WSXGA
	{1920, 1200}, //RES_WUXGA
	{2560, 1600}, //RES_WQXGA

	{1280, 720}, //RES_HD720P
	{1920, 1080}, //RES_HD1080P	
	{960,  1080}, //RES_HD1080P_CIF
	{960,  576}, //RES_FULL_WD1
	{1920, 1536}, //RES_3M
	{2560, 1944}, //RES_5M
	{640,  720}, //RES_HD720P_CIF
	{2560, 1440}, //RES_4M 
	{320,  180}, //RES_LOREX_SNAP 
	{432,  320}, //RES_432X320 
	{3840, 2160}, //RES_8M
	{640,  360}, //RES_640X360
	{1280, 1944},//RES_5M_HALF
	{1280, 1440},//RES_4M_HALF
	{1024, 1536},//RES_3M_HALF
};

const QC_SIZE_S TABLE_NTSC_GET_SIZE_BY_RES[RES_BUTT] = 
{
	{176, 120}, //RES_QCIF,
	{352, 240}, //RES_CIF,
	{352, 480}, //RES_2CIF,
	{704, 240}, //RES_HD1,
	{704, 480}, //RES_D1,

	{236, 120}, //RES_WQCIF,
	{464, 240}, //RES_WCIF,
	{464, 480}, //RES_W2CIF,
	{928, 240}, //RES_WHD1,
	{928, 480}, //RES_WD1, 由960变成928解决有黑边问题

	{320,  240}, //RES_QVGA
	{640,  480}, //RES_VGA
	{1024, 768}, //RES_XGA
	{1400, 1050}, //RES_SXGA
	{1600, 1200}, //RES_UXGA
	{2048, 1536}, //RES_QXGA

	{854,  480}, //RES_WVGA
	{1680, 1050}, //RES_WSXGA
	{1920, 1200}, //RES_WUXGA
	{2560, 1600}, //RES_WQXGA

	{1280, 720}, //RES_HD720P
	{1920, 1080}, //RES_HD1080P	
	{960,  1080}, //RES_HD1080P_CIF
	{960,  480}, //RES_FULL_WD1
	{1920, 1536}, //RES_3M
	{2560, 1944}, //RES_5M
	{640,  720}, //RES_HD720P_CIF
	{2560, 1440}, //RES_4M 
	{320,  180}, //RES_LOREX_SNAP 
	{432,  320}, //RES_432X320
	{3840, 2160}, //RES_8M
	{640,  360}, //RES_640X360
	{1280, 1944},//RES_5M_HALF
	{1280, 1440},//RES_4M_HALF
	{1024, 1536},//RES_3M_HALF
};

const QC_SIZE_S UI_TABLE_PAL_GET_SIZE_BY_RES[RES_BUTT] =
{
	{704,  576}, //RES_D1,
	{704,  288}, //RES_HD1,
	{352,  288}, //RES_CIF,
	{1280, 720}, //RES_HD720P
	{176,  144}, //RES_QCIF,
	
	{352, 576}, //RES_2CIF,
	{236, 144}, //RES_WQCIF,
	{464, 288}, //RES_WCIF,
	{464, 576}, //RES_W2CIF,
	{928, 288},	//RES_WHD1,
	
	{960,  576}, //RES_WD1,   由960变成928解决有黑边问题
	{320,  240}, //RES_QVGA
	{640,  480}, //RES_VGA
	{1024, 768}, //RES_XGA
	{1400, 1050}, //RES_SXGA
	
	{1600, 1200}, //RES_UXGA
	{2048, 1536}, //RES_QXGA
	{854,  480}, //RES_WVGA
	{1680, 1050}, //RES_WSXGA
	{1920, 1200}, //RES_WUXGA
	
	{2560, 1600}, //RES_WQXGA
	{1920, 1080}, //RES_HD1080P	
	{960,  1080}, //RES_HD1080P_CIF   由956变成944，，解决IE端回放有白边的问题
	{960,  576}, //RES_FULL_WD1
	{1920, 1536}, //RES_3M
	{2560, 1944}, //RES_5M
	{640,  720}, //RES_HD720P_CIF
	{2560, 1440}, //RES_4M 
	{320,  180}, //RES_LOREX_SNAP 
	{432,  320}, //RES_432X320
	{3840, 2160}, //RES_8M
	{640,  360}, //RES_640X360
	{1280, 1944},//RES_5M_HALF
	{1280, 1440},//RES_4M_HALF
	{1024, 1536},//RES_3M_HALF
};

const QC_SIZE_S UI_TABLE_NTSC_GET_SIZE_BY_RES[RES_BUTT] = 
{
	{704,  480}, //RES_D1,
	{704,  240}, //RES_HD1,
	{352,  240}, //RES_CIF,
	{1280, 720}, //RES_HD720P
	{176,  120}, //RES_QCIF,

	{352, 480}, //RES_2CIF,
	{236, 120}, //RES_WQCIF,
	{464, 240}, //RES_WCIF,
	{464, 480}, //RES_W2CIF,
	{928, 240}, //RES_WHD1,
	
	{960,  480}, //RES_WD1, 由960变成928解决有黑边问题
	{320,  240}, //RES_QVGA
	{640,  480}, //RES_VGA
	{1024, 768}, //RES_XGA
	{1400, 1050}, //RES_SXGA
	
	{1600, 1200}, //RES_UXGA
	{2048, 1536}, //RES_QXGA
	{854,  480}, //RES_WVGA
	{1680, 1050}, //RES_WSXGA
	{1920, 1200}, //RES_WUXGA
	
	{2560, 1600}, //RES_WQXGA
	{1920, 1080}, //RES_HD1080P	
	{960,  1080}, //RES_HD1080P_CIF
	{960,  480}, //RES_FULL_WD1
	{1920, 1536}, //RES_3M
	{2560, 1944}, //RES_5M
	{640,  720}, //RES_HD720P_CIF
	{2560, 1440}, //RES_4M 
	{320,  180}, //RES_LOREX_SNAP 
	{432,  320}, //RES_432X320 
	{3840, 2160}, //RES_8M
	{640,  360}, //RES_640X360
	{1280, 1944},//RES_5M_HALF
	{1280, 1440},//RES_4M_HALF
	{1024, 1536},//RES_3M_HALF
};

/*
frame struct:
--------------------------------------------------------------------------------------------------------------------------
| frameType | frameNo | frameLen | ChnNo | ReSend | CmdMainType | CmdSubType | RetStatus | CmdLen |CmdData | LRC | endFlag|
-------------------------------------------------------------------------------------------------------------------------
*/
#define BGS_FRAME_EXTRA_LEN     9    	/* 后台服务器不包含数据帧内命令内容长度,frameType + frameNo + frameLen + LRC + 0x40 */
#define BGS_FRAME_CHNNO_TO_DATA_LEN  10 /* 后台服务器通道号到命令数据的长度，ChnNo---CmdLen */

#define FRAME_END_FLAG      0x40   // 数据帧结束标识
#define MSG_MAX_DATA_LEN    1024

#define FRAME_TYPE_REQUEST  0x1 // 请求帧 接收方需回应
#define FRAME_TYPE_RESPONSE 0x2 // 响应帧 接收方无需回应

// 命令执行状态
typedef enum _CMD_RET_STATUS_E
{
    CMD_RET_SUCCESS           = 0x00000000, 
    CMD_RET_FRAME_FORMAT_ERR  = 0x00000001,  // 数据帧格式解析出错
    CMD_RET_CMD_NONEXIST      = 0x00000002,  // 命令不存在
    CMD_RET_DATA_PARSE_ERR    = 0x00000003,  // 命令数据解析出错
    CMD_RET_EXECUTE_FAIL      = 0x00000004,  // 命令执行失败
    CMD_RET_UNKNOWN_ERR       = 0x00009999,  // 未知错误
	CMD_RET_UPGRADE_UNSTART   = 0xFF002C00,  // 升级--没有激活下载
	CMD_RET_UPGRADE_UNKNOW    = 0xFF002C01,  // 升级--非升级命令
	CMD_RET_UPGRADE_JUMP_FRAME    	= 0xFF002C02,  // 升级--跳帧
    CMD_RET_UPGRADE_SEND_TOO_LONG	= 0xFF002C03,  // 升级--接收数据超过总长度
	CMD_RET_UPGRADE_WRITE_ERR    	= 0xFF002C04,  // 升级--单片机侧写Flash错误
	CMD_RET_UPGRADE_FRAME_LACK   	= 0xFF002C05,  // 升级--结束升级时文件没有下载完
	CMD_RET_UPGRADE_CRC_ERR    		= 0xFF002C08,  // 升级--结束升级时CRC校验不通过
}CMD_RET_STATUS_E;

// 帧内容的索引
typedef enum _BGS_FRAME_INDEX_E // frame index
{
    BFI_FRAME_TYPE = 0,     /* 数据帧类型 */
    BFI_FRAME_NO   = 1,     /* 数据帧号 */
    BFI_FRAME_LEN  = 5,     /* 数据帧内命令内容长度,从“通道号”到“命令数据”的字节数 */
    BFI_CHN_NO     = 7,     /* 通道号:0x00 */
    BFI_RESEND     = 8,     /* 是否重发 */
    BFI_CMD_MAIN_TYPE = 9,  /* 命令类型 */
    BFI_CMD_SUB_TYPE  = 10,  /* 命令 */
    BFI_RET_STATUS    = 11,  /* 执行返回状态值 */
    BFI_CMD_DATA_LEN  = 15, /* 命令数据长度 */
    BFI_CMD_DATA      = 17, /* 命令数据 */
   	BFI_BUTT
}BGS_FRAME_INDEX_E;

typedef struct _MSG_HEAD_S_
{
    QC_U8  u8FrameType;      /* 数据帧类型 */
    QC_U8  au8FrameNo[4];    /* 数据帧号 */
    QC_U8  au8FrameLen[2];   /* 数据帧内命令内容长度,从“通道号”到“命令数据”的字节数 */
    QC_U8  u8ChnNo;          /* 通道号:0x00 */
    QC_U8  u8IsReSend;       /* 是否重发 */
    QC_U8  u8CmdMainType;    /* 命令类型 */
    QC_U8  u8CmdSubType;     /* 命令 */
    QC_U8  au8RetStatus[4];  /* 执行返回状态值 */
    QC_U8  au8CmdLen[2];     /* 命令数据长度 */
}MSG_HEAD_S;

// 设备要素ID
typedef enum _ELEMENT_ID_E_
{
	EI_WIND_SPEED 				= 0x00, /* 风速 */
	EI_WIND_DIRECTION 			= 0x01, /* 风向 */
	EI_ATMOSPHERIC_TEMPERATURE 	= 0x02, /* 大气温度 */
	EI_ATMOSPHERIC_HUMIDITY 	= 0x03, /* 大气湿度 */
	EI_ATMOSPHERIC_PRESSURE 	= 0x04, /* 大气气压 */
	EI_RAINFALL 				= 0x05, /* 降雨量 */
	EI_SNOWFALL 				= 0x06, /* 降雪量 */
	EI_EVAPORATION 				= 0x07, /* 蒸发量 */
	EI_ILLUMINANCE 				= 0x08, /* 光照度 */
	EI_TOTAL_RADIATION 			= 0x09, /* 总辐射 */
	EI_PHOTOSYNTHESIS_ACTIVERADIATION = 0x0A, /* 光合有效辐射 */
	EI_ULTRAVIOLET_RADIATION 	= 0x0B, /* 紫外辐射 */
	EI_OXYGEN_CONTENT 			= 0x0C, /* 氧气含量 */
	EI_NEGATIVE_OXYGENIONS 		= 0x0D, /* 负氧离子 */
	EI_CO_CONTENT 				= 0x0E, /* CO含量 */
	EI_CO2_CONTENT 				= 0x0F, /* CO2含量 */
	EI_PM25 					= 0x10, /* PM2.5 */
	EI_PM10 					= 0x11, /* PM10 */
	EI_AMMONIA_CONTENT 			= 0x12, /* 氨气含量 */
	EI_FORMALDEHYDE_CONTENT 	= 0x13, /* 甲醛含量 */
	EI_SOIL_TEMPERATURE 		= 0x14, /* 土壤温度 */
	EI_SOIL_HUMIDITY 			= 0x15, /* 土壤湿度 */
	EI_SOIL_PH 					= 0x16, /* 土壤PH值 */
	EI_SOIL_SALINITY_EC 		= 0x17, /* 土壤盐分电导率 */
	EI_WATER_TEMP 				= 0x18, /* 水温 */
	EI_WATER_PH 				= 0x19, /* 水PH值 */
	EI_WATER_EC 				= 0x1A, /* 水质EC */
	EI_NOISE 					= 0x1B, /* 噪声 */
	EI_LEAF_TEMPERATURE 		= 0x1C, /* 叶片温度 */
	EI_LEAF_HUMIDITY 			= 0x1D, /* 叶片湿度 */
	EI_VIDEO 					= 0x1E, /* 摄像头视频 */
	EI_DUAL_CAMERA_IMAGE 		= 0x1F, /* 双摄像头图片 */
	EI_DUAL_CAMERA_VIDEO 		= 0x20, /* 双摄像头视频 */
	EI_DISSOLVED_OXYGEN 		= 0x21, /* 溶解氧(DO) */
	EI_AMMONIA_NITROGEN 		= 0x22, /* 氨氮 */
	EI_CHEMICAL_OXYGEN_DEMAND 	= 0x23, /* 化学需氧量(COD) */
	EI_TRANSPARENCY 			= 0x24, /* 透明度 */
	EI_REDOX_POTENTIAL 			= 0x25, /* 氧化还原电位（ORP） */
	EI_WATER_LEVEL 				= 0x26, /* 水位 */
	EI_TURBIDITY 				= 0x27, /* 浊度  */
	EI_TOTAL_PHOSPHORUS 		= 0x28, /* 总磷 */
	EI_TOTAL_TRIAXIAL_ANGLE 	= 0x29, /* 三轴倾角 */
	EI_TOTAL_RAIN_SNOW 			= 0x2A, /* 雨雪 */
	EI_BUTT
}ELEMENT_ID;

typedef enum _SENSOR_STATUS_E_
{
	QCSTATUS_DISCONNECT 	= 0x0, 			/* 未连接/未扫描 */ 
	QCSTATUS_OK 			= 0x1, 			/* 正常 */ 
	QCSTATUS_OBSOLESCENT 	= 0x2, 			/* 停用 */ 
	QCSTATUS_TEST_TIMEOUT 	= 0x3,			/* 化验超时 */ 
	QCSTATUS_ERROR 			= 0x4, 			/* 故障/抽不上水 */ 
	QCSTATUS_NO_SENSOR 		= 0x5,			/* 找不到水位传感器 */ 
	QCSTATUS_WATER_LEVEL_TOO_LOWER = 0x6,	/* 水位太低(水位距离大于限定值) */ 
	QCSTATUS_WATER_BOX_FULL = 0x7,			/* 水箱水满 */ 
	QCSTATUS_DEV_FALL 		= 0x8,			/* 设备倾倒 */ 	
	QCSTATUS_RIVER_WATER_LEVER_OK = 0x9,	/* 河渠水到位 */ 	
	QCSTATUS_RIVER_WATER_LEVER_NG = 0xA,	/* 河渠水不到位 */ 	
	QCSTATUS_BUTT,
}SENSOR_STATUS_E;

#endif/* _QCCOMMONDATATYPE_H_ */

