# The ARMv7 is significanly faster due to the use of the hardware FPU
APP_ABI := armeabi armeabi-v7a x86 mips
APP_ABI := all
APP_PLATFORM := android-8
#APP_STL := stlport_static
APP_STL := stlport_shared
APP_MODULES:=ezThread
