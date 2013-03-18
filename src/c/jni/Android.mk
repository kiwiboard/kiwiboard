# 
#   A simple test with NDK
#
#  (c)KiwiBoard.org
#


LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := kiwiboard
LOCAL_LDLIBS := -llog
LOCAL_LDFLAGS += $(LOCAL_PATH)\kiwiboard_lib.o
LOCAL_SRC_FILES := \
	kiwiboard_main.c

include $(BUILD_EXECUTABLE)
