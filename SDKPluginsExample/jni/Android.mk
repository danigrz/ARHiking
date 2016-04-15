LOCAL_PATH := $(call my-dir)/..
LOCAL_PATH_SAVE := $(LOCAL_PATH)
SRC_DIR := $(LOCAL_PATH)/src
LIB_DIR := $(LOCAL_PATH)/lib
OPENCV_PATH := $(LOCAL_PATH)/OpenCV-android-sdk/sdk/native/jni

include $(CLEAR_VARS)

LOCAL_PATH := $(LIB_DIR)/$(TARGET_ARCH_ABI)
include $(CLEAR_VARS)
LOCAL_MODULE    := iconv
LOCAL_SRC_FILES := libiconv.a    
include $(PREBUILT_STATIC_LIBRARY)

LOCAL_PATH := $(LIB_DIR)/$(TARGET_ARCH_ABI)
include $(CLEAR_VARS)
LOCAL_MODULE    := zbar
LOCAL_SRC_FILES := libzbar.a    
include $(PREBUILT_STATIC_LIBRARY)

LOCAL_PATH := $(SRC_DIR)
include $(CLEAR_VARS)

OPENCV_LIB_TYPE:=STATIC

include $(OPENCV_PATH)/OpenCV.mk

LOCAL_MODULE := wikitudePlugins

LOCAL_C_INCLUDES := $(SRC_DIR)/include \
	$(OPENCV_PATH)/include \
	$(OPENCV_PATH)/include/opencv2 \
	$(OPENCV_PATH)/include/opencv2/core \
	$(OPENCV_PATH)/include/opencv2/imgproc \
	$(OPENCV_PATH)/include/opencv2/objdetect \
	$(SRC_DIR)/include/zbar \


LOCAL_SRC_FILES := BarcodePlugin.cpp FaceDetectionPlugin.cpp FaceDetectionPluginConnector.cpp JniRegistration.cpp Plugin.cpp Frame.cpp RecognizedTarget.cpp jniHelper.cpp

LOCAL_STATIC_LIBRARIES += zbar iconv  
LOCAL_LDLIBS += -llog

include $(BUILD_SHARED_LIBRARY)
