# [WORK IN PROGRESS] Example Yaw-Pitch-Role app

# DISCLAIMER: This example is currently not working at all 

This example requires the IMUduino_Bluetooth_UART_YawPitchRoll sketch to be loaded on your IMUduino board. Open up the Arduino Serial Monitor to start the board's routines.

This Ionic Project uses the `com.evothings.ble` cordova plugin:
```
ionic plugin add com.evothings.ble
```

To run this project on an Android device (with Bluetooth 4.0 capabilities), use a terminal to run the following from within 
the `bleYawPitchRoll/` directory:

```
# This should only need to be run once
ionic platform add android
```

...Then, deploy to your Android device (Note: requires USB debugging)

```
ionic run android
```