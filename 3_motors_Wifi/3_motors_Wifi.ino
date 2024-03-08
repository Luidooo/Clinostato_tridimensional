#include <WiFi.h>
#include <ESP_FlexyStepper.h>

const char* ssid     = "coke_jonas";
const char* password = "araujo@123";

const int axis_1_step_pin = 2;
const int axis_1_direction_pin = 4;
const int axis_2_step_pin = 15;
const int axis_2_direction_pin = 16;
const int axis_3_step_pin = 17;
const int axis_3_direction_pin = 5;

ESP_FlexyStepper axis_1;
ESP_FlexyStepper axis_2;
ESP_FlexyStepper axis_3;

WiFiServer server(80);

void setup()
{
    Serial.begin(115200);
    axis_1.connectToPins(axis_1_step_pin, axis_1_direction_pin);
    axis_2.connectToPins(axis_2_step_pin, axis_2_direction_pin);
    axis_3.connectToPins(axis_3_step_pin, axis_3_direction_pin);

    axis_1.setSpeedInStepsPerSecond(100); 
    axis_1.setAccelerationInStepsPerSecondPerSecond(500);
    axis_1.setDecelerationInStepsPerSecondPerSecond(500); 

    axis_2.setSpeedInStepsPerSecond(100); 
    axis_2.setAccelerationInStepsPerSecondPerSecond(500);
    axis_2.setDecelerationInStepsPerSecondPerSecond(500); 

    axis_3.setSpeedInStepsPerSecond(100); 
    axis_3.setAccelerationInStepsPerSecondPerSecond(500);
    axis_3.setAccelerationInStepsPerSecondPerSecond(500);



    pinMode(5, OUTPUT);   

    delay(10);

    // We start by connecting to a WiFi network
    Serial.println();

    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print("Conectando");
    }

    Serial.println("");
    Serial.println("WiFi conectado.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();

}

void loop(){
 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click  <a href=\"/axis1\">here</a> to turn the motor 1 on.<br>");
            client.print("Click <a href=\"/axis2\">here</a> to turn the motor 2 on.<br>");
            client.print("Click <a href=\"/axis3\">here</a> to turn the motor 3 on.<br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /axis1")) {
          axis_1.moveRelativeInSteps(20000);               
        }
        if (currentLine.endsWith("GET /axia2")) {
          axis_2.moveRelativeInSteps(20000);
        }
        if (currentLine.endsWith("GET /axia3")) {
          axis_1.moveRelativeInSteps(20000);                
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
