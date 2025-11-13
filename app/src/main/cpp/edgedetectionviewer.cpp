#include <jni.h>
#include <android/log.h>

#define LOG_TAG "NativeFrame"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C"
JNIEXPORT void JNICALL
Java_com_example_edgedetectionviewer_MainActivity_processFrame(
        JNIEnv *env,
        jobject thiz,
        jbyteArray frameData,
        jint width,
        jint height) {

    // Convert Java byte[] to C++ jbyte*
    jbyte *data = env->GetByteArrayElements(frameData, nullptr);
    jsize length = env->GetArrayLength(frameData);

    // For now, we just print a log to confirm JNI is working
    LOGI("Received frame in C++ | size = %d bytes | width = %d | height = %d",
         length, width, height);

    // Release the byte array
    env->ReleaseByteArrayElements(frameData, data, JNI_ABORT);
}
