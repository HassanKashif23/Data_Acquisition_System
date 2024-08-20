# Data_Acquisition_System

A miniature industrial control system in which there are are 3 sensors
1. Smoke sensor MQ2
2. Temperature sensor LM35
3. IR speed sensor LM393

The smoke sensor senses the smoke in the air and when it crosses the threshold value the arduino outputs an actuator which is a fan working as an exhaust so that smoke is taken out and it descreases threshold value so the fan is turned off.
The temperature sensor senses the temperature in sorrounding and when it crosses the threshold value the arduino outputs two actuators which are buzzer and fan.
The fan cools down the temperature as soon as it falls down the threshold value so the fan and buzzer is turned off.
The IR speed sensor senses the speed of a dc motor and when it crosses a threshold value its speed is control externally using a "555" timer IC based PWM controller

All the data and messages are shown on an 16x2 lcd connectd through an I2C module.
