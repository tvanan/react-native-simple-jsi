#include <jni.h>
#include <sys/types.h>
#include "example.h"
#include "pthread.h"


using namespace facebook::jsi;
using namespace std;

// JavaVM *java_vm;
// jclass java_class;
// jobject java_object;

// extern "C"
// JNIEXPORT jint JNICALL
// Java_com_reactnativesimplejsi_SimpleJsiModule_nativeMultiply(JNIEnv *env, jclass type, jint a, jint b) {
//     return example::multiply(a, b);
// }


//extern "C"
//JNIEXPORT void JNICALL
//Java_com_reactnativesimplejsi_SimpleJsiModule_nativeInstall(JNIEnv *env, jobject thiz, jlong jsi) {
//    // TODO: implement nativeInstall()
//
//auto runtime = reinterpret_cast<facebook::jsi::Runtime *>(jsi);
//
//
//    if (runtime) {
//        example::install(*runtime);
//        // install(*runtime);
//    }
//
// env->GetJavaVM(&java_vm);
//    java_object = env->NewGlobalRef(thiz);
//}


extern "C"
JNIEXPORT void JNICALL
Java_com_reactnativesimplejsi_SimpleJsiModule_nativeInstall(JNIEnv *env, jobject thiz, jlong jsi) {
    // TODO: implement nativeInstall()

    auto runtime = reinterpret_cast<facebook::jsi::Runtime *>(jsi);


    if (runtime) {
        example::install(*runtime);
        // install(*runtime);
    }

    // env->GetJavaVM(&java_vm);
    // java_object = env->NewGlobalRef(thiz);
}
