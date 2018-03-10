//
// Created by gavinxu on 2018/3/10.
//
#ifndef HELLOJNI_FFMPEGER_H
#define HELLOJNI_FFMPEGER_H
class FFmpeger {
public:
    /**
    * FFmpeg类库支持的封装格式
    */
    static void avformat_info(char *);

    /**
    * FFmpeg类库支持的编解码器
    */
    static void avcodec_info(char *);

    /**
    * FFmpeg类库支持的滤镜
    */
    static void avfilter_info(char *);

    /**
    * FFmpeg类库的配置信息
    */
    static void avcodec_config(char *);
};
#endif //HELLOJNI_FFMPEGER_H
