#ifndef _YOLO_V5_DECTECTOR_H_
#define _YOLO_V5_DECTECTOR_H_

#include "layer.h"
#include <vector>
#include "net.h"

struct Object
{
    cv::Rect_<float> rect;
    int label;
    float prob;
};

struct YoloSize{    //定义结构体YoloSize
    int width;
    int height;
};

struct YoloLayerData{       //定义结构体YoloLayerData
    std::string outName;    //构造一个默认为空的string name，使用标准函数库中的函数或对象需要使用std进行限定，即这里
    int stride;             //调用的是std中的string，防止自己定义的类与标准库中的函数冲突
    std::vector<YoloSize> anchors; 
};

class CYolov5Detector 
{
public:
    CYolov5Detector(const char *param, const char* bin);
    ~CYolov5Detector();

    int detect(const cv::Mat& bgr, std::vector<Object>& objects);
    int drawObjects(const cv::Mat& bgr, std::vector<Object>& objects);

private:
    inline float sigmoid(float x);
    inline float intersectionArea(const Object& a, const Object& b);
    void nmsSortedBboxes(const std::vector<Object>& faceobjects, std::vector<int>& picked, float nms_threshold);
    void qsortDescentInplace(std::vector<Object>& faceobjects);
    void qsortDescentInplace(std::vector<Object>& faceobjects, int left, int right);
    void generateProposals(const ncnn::Mat& anchors, int stride, const ncnn::Mat& in_pad, 
                            const ncnn::Mat& feat_blob, float prob_threshold, std::vector<Object>& objects);

private:
    const char *m_pParamPath;
    const char *m_pBinPath;
    ncnn::Net m_Yolov5Net;

public:
    // anchor setting from yolov5/models/yolov5s.yaml
    std::vector<YoloLayerData> m_vLayers
    {
        {"output", 8,  {{10,13}, {16,30},  {33,23}}},
        {"427",    16, {{30,61}, {62,45},  {59,119}}},
        {"452",    32, {{116,90},{156,198},{373,326}}},
    };

    std::vector<std::string> m_sClassNames{
        "person", "bicycle", "car", "motorcycle", "airplane", "bus", "train", "truck", "boat", "traffic light",
        "fire hydrant", "stop sign", "parking meter", "bench", "bird", "cat", "dog", "horse", "sheep", "cow",
        "elephant", "bear", "zebra", "giraffe", "backpack", "umbrella", "handbag", "tie", "suitcase", "frisbee",
        "skis", "snowboard", "sports ball", "kite", "baseball bat", "baseball glove", "skateboard", "surfboard",
        "tennis racket", "bottle", "wine glass", "cup", "fork", "knife", "spoon", "bowl", "banana", "apple",
        "sandwich", "orange", "broccoli", "carrot", "hot dog", "pizza", "donut", "cake", "chair", "couch",
        "potted plant", "bed", "dining table", "toilet", "tv", "laptop", "mouse", "remote", "keyboard", "cell phone",
        "microwave", "oven", "toaster", "sink", "refrigerator", "book", "clock", "vase", "scissors", "teddy bear",
        "hair drier", "toothbrush"
    };

    enum LABEL_E
    {
        person,     /* 人 */  
        bicycle,    /* 自行车 */ 
        car,        /* 汽车 */
        motorcycle, /* 摩托车 */
        airplane,   /* 飞机 */
        bus,        /* 公共汽车 */
        train,      /* 火车 */
        truck,      /* 卡车 */
        boat,       /* 船 */
        traffic_light,  /* 红绿灯 */
        fire_hydrant,   /* 消防栓 */
        stop_sign,      /* 停车标志 */
        parking_meter,  /* 停车收费码表 */
        bench,      /* 长椅 */
        bird,       /* 鸟 */
        cat,        /* 猫 */
        dog,        /* 狗 */
        horse,      /* 马 */
        sheep,      /* 羊 */
        cow,        /* 奶牛 */
        elephant,   /* 象 */
        bear,       /* 熊 */
        zebra,      /* 斑马 */
        giraffe,    /* 长颈鹿 */
        backpack,   /* 双肩包 */
        umbrella,   /* 雨伞 */
        handbag,    /* 手提包 */
        tie,        /* 领带 */
        suitcase,   /* 行李箱 */
        frisbee,    /* 飞盘 */
        skis,       /* 滑雪板(双脚) */
        snowboard,  /* 滑雪板 */
        sports_ball,/* 体育馆 */
        kite,       /* 风筝 */
        baseball_bat,   /* 棒球棒 */
        baseball_glove, /* 棒球手套 */
        skateboard,     /* 溜冰板 */
        surfboard,      /* 冲浪板 */
        tennis_racket,  /* 网球拍 */
        bottle,         /* 瓶子 */
        wine_glass,     /* 酒杯 */
        cup,            /* 杯子 */
        fork,           /* 叉子 */
        knife,          /* 刀 */
        spoon,          /* 勺子 */
        bowl,           /* 碗 */
        banana,         /* 香蕉 */
        apple,          /* 苹果 */
        sandwich,       /* 三明治 */
        orange,         /* 橙 */
        broccoli,       /* 西兰花 */
        carrot,         /* 胡萝卜 */
        hot_dog,        /* 热狗 */
        pizza,          /* 比萨 */
        donut,          /* 炸面圈 */
        cake,           /* 蛋糕 */
        chair,          /* 椅子 */
        couch,          /* 睡椅 */
        potted_plant,   /* 盆栽 */
        bed,            /* 床 */
        dining_table,   /* 餐桌 */
        toilet,     /* 马桶 */
        tv,         /* 电视 */
        laptop,     /* 笔记本电脑 */
        mouse,      /* 鼠标 */
        remote,    
        keyboard,   /* 键盘 */
        cell_phone, /* 手机 */
        microwave,  /* 微波炉 */
        oven,       /* 烤箱 */
        toaster,    /* 烤箱 */
        sink,       /* 洗涤槽 */
        refrigerator,/* 冰箱 */
        book,       /* 书 */
        clock,      /* 时钟 */
        vase,       /* 花瓶 */
        scissors,   /* 剪刀 */
        teddy_bear, /* 泰迪熊 */
        hair_drier, /* 吹风机 */
        toothbrush, /* 牙刷 */
    };

};

class YoloV5Focus : public ncnn::Layer
{
public:
    YoloV5Focus()
    {
        one_blob_only = true;
    }

    virtual int forward(const ncnn::Mat& bottom_blob, ncnn::Mat& top_blob, const ncnn::Option& opt) const
    {
        int w = bottom_blob.w;
        int h = bottom_blob.h;
        int channels = bottom_blob.c;

        int outw = w / 2;
        int outh = h / 2;
        int outc = channels * 4;

        top_blob.create(outw, outh, outc, 4u, 1, opt.blob_allocator);
        if (top_blob.empty())
            return -100;

        #pragma omp parallel for num_threads(opt.num_threads)
        for (int p = 0; p < outc; p++)
        {
            const float* ptr = bottom_blob.channel(p % channels).row((p / channels) % 2) + ((p / channels) / 2);
            float* outptr = top_blob.channel(p);

            for (int i = 0; i < outh; i++)
            {
                for (int j = 0; j < outw; j++)
                {
                    *outptr = *ptr;

                    outptr += 1;
                    ptr += 2;
                }

                ptr += w;
            }
        }
        return 0;
    }
};

ncnn::Layer *YoloV5Focus_layer_creator(void *);

// DEFINE_LAYER_CREATOR(YoloV5Focus)

#endif // _YOLOV5_DECTECTOR_H_