#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "coke_jonas";
const char* password = "araujo@123";

WebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Clinostato Dashboard</title>
<style>
    body {
        font-family: Arial, sans-serif;
        margin: 0;
        padding: 0;
        background-color: #808080;
    }

    .container {
        margin: 50px auto;
        max-width: 600px;
        padding: 20px;
        background-color: #fff;
        border-radius: 10px;
        box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
    }

    h1 {
        color: #333;
        text-align: center;
    }

    button {
        padding: 10px 20px;
        font-size: 16px;
        background-color: #4CAF50;
        color: white;
        border: none;
        cursor: pointer;
        display: block;
        margin: 0 auto;
    }

    button:hover {
        background-color: #45a049;
    }
</style>
</head>
<body>
<div class="container">
    <h1>Clinostato Dashboard</h1>
    <button id="activateBtn">Activate Stepper Motors</button>
</div>

<script>
    document.getElementById("activateBtn").addEventListener("click", function() {
        // You can add JavaScript functionality here to handle the button click
        // For example, sending an HTTP request to the ESP32 server to activate stepper motors
        alert("Stepper motors activated!");
    });
</script>
</body>
</html>
)rawliteral";


void handleRoot() {
  server.send(200, "text/html", index_html);
}

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Set up routes
  server.on("/", handleRoot);

  server.begin();
  Serial.println("HTTP server started");
  Serial.println(WiFi.localIP());
}

void loop() {
  server.handleClient();
}