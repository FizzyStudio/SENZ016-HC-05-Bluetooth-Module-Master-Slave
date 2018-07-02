# SENZ016 HC-05 主从一体蓝牙模块

###### 翻译

> `英文` 请参考 [`这里`](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/README.md)

> `中文` 请参考 [`这里`](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/README_CN.md)

![](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/pic/SENZ016——Front.jpg "SENZ016_Front")
![](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/pic/SENZ016——Back.jpg "SENZ016_Back")
 

### 产品介绍

> SENZ016 HC-05 主从一体蓝牙模块，采用CSR主流蓝牙芯片，可与蓝牙笔记本电脑、智能手机、其他蓝牙设备配对连接。我们的SENZ016还具有电源防反接功能，接反时模块不工作。


### 产品参数

- 工作电压：+3.6 ~ 6V
- 重量：3.5g
- 状态连接指示灯：快闪 -> 未连接；慢闪 -> AT命令模式
- 工作电流：未配对时，~30mA；配对后，~10mA
- 有效传输距离：空旷地带10m
- 可通过AT命令切换主从模式，也可以通过按键切换
- 默认设置：
	- 波特率：9600
	- 配对密码：1234
	- 名称：HC-05


### 使用教程

#### 引脚定义

|Sensor pin|Ardunio Pin|Function Description|
|-|:-:|-|
|VCC|+3.6~6V|Power shouldn't be higher than 7V|
|GND|GND||
|EN|H/L|H:Enable signal for AT mode|
|RXD|TX||
|TXD|RX||
|STATE|-|Output "H/L" digital level, Connected is "H", Unconnected is "L"|

![](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/pic/SENZ016_pin.jpg "引脚定义") 


#### 连线图

![](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/pic/SENZ016_connect.png "连线图") 


### 示例代码

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


### 购买[*SENZ016 HC-05 主从一体蓝牙模块*](https://www.ebay.com/).