//Wifi connect to server via HTTP get
#include "Arduino.h"
#include "WiFi.h"
#include "HTTPClient.h"

const char* ssid     = "test";
const char* password = "test1234";


const String url = "http://example.org";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.print(F("Connecting to WiFi: "));
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print(F("OK! IP="));
  Serial.println(WiFi.localIP());

  Serial.print("Fetching " + url + "... ");

  HTTPClient http;
  http.begin(url);

  int httpResponseCode = http.GET();
  if (httpResponseCode > 0) {
    Serial.print("HTTP response: ");
    Serial.println(httpResponseCode);

    String payload = http.getString();
    
    Serial.println();
    Serial.println(payload);
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
    Serial.println(":-(");
  }
  http.end();
}

void loop() {
  delay(100);
}