# 4WD robot car with BLE smartphone remote control

## Short Description 

<p align="center">
<img src="https://github.com/lrswss/ble-robot-car/blob/master/ble-robot-car.jpg" alt="4WD Robot Car with BLE control">
</p>

The Arduino motor shield drives two pairs of DC motors (channel A left, channel B right). A BLE
bluetooth module [AT-09](https://makersportal.com/blog/2019/10/14/bluetooth-module-with-arduino)
connected via SoftSerial is used to control the car using simple serial commands. Suitable
free App for iOS [BLEJoyStick](https://apps.apple.com/us/app/ble-joystick/id1098200556).

## Hardware schematics

<p align="center">
<img src="https://github.com/lrswss/ble-robot-car/blob/master/schematics.png" alt="4WD Robot Car Schematics">
</p>

## Shopping list

* Kit "4WD Smart Car" (chassis, 4 motors, battery holder)
* Arduino Uno
* Arduino motor shield (e.g. Deek-Robot Motor Shield)
* BLE Bluetooth module (AT-09)
* 1k and 2k resistors for 3.3v voltage divider on BLE module RX line
* few cables, solder, soldering iron or dupont cables

## Build and install

Download the Arduino sketch, compile it using the Arduino IDE and upload it
to the Arduino Uno as usual. If the Bluetooth connection doesn't seem to work
try to change the RX/TX lines on Pin 4/5. The BLE module will probably also work
without the voltage divider but your your mileage may vary (harm your BLE module).

## Contributing

Pull requests are welcome! For major changes, please open an issue first to
discuss what you would like to change.

## License

Copyright (c) 2020 Lars Wessels.
This software was published under the MIT license. 
Please check the [license file](LICENSE).
