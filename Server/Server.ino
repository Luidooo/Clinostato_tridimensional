#include <WiFi.h>
#include <WebServer.h>
#include <SPIFFS.h>

const char* ssid = "MENDES";
const char* password = "Ml2721091201";

WebServer server(80);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  if (!SPIFFS.begin(true)) {
    Serial.println("Failed to mount SPIFFS file system");
    return;
  }

  server.on("/", HTTP_GET, []() {
    File file = SPIFFS.open("/index.html", "r");
    if (!file) {
      Serial.println("Failed to open index.html file");
      return;
    }
    server.streamFile(file, "text/html");
    file.close();
  });

  server.on("/styles.css", HTTP_GET, []() {
    File file = SPIFFS.open("/styles.css", "r");
    if (!file) {
      Serial.println("Failed to open styles.css file");
      return;
    }
    server.streamFile(file,"text/css");
    file.close();
  });

  server.begin();
  Serial.println("HTTP server started");
  Serial.println(WiFi.localIP());
}

void loop() {
  server.handleClient();
}
