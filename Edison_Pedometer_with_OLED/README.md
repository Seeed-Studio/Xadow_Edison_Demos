Edison-Pedometer
---------------------------------------------------------
###Hardware

Intel® Edison *1 <br>
Xadow – Edison *1 <br>
Xadow – Edison – Programmer *1 <br>
Xadow - OLED 0.96" *1 <br>
Xadow - 3-Axis Accelerometer *1 <br>
Xadow – Buzzer *1 <br>

###Instructions

1.Using the FPC Cables, making the following connections. <br>

![image] (https://github.com/Seeed-Studio/Xadow_Edison_Demos/blob/master/Edison_Pedometer_with_OLED/pic/Pedometer_1.png)

Note: when connect Xadow-OLED/Xadow-3-Axis Accelerometer/Xadow-Buzzer to Xadow-Edison, you should concern about the connection direction. The connection method is that the unfilled corner of one xadow module need to connect to the right angle of another module(see four corners of each xadow module).

2.Connect the UART and Device/Host port on Xadow-Edison-Programmer to PC USB port <br>
3.Download the library from github <br>
4.Open Arduino IDE. Click Tools > Board and select Intel® Edison <br>
5.Click Tools > Serial Port and select the Com # that the Intel Edison is connected to <br>
6.Click Sketch>Import Library…>Add Library and import the library downloaded at step 3 <br>
7.Click File>Examples>Edison_Pedometer_with_OLED and select the demo <br>
8.Change the char ssid[] = STEST with your network name <br>
9.Change the char pass[] = 876543210 with your network password <br>
10.Click upload icon <br>
11.Shake Xadow-3-Axis Accelerometer ,you will see the pedometer counts. <br>

When the pedometer connects WiFi network, On a device connected on the same network, open a web browser, and go to the IP address displayed on the OLED or Serial Monitor, you can see the step counts.
You can also apply a LiPo Battery to Xadow-Edison(as follows), and make a case to wear the devices on your body.Enjoy it! <br>

![image] (https://github.com/Seeed-Studio/Xadow_Edison_Demos/blob/master/Edison_Pedometer_with_OLED/pic/Pedometer_2.png)