
adb push libs\armeabi\kiwiboard_gpio_test /system/bin
adb shell chmod 755 /system/bin/kiwiboard_gpio_test
adb shell /system/bin/kiwiboard_gpio_test
