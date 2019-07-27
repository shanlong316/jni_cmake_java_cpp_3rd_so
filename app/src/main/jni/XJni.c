//
// Created by Administrator on 2019/7/27.
//
#include <jni.h>
#include <stdio.h>
#include <malloc.h>

#include <android/log.h>
#include "voiceInterface.h"


const char * LOG_TGA = "shanlong";

JNIEXPORT jstring JNICALL
Java_com_example_administrator_myapplication_XJni_getStr(JNIEnv *env, jobject instance,
                                                         jstring s_) {
    const char *s = (*env)->GetStringUTFChars(env, s_, 0);

    // TODO

    (*env)->ReleaseStringUTFChars(env, s_, s);

    char *buffer = (char *)malloc(1024 * 2 * 12); //保存12路音频
    short *output = (short *)malloc(1024 * sizeof(short)); //保存处理之后的数据
    FILE *fp = fopen("afteralsa.pcm","rb");
    FILE *out = fopen("out.pcm","wb");
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TGA, "hell 11111111111");

    int length = 0;
    VoiceHandle voiceHandle;//上下文
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TGA, "hello native log");
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TGA, "voiceInit start");
    voiceInit(&voiceHandle);//初始化
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TGA, "voiceInit done");

    while ((length = fread(buffer,1,1024 * 24,fp)) >= 1024 * 24) {
        printf("length = %d\n",length);
        __android_log_print(ANDROID_LOG_DEBUG, LOG_TGA, "length = %d",length);

        /*
            处理
            参数1：上下文
            参数2：输入的12路音频，每次传入1024个点，总共12 * 1024 * 2 个字节
            参数3：处理完之后的音频数据，1024个点，1024 * 2个字节
            返回值为方向值
        */

        __android_log_print(ANDROID_LOG_DEBUG, LOG_TGA, "voiceProcessContainPreparation start");

        int doa = voiceProcessContainPreparation(voiceHandle,buffer,output);
        printf("doa = %d\n",doa);
        __android_log_print(ANDROID_LOG_DEBUG, LOG_TGA, "doa = %d",doa);

        fwrite(output,2048,1,out);
    }
    fclose(fp);
    fclose(out);
    /*
        销毁资源
    */
    voiceDestroy(voiceHandle);


    char *returnValue = "12345622222";



    return (*env)->NewStringUTF(env, returnValue);
}