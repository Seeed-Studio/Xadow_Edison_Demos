Seeed QTouch
-------------------------------------------------------------
![image](http://www.seeedstudio.com/depot/images/product/Grove-Q%20Touch%20Sensor.jpg)

LED Bar, common in volume display, is a common sensor component to display analog value. You can use a row of discrete LED lights to make division of this effect, you can also use our element mentioned here. 

For more information, please refer to [Grove_LED_Bar][1]

#Usage

1. To judge certain key if touched


		unsigned char isTouch(int key)		// key- 0~6, if touched return 1
2. Get touch state
   
   	bits 0 to 6 indicate which keys are in detection, if any. Touched keys report as 1, untouched or disabled
    keys report as 0.

		unsigned char getState()			// will 

3. Get Touch Num

		int touchNum();

	if no touched, return -1. or will return the touched key number.

----
This software is written by Loovee for seeed studio<br>
and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>



[1]:http://www.seeedstudio.com/wiki/LED_Bar



[![Analytics](https://ga-beacon.appspot.com/UA-46589105-3/Grove_LED_Bar)](https://github.com/igrigorik/ga-beacon)
