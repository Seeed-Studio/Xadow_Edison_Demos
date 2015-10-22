Edison-Pedometer
---------------------------------------------------------
###Hardware Required

* Intel® Edison x 1
* Xadow – Edison x 1
* Xadow – Edison – Programmer x 1
* Xadow - OLED 0.96" x 1
* Xadow - 3-Axis Accelerometer x 1
* Xadow – Buzzer x 1

###Instructions

1. Using the FPC Cables, make the following connections.

![image] (https://github.com/Seeed-Studio/Xadow_Edison_Demos/blob/master/Edison_Pedometer_with_OLED/pic/Pedometer_1.png)

Note: When connecting Xadow-OLED/Xadow-3-Axis Accelerometer/Xadow-Buzzer to Xadow-Edison, you should make sure the connection direction is correct. The unfilled corner of one Xadow module needs to connect to the right angle of another module(refer to the 4 corners of each Xadow module).

2. Connect the UART and Device/Host port on Xadow-Edison-Programmer to PC USB port
3. Download the library from Github
4. Open the Arduino IDE. Click Tools > Board and select Intel® Edison
5. Click Tools > Serial Port and select the Com # that the Intel Edison is connected to
6. Click Sketch > Import Library… > Add Library and import the library downloaded in step 3
7. Click File > Examples > Edison_Pedometer_with_OLED and select the demo
8. Change the char ssid[] = STEST with your network name
9. Change the char pass[] = 876543210 with your network password
10. Click upload icon
11. Shake Xadow-3-Axis Accelerometer, you will see the pedometer count update.

Once the pedometer connects to the WiFi network, on a device connected on the same network, open a web browser and go to the IP address displayed on the OLED or Serial Monitor, you can see the step counts.

You can also apply a LiPo Battery to Xadow-Edison(as follows) and make a case to wear the device on your body. Enjoy!

![image] (https://github.com/Seeed-Studio/Xadow_Edison_Demos/blob/master/Edison_Pedometer_with_OLED/pic/Pedometer_2.png)
