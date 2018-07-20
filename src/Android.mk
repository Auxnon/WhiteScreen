LOCAL_PATH := $(call my-dir)
LOCAL_CPPFLAGS := -O2 -Werror -Wall
include $(CLEAR_VARS)

SDL_PATH := ../SDL

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include

# Add your application source files here...
LOCAL_MODULE := main
LOCAL_SRC_FILES := main.cpp Entity.cpp

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
