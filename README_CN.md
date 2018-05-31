# SENZ016 HC-05 主从一体蓝牙模块

###### 翻译

> `英文` 请参考 [`这里`](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/README.md)

> `中文` 请参考 [`这里`](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/README_CN.md)

![](https://github.com/njustcjj/SENZ016-HC-05-Bluetooth-Module-Master-Slave/blob/master/pic/SENZ016.jpg "SENZ016")
 

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

	//用Arduino配置蓝牙AT指令
	#define AT 2
	#define LED 13
	void setup()
	{
	       pinMode(LED,OUTPUT);
	       pinMode(AT,OUTPUT);
	       digitalWrite(AT,HIGH);
	       Serial.begin(38400);//这里应该和你的模块通信波特率一致
	       delay(100);
	       Serial.println("AT");
	       delay(100);
	       Serial.println("AT+NAME=OPENJUMPER-Bluetooth");//命名模块名
	       delay(100);
	       Serial.println("AT+ROLE=0");//设置主从模式：0从机，1主机
	       delay(100);
	       Serial.println("AT+PSWD=1234");//设置配对密码，如1234
	       delay(100);
	       Serial.println("AT+UART=9600,0,0");//设置波特率9600，停止位1，校验位无
	       delay(100);
	       Serial.println("AT+RMAAD");//清空配对列表
	}
	void loop()
	{
	       digitalWrite(LED, HIGH);
	       delay(500);
	       digitalWrite(LED, LOW);
	       delay(500);
	}


### 购买[*SENZ016 HC-05 主从一体蓝牙模块*](https://www.ebay.com/).