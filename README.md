# SENZ016-HC-05-Bluetooth-Module-Master-Slave

###### Translation

> For `English`, please click [`here.`](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/README.md)

> For `Chinese`, please click [`here.`](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/README_CN.md)

![](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/pic/SENZ016_Front.jpg "SENZ016_Front")
![](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/pic/SENZ016_Back.jpg "SENZ016_Back")


### Introduction


> SENZ016 HC-05 Bluetooth Module combines the Master and Slave mode. It takes the main stream chip in CSR, and can connect with bluetooth laptop, smart phone, and other bluetooth equipment.

### Specification

- Operating Voltage: +3.3V ~ 5V
- Weight: 3.5g
- LED for connecting status:
	- fast blink: no bluetooth connect
	- slow blink: AT command mode
- Working current: 
	- connected: ~10mA
	- not connected: ~30mA
- Effective transmission distance: 10 meters in free space
- Master/Slave mode alter: AT mode, or pressing the button
- Default setting:
	- Baud rate: 9600 Bd/s
	- Password: 1234
	- Name: HC-05

### Tutorial

#### Pin Definition

|Sensor pin|Ardunio Pin|Function Description|
|-|:-:|-|
|VCC|+3.6~6V|Power shouldn't be higher than 7V|
|GND|GND||
|EN|H/L|H:Enable signal for AT mode|
|RXD|TX||
|TXD|RX||
|STATE|-|Output "H/L" digital level, Connected is "H", Unconnected is "L"|


![](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/pic/SENZ016_pin.jpg "Pin Definition") 

#### Connecting Diagram

![](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/pic/SENZ016_connect.png "Connecting Diagram") 


#### Sample Code

> Use the Arduino as the software serial in AT mode

	/***************
	
	HC-05 pin connection:
		TXD->10, RXD->11, VCC->+5V, GND->GND, EN NC, STATE NC

	AT mode:
		Step1: shut down the power of HC-05;
		Step2: keep pressing the black button;
		Step3: power the HC-05 and check the red LED. It's OK if blinks at 1HZ;

	****************/

	#include <SoftwareSerial.h>
	SoftwareSerial BT(10,11);    //define pin10 as RX, pin11 as TX; 

	void setup() {
	  Serial.begin(38400);
	  Serial.println("hd");
	  BT.begin(38400);
	}

	void loop() {
	  // put your main code here, to run repeatedly:
	  if (Serial.available()){
	    BT.write(Serial.read());
	  }
	  if (BT.available()){
	    Serial.write(BT.read());
	  }
	}



### Purchasing [*SENZ016-HC-05-Bluetooth-Module-Master-Slave*](https://www.ebay.com/).
