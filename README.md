# Seek
The Digital Hide and Seek Game

## How It Works
It is made up of two major components the hardware based Hider devices and the software based Seekers app. The Hiders are a micro controller device that has GPS and WiFi modules; that capture the current GPS coordinates and then send them over WiFi to the Seekers device. The coordinates of the Hiders are compared with the coordinates of the Seeker's device. The Seekers app then calculates direction you need to walk to find the Hider showing this as a compass direction on screen and also displays the current heading for the Seekers device. The aim is for the Seeker to find the Hiders, which can either be left in a fixed location or with a person. Once found the Seeker can scan the NFC chip on the Hider. Confirming that they have found that specific Hider giving them achievement points that are logged against their account.

## Built With
* Apache
* Arduino
* C++
* CSS3
* ESP8266
* ESP8266 http client
* ESP8266 WiFi
* U-Blox 7 GPS module
* Raspberry Pi server
* Coke Can
* JavaScript
* HTML5
* PHP
* Tiny GPS
* Software Serial

## Challenges Faced
The GPS module had a problem connecting to satellites, this was solved by making a metal cone out of a coke can to improve the signal. Once fixed we had another issue getting the GPS module to transmit the correct co-ordinates to the Arduino. Because of this we did not manage to complete development of the PHP link between the Hiders and Seekers.

We also ran into a issue with finding the current bearing of the Seekers device this was because we could not access the magnetic sensor on the phone without developing a full mobile app. But, by this point it was to late to make the switch to a full Android mobile app.

## What We Learned
* How to use GPS.
* Using and connecting ESP8266 to the internet.
* Performing maths in JavaScript.
* How to share data between hardware and software devices.

## What's Next For Seek
* Creating a mobile app.
* Adding distance to the display so, it can be used for navigation around       buildings. e.g.(Convention Centre, Hospital)
* Integrating iBeacon or Eddystone to develop a system that is not completely reliant on WiFi as this cannot be found in all locations.
* Keeping a record of achievements.
* Using batteries to power the device.

## Images
![Hider](screenshots/hider.jpg)
Hider Device
![Seeker](screenshots/seeker.PNG)
Seeker App
