# MQTT Curtains
Control a servo connected to a esp8266 to open and close your curtains/blinds. Cheap solution to "smart" your curtains/blinds.

    Hardware used:
ESP8266 LoLin nodemcu
Servo=MG995


      Wiring:
[Servo]   [ESP8266]
  GND--------GND
  VCC--------VV (5v)
  DATA-------D2
  
  Don't need to change anything at 'MQTT_Curtains.ino' only at 'user_config.h'
  
  "MQTT Client Name" & "MQTT Topic to Control Curtains" & "MQTT State Topic" need to be unique for each curtain/blinds
  
                  -MQTT TOPICS CONFIGURATION-
  
  "MQTT ON Command" & "MQTT OFF Command" are the msg you publish to start opening or closing
  
  --------
  "SpinTime to Open" and "SpinTime to Close" is the time the servo runs to either open or close, you will have to adjust according to your own. 
  
  And unless you need to change the Servo Port don't change anything else at "SERVO CONFIGURATION" unless you know what you are doing.
