/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <string.h>
#include <jni.h>
#include <android/log.h>
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavfilter/avfilter.h"
#include "com_smallest_test_hellojni_MainActivity.h"

/* This is a trivial JNI example where we use a native method
 * to return a new VM String. See the corresponding Java source
 * file located at:
 *
 *   apps/samples/hello-jni/project/src/com/example/hellojni/HelloJni.java
 */
JNIEXPORT jstring JNICALL Java_com_smallest_test_hellojni_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz)
{
#if defined(__arm__)
  #if defined(__ARM_ARCH_7A__)
    #if defined(__ARM_NEON__)
      #define ABI "armeabi-v7a/NEON"
    #else
      #define ABI "armeabi-v7a"
    #endif
  #else
   #define ABI "armeabi"
  #endif
#elif defined(__i386__)
   #define ABI "x86"
#elif defined(__mips__)
   #define ABI "mips"
#else
   #define ABI "unknown"
#endif
    char info[40000] = {0};
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
__android_log_print(ANDROID_LOG_INFO,"myTag","info:\n%s",info);
    return (*env)->NewStringUTF(env, "Hello from JNI !  Compiled with ABI " ABI ".");
}
