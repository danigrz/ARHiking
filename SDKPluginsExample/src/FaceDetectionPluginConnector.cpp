//
//  FaceDetectionPluginConnector.cpp
//  Native Examples
//
//  Created by Andreas Schacherbauer on 05/08/15.
//  Copyright (c) 2015 Wikitude. All rights reserved.
//

#include "FaceDetectionPluginConnector.h"
#include "jniHelper.h"

jobject activityObj;

extern "C" JNIEXPORT void JNICALL
Java_com_wikitude_samples_FaceDetectionPluginActivity_initNative(JNIEnv* env, jobject obj, jstring databasePath_)
{
    activityObj = env->NewGlobalRef(obj);
    FaceDetectionPlugin::_databasePath = env->GetStringUTFChars(databasePath_,NULL);
}

extern "C" JNIEXPORT void JNICALL
Java_com_wikitude_samples_FaceDetectionPluginActivity_setFlipFlag(JNIEnv* env, jobject obj, jint flag)
{
	FaceDetectionPlugin::instance->setFlipFlag((int) flag);
}

FaceDetectionPluginConnector::FaceDetectionPluginConnector()
{
}

FaceDetectionPluginConnector::~FaceDetectionPluginConnector()
{
	JavaVMResource vm(pluginJavaVM);
	vm.env->DeleteGlobalRef(activityObj);
}

void FaceDetectionPluginConnector::faceDetected(const float *modelViewMatrix)
{
    JavaVMResource vm(pluginJavaVM);
    jclass clazz = vm.env->FindClass("com/wikitude/samples/FaceDetectionPluginActivity");
    _faceDetectedId = vm.env->GetMethodID(clazz, "onFaceDetected", "([F)V");
    jfloatArray jModelViewMatrix = vm.env->NewFloatArray(16);
    vm.env->SetFloatArrayRegion(jModelViewMatrix, 0, 16, modelViewMatrix);
    vm.env->CallVoidMethod(activityObj, _faceDetectedId, jModelViewMatrix);
}

void FaceDetectionPluginConnector::faceLost()
{
    JavaVMResource vm(pluginJavaVM);
    jclass clazz = vm.env->FindClass("com/wikitude/samples/FaceDetectionPluginActivity");
    _faceLostId = vm.env->GetMethodID(clazz, "onFaceLost", "()V");
    vm.env->CallVoidMethod(activityObj, _faceLostId);
}

void FaceDetectionPluginConnector::projectionMatrixChanged(const float *projectionMatrix)
{
    JavaVMResource vm(pluginJavaVM);
    jclass clazz = vm.env->FindClass("com/wikitude/samples/FaceDetectionPluginActivity");
    _projectionMatrixChangedId = vm.env->GetMethodID(clazz, "onProjectionMatrixChanged", "([F)V");
    jfloatArray jProjectionMatrix = vm.env->NewFloatArray(16);
    vm.env->SetFloatArrayRegion(jProjectionMatrix, 0, 16, projectionMatrix);
    vm.env->CallVoidMethod(activityObj, _projectionMatrixChangedId, jProjectionMatrix);
}

void FaceDetectionPluginConnector::renderDetectedFaceAugmentation() {
    JavaVMResource vm(pluginJavaVM);
    jclass clazz = vm.env->FindClass("com/wikitude/samples/FaceDetectionPluginActivity");
    _renderDetectedFaceAugmentation = vm.env->GetMethodID(clazz, "renderDetectedFaceAugmentation", "()V");
    vm.env->CallVoidMethod(activityObj, _renderDetectedFaceAugmentation);
}

