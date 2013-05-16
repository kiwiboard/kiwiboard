# 
#   KiwiBoard demos
#
#  (c)KiwiBoard.org
#

############################################################
############################################################
LOCAL_PATH := $(call my-dir)

############################################################
############################################################
include $(CLEAR_VARS)

LOCAL_MODULE    := libkiwiboard_lib
LOCAL_SRC_FILES := ..\obj\local\armeabi\libkiwiboard_lib.a

include $(PREBUILT_STATIC_LIBRARY)
############################################################
############################################################

include $(CLEAR_VARS)
LOCAL_MODULE := kiwiboard_amei
LOCAL_STATIC_LIBRARIES := libkiwiboard_lib
LOCAL_LDLIBS := -llog 
LOCAL_SRC_FILES := \
	kiwiboard_amei.cpp\

include $(BUILD_EXECUTABLE)


############################################################
############################################################

include $(CLEAR_VARS)
LOCAL_MODULE := kiwiboard_blink
LOCAL_STATIC_LIBRARIES := libkiwiboard_lib
LOCAL_LDLIBS := -llog 
LOCAL_SRC_FILES := \
	kiwiboard_blink.cpp\

include $(BUILD_EXECUTABLE)

############################################################
############################################################

include $(CLEAR_VARS)
LOCAL_MODULE := kiwiboard_gpio_test
LOCAL_STATIC_LIBRARIES := libkiwiboard_lib
LOCAL_LDLIBS := -llog 
LOCAL_SRC_FILES := \
	kiwiboard_gpio_test.cpp\

include $(BUILD_EXECUTABLE)


############################################################
############################################################

include $(CLEAR_VARS)
LOCAL_MODULE := kiwiboard_servo
LOCAL_STATIC_LIBRARIES := libkiwiboard_lib
LOCAL_LDLIBS := -llog 
LOCAL_SRC_FILES := \
	kiwiboard_servo.cpp\

include $(BUILD_EXECUTABLE)


############################################################
############################################################

include $(CLEAR_VARS)
LOCAL_MODULE := kiwiboard_ft
LOCAL_STATIC_LIBRARIES := libkiwiboard_lib
LOCAL_LDLIBS := -llog 
LOCAL_SRC_FILES := \
	kiwiboard_ft.cpp\

include $(BUILD_EXECUTABLE)