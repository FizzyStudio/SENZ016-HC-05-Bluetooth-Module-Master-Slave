# SENZ016-HC-05-Bluetooth-Module-Master-Slave

###### Translation

> For `English`, please click [`here.`](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/README.md)

> For `Chinese`, please click [`here.`](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/README_CN.md)

![](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/pic/SENZ016.jpg "SENZ016")


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

#### Wire Definition

|Sensor pin|Ardunio Pin|Function Description|
|-|:-:|-|
|VCC|+3.3~5V|Power|
|GND|GND||
|VO|-|Adjust the contrast ratio|
|RS(CS)|H/L|Parallel Mode: RS="H",  data signal, RS="L",  command signal; Serial Mode: CS: chip signal|
|R/W(SID)|H/L|Parallel Mode: R/W="H", write data, R/W="L", read data; Serial Mode: SID: data interface|
|E(CLK)|H/L|Parallel Mode: Enable signal; Serial Mode: clock signal|
|DB0~DB7|H/L|Data0-7|
|PSB|H/L|PSB="H", Parallel Mode; PSB="L", Serial Mode|
|NC|-||
|RST|H/L|RST="L", Reset|
|VOUT|-||
|BLA|-|Back LED anode, +5V|
|BLK|-|Back LED kathode, 0V|


![](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/pic/SENZ016_pin.jpg "Pin Definition") 

#### Connecting Diagram

![](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/pic/SENZ016_connect.png "Connecting Diagram") 


#### Sample Code


	//Set Bluetooth AT mode by Arduino
	#define EN 2
	#define LED 13
	void setup()
	{
	       pinMode(LED,OUTPUT);
	       pinMode(EN,OUTPUT);
	       digitalWrite(EN,HIGH);
	       Serial.begin(38400);//here the number should be concident with your module's communication Baud rate
	       delay(100);
	       Serial.println("AT");
	       delay(100);
	       Serial.println("AT+NAME=OPENJUMPER-Bluetooth");//Rename the module
	       delay(100);
	       Serial.println("AT+ROLE=0");//Set the Master/Slave mode, 0-Slave, 1-Master
	       delay(100);
	       Serial.println("AT+PSWD=1234");//Set the password such as 1234
	       delay(100);
	       Serial.println("AT+UART=9600,0,0");//Set Baud rate as 9600, 1 stop bit, 0 check bit
	       delay(100);
	       Serial.println("AT+RMAAD");//Clear the connect list
	}
	void loop()
	{
	       digitalWrite(LED, HIGH);
	       delay(500);
	       digitalWrite(LED, LOW);
	       delay(500);
	}


### Purchasing [*SENZ016-HC-05-Bluetooth-Module-Master-Slave*](https://www.ebay.com/).
