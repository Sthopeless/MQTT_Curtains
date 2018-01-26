/************************* WIFI CONFIGURATION **********************************/
#define wifi_ssid "xxxxxxxxx"     //WiFi SSID
#define wifi_password "xxxxxxxxx" //WiFi Password

/************************* MQTT BROKER CONFIGURATION ***************************/
#define mqtt_client "MQTTCurtains"  // MQTT Client Name
#define mqtt_server "xxx.xxx.x.xxx" // MQTT Broker IP
#define mqtt_user "xxxxxxxxxx"      // MQTT Username
#define mqtt_password "xxxxxxxxx"   // MQTT Password
#define mqtt_port 1883              // MQTT Port

/************************* MQTT TOPICS CONFIGURATION ***************************/
#define mqtt_command "/MQTTCurtains/control/" // MQTT Topic to Control Curtains
#define mqtt_state "/MQTTCurtains/state/"     // MQTT State Topic
#define cmnd_on "ON"                          // MQTT ON Command
#define cmnd_off "OFF"                        // MQTT OFF Command

/************************* SERVO CONFIGURATION ********************************/
#define servo_port D2        // Servo Pin
#define spintime_on 5000     // SpinTime to Open
#define spintime_off 5000    // SpinTime to Close
#define opening_msg "open"   // Serial MSG when opening
#define closing_msg "close"  // Serial MSG when closing
#define servo_write_on 180   // Servo Write for ON  (default:180)
#define servo_write_off 0    // Servo Write for OFF (default:0)
#define msg_delay_on 50      // MSG Delay ON
#define msg_delay_off 50     // MSG Delay OFF
