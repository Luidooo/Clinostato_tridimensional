#include <WiFi.h>   
#include <WebServer.h> 
#include <ESP_FlexyStepper.h>
#include <ESP_Google_Sheet_Client.h>
#include "index.h" 

#define LOCAL_SSID "coke_jonas"
#define LOCAL_PASS "araujo@123"

#define PIN_OUTPUT 26 // connected to nothing but an example of a digital write from the web page
#define PIN_FAN 27    // pin 27 and is a PWM signal to control a fan speed
#define PIN_LED 2     //On board LED
#define PIN_A0 34     // some analog input sensor
#define PIN_A1 35     // some analog input sensor

// variables to store measure data and sensor states
int BitsA0 = 0, BitsA1 = 0;
float VoltsA0 = 0, VoltsA1 = 0;
int FanSpeed = 0;
bool LED0 = false, SomeOutput = false;
uint32_t SensorUpdate = 0;
int FanRPM = 0;


bool btn0, btn1, btn2, btn3, btn4 = false;

int motorVelocity = 1000;
const int motor1_step_pin = 2;
const int motor1_direction_pin = 4;
const int motor2_step_pin = 15;
const int motor2_direction_pin = 16;
const int motor3_step_pin = 17;
const int motor3_direction_pin = 5;

ESP_FlexyStepper motor1;
ESP_FlexyStepper motor2;
ESP_FlexyStepper motor3;

char XML[2048];

char buf[32];

WebServer server(80);

void setup() {

  Serial.begin(115200);

  motor1.connectToPins(motor1_step_pin, motor1_direction_pin);
  motor2.connectToPins(motor2_step_pin, motor2_direction_pin);
  motor3.connectToPins(motor3_step_pin, motor3_direction_pin);

  motor1.setSpeedInStepsPerSecond(motorVelocity); 
  motor1.setAccelerationInStepsPerSecondPerSecond(500);
  motor2.setSpeedInStepsPerSecond(motorVelocity); 
  motor2.setAccelerationInStepsPerSecondPerSecond(500);
  motor3.setSpeedInStepsPerSecond(motorVelocity);
  motor3.setAccelerationInStepsPerSecondPerSecond(500);


 //disableCore0WDT();
 //disableCore1WDT();

  Serial.println("starting server");

  WiFi.begin(LOCAL_SSID, LOCAL_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    //acendeiled
  }
  Serial.print("IP address: "); 
  Serial.println(WiFi.localIP());
  printWifiStatus();


  // these calls will handle data coming back from your web page
  // this one is a page request, upon ESP getting / string the web page will be sent
  server.on("/", SendWebsite);

  // upon esp getting /XML string, ESP will build and send the XML, this is how we refresh
  // just parts of the web page
  server.on("/xml", SendXML);

  // upon ESP getting /UPDATE_SLIDER string, ESP will execute the UpdateSlider function
  // same notion for the following .on calls
  // add as many as you need to process incoming strings from your web page
  // as you can imagine you will need to code some javascript in your web page to send such strings
  // this process will be documented in the SuperMon.h web page code
  server.on("/BUTTON_0", ProcessButton_0);
  server.on("/BUTTON_1", ProcessButton_1);
  server.on("/BUTTON_2", ProcessButton_2);
  server.on("/BUTTON_3", ProcessButton_3);
  server.on("/BUTTON_4", ProcessButton_4);
  server.on("/BUTTON_5", ProcessButton_5);
  server.on("/BUTTON_6", ProcessButton_6);
  server.on("/BUTTON_7", ProcessButton_7);

  server.begin();

}

void loop() {

  server.handleClient();

}

void ProcessButton_0() {

  btn0 = !btn0;
  motor1.setSpeedInStepsPerSecond(motorVelocity/4); 
  motor2.setSpeedInStepsPerSecond(motorVelocity/4);
  motor3.setSpeedInStepsPerSecond(motorVelocity/4);
  server.send(200, "text/plain", ""); 
}

void ProcessButton_1() {
  btn1 = !btn1;
  motor1.setSpeedInStepsPerSecond(motorVelocity/2); 
  motor2.setSpeedInStepsPerSecond(motorVelocity/2); 
  motor3.setSpeedInStepsPerSecond(motorVelocity/2);
  server.send(200, "text/plain", ""); 
}

void ProcessButton_2() {
  btn2 = !btn2;
  motor1.setSpeedInStepsPerSecond((motorVelocity/4)*3); 
  motor2.setSpeedInStepsPerSecond((motorVelocity/4)*3); 
  motor3.setSpeedInStepsPerSecond((motorVelocity/4)*3);
  server.send(200, "text/plain", ""); 
}

void ProcessButton_3() {
  btn3 = !btn3;
  motor1.setSpeedInStepsPerSecond((motorVelocity/4)*3); 
  motor1.setSpeedInStepsPerSecond(motorVelocity); 
  motor2.setSpeedInStepsPerSecond(motorVelocity); 
  motor3.setSpeedInStepsPerSecond(motorVelocity);
  server.send(200, "text/plain", ""); 
}

void ProcessButton_4() {
  server.send(200, "text/plain", ""); 
}

void ProcessButton_5() {
  server.send(200, "text/plain", ""); 
}

void ProcessButton_6() {
  server.send(200, "text/plain", ""); 
}

void ProcessButton_7() {
  server.send(200, "text/plain", ""); 
}



void SendWebsite() {

  Serial.println("sending web page");
  server.send(200, "text/html", PAGE_MAIN);

}

void SendXML() {


  strcpy(XML, "<?xml version = '1.0'?>\n<Data>\n");
 
   
  if (btn0)
    strcat(XML, "<btn0>1</btn0>\n");
  else
    strcat(XML, "<btn0>0</btn0>\n");


  strcat(XML, "</Data>\n");
  Serial.println(XML);
  server.send(200, "text/xml", XML);


}

void printWifiStatus() {

  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Open http://");
  Serial.println(WiFi.localIP());
}
