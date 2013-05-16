
adb push libs\armeabi\kiwiboard_blink /system/bin
adb shell chmod 755 /system/bin/kiwiboard_blink
adb shell /system/bin/kiwiboard_blink
