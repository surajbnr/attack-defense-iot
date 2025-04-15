#include <WiFi.h>
#include <WebServer.h>\
#include <esp_wifi>

const char* ssid = "KS";      // Replace with your WiFi SSID
const char* password = "12032026";  // Replace with your WiFi Password

#define IR_SENSOR_PIN 15  // IR sensor connected to GPIO 15

WebServer server(80);

String blockedIP = "192.168.223.1";  // Replace with the attacker's IP

void handleRoot() {
    String clientIP = server.client().remoteIP().toString();
    Serial.printf("Incoming request from: %s\n", clientIP.c_str());

    // Check if the request comes from the blocked IP
    if (clientIP == blockedIP) {
        Serial.printf("Blocking IP: %s\n", clientIP.c_str());
        server.send(403, "text/plain", "Access Denied");
        return;
    }

    int sensorValue = digitalRead(IR_SENSOR_PIN);  // Read the IR sensor state
    String html = "<html><head><meta http-equiv='refresh' content='1'></head><body>";
    html += "<h1>ESP32 IR Sensor</h1>";
    html += "<p>IR Sensor State: " + String(sensorValue) + "</p>";
    html += "</body></html>";
    server.send(200, "text/html", html);
}

void setup() {
    Serial.begin(115200);
    pinMode(IR_SENSOR_PIN, INPUT);

    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");
    Serial.println(WiFi.localIP());

    server.on("/", handleRoot);
    server.begin();
    Serial.println("HTTP server started");
}

void loop() {
    server.handleClient();
}
