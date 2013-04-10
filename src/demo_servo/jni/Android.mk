# 
#   A simple test with NDK
#
#  (c)KiwiBoard.org
#


LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := kiwiboard_servo
LOCAL_LDLIBS := -llog 
LOCAL_LDFLAGS += $(LOCAL_PATH)\kiwiboard_lib.o
LOCAL_SRC_FILES := \
	kiwiboard_arduino.cpp

include $(BUILD_EXECUTABLE)
