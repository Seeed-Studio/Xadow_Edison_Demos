Edison-Pedometer
Hardware
Intel® Edison *1
Xadow – Edison *1
Xadow – Edison – Programmer *1
Xadow - OLED 0.96" *1
Xadow - 3-Axis Accelerometer *1
Xadow – Buzzer *1
Instructions
1.Using the FPC Cables, making the following connections.
![image] (https://github.com/Seeed-Studio/Xadow_Edison_Demos/blob/master/Edison_Pedometer_with_OLED/pic/Pedometer_1.png)

Note: when connect Xadow-OLED/Xadow-3-Axis Accelerometer/Xadow-Buzzer to Xadow-Edison, you should concern about the connection direction. The connection method is that the unfilled corner of one xadow module need to connect to the right angle of another module(see four corners of each xadow module).

2.Connect the UART and Device/Host port on Xadow-Edison-Programmer to PC USB port
3.Download the library from github
4.Open Arduino IDE. Click Tools > Board and select Intel® Edison
5.Click Tools > Serial Port and select the Com # that the Intel Edison is connected to
6.Click Sketch>Import Library…>Add Library and import the library downloaded at step 3
7.Click File>Examples>Edison_Pedometer_with_OLED and select the demo
8.Change the char ssid[] = STEST with your network name
9.Change the char pass[] = 876543210 with your network password
10.Click upload icon
11.Shake Xadow-3-Axis Accelerometer ,you will see the pedometer counts.

When the pedometer connects WiFi network, On a device connected on the same network, open a web browser, and go to the IP address displayed on the OLED or Serial Monitor, you can see the step counts.
You can also apply a LiPo Battery to Xadow-Edison(as follows), and make a case to wear the devices on your body.Enjoy it!
![image] (https://github.com/Seeed-Studio/Xadow_Edison_Demos/blob/master/Edison_Pedometer_with_OLED/pic/Pedometer_2.png)