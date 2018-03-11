#include <string.h>
#include <jni.h>
#include <android/log.h>
#include "com_smallest_test_hellojni_MainActivity.h"
#include "FFmpeger.h"
#include <stdio.h>

JNIEXPORT jstring JNICALL Java_com_smallest_test_hellojni_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz)
{
	char info[60000] = {0};
	FFmpeger::avformat_info(info);
	__android_log_print(ANDROID_LOG_INFO,"myTag","avformatInfo:\n%s", info);
	char info2[60000] = {0};
	FFmpeger::avcodec_info(info2);
	__android_log_print(ANDROID_LOG_INFO,"myTag","avcodecInfo:\n%s", info2);
	char info3[60000] = {0};
	FFmpeger::avfilter_info(info3);
	__android_log_print(ANDROID_LOG_INFO,"myTag","avfilterInfo:\n%s", info3);
	char info4[60000] = {0};
	FFmpeger::avcodec_config(info4);
	__android_log_print(ANDROID_LOG_INFO,"myTag","avcodecConfiguration:\n%s", info4);
	char infoTotal[300000] = {0};
	sprintf(infoTotal, "avformatInfo:\n%s avcodecInfo:\n%s avfilterInfo:\n%s avcodecConfiguration:\n%s", info, info2, info3, info4);
	return (*env).NewStringUTF(infoTotal);
}
