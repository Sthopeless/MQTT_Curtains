#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <PubSubClient.h>
#include "user_config.h"

WiFiClient espClient;
PubSubClient client(espClient);
Servo myservo;

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(wifi_ssid, wifi_password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  char p[length + 1];
  memcpy(p, payload, length);
  p[length] = NULL;
  String message(p);
  String mytopic(topic);
  if (mytopic == mqtt_command && message == cmnd_off) {
    myservo.attach(servo_port);
    Serial.println(closing_msg);
    delay(msg_delay_off);
    myservo.write(servo_write_off);
    client.publish(mqtt_state, cmnd_off);
    delay(spintime_off);
    myservo.detach();
  }

  if (mytopic == mqtt_command && message == cmnd_on) {
    myservo.attach(servo_port);
    Serial.println(opening_msg);
    delay(msg_delay_on);
    myservo.write(servo_write_on);
    client.publish(mqtt_state, cmnd_on);
    delay(spintime_on);
    myservo.detach();
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect(mqtt_client, mqtt_user, mqtt_password)) {
      Serial.println("connected");
      client.subscribe(mqtt_command);
      } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}
