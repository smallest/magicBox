#include "FFmpeger.h"
extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavfilter/avfilter.h"
}


void FFmpeger::avformat_info(char *info) {
    av_register_all();
    AVInputFormat *avInputFormat = av_iformat_next(NULL);
    AVOutputFormat *avOutputFormat = av_oformat_next(NULL);
    while(avInputFormat != NULL) {
    	sprintf(info, "%s[In ][%10s]\n", info, avInputFormat->name);
    	avInputFormat = avInputFormat->next;
    }
    while(avOutputFormat != NULL) {
    	sprintf(info, "%s[Out][%10s]\n", info, avOutputFormat->name);
    	avOutputFormat = avOutputFormat->next;
    }
}

void FFmpeger::avcodec_info(char *info) {
    av_register_all();
    AVCodec *c_temp = av_codec_next(NULL);
    while(c_temp != NULL){
       if(c_temp->decode!=NULL){
          sprintf(info,"%s[Dec]",info);
       }else{
          sprintf(info,"%s[Enc]",info);
       }
       switch(c_temp->type){
        case AVMEDIA_TYPE_VIDEO:
          sprintf(info,"%s[Video]",info);
          break;
        case AVMEDIA_TYPE_AUDIO:
          sprintf(info,"%s[Audio]",info);
          break;
        default:
          sprintf(info,"%s[Other]",info);
          break;
       }
       sprintf(info,"%s[%10s]\n",info,c_temp->name);
       c_temp=c_temp->next;
    }
}

void FFmpeger::avfilter_info(char *info) {
	avfilter_register_all();
	AVFilter *avFilter = (AVFilter *) avfilter_next(NULL);
	while (avFilter != NULL) {
		sprintf(info, "%s[%10s]\n", info, avFilter->name);
		avFilter = avFilter->next;
	}
}

void FFmpeger::avcodec_config(char *info) {
	av_register_all();
	sprintf(info, "%s[%10s]\n", avcodec_configuration());
}


