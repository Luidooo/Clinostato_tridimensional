#include <WiFi.h>
#include <WebServer.h>
#include <SPIFFS.h>

// WiFi settings
const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";

// Create an instance of the WebServer
WebServer server(80);

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Mount SPIFFS file system
  if (!SPIFFS.begin(true)) {
    Serial.println("Failed to mount SPIFFS file system");
    return;
  }

  // Route for root URL
  server.on("/", HTTP_GET, []() {
    File file = SPIFFS.open("/index.html", "r");
    if (!file) {
      Serial.println("Failed to open index.html file");
      return;
    }
    server.streamFile(file, "text/html");
    file.close();
  });

  // Route for CSS file
  server.on("/styles.css", HTTP_GET, []() {
    File file = SPIFFS.open("/styles.css", "r");
    if (!file) {
      Serial.println("Failed to open styles.css file");
      return;
    }
    server.streamFile(file, "text/css");
    file.close();
  });

  // Start server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
