#include <Arduino.h>
#include "WiFi.h"

void setup() {
  Serial.begin(115200);
  WiFi.disconnect();

  WiFi.mode(WIFI_STA);
  delay(100);

  Serial.println(F("Setup done"));
}

void loop() {
  Serial.print(F("\n\nScan start: "));

  int n = WiFi.scanNetworks();

  if (n == 0) {
      Serial.println(", but no networks were found.");
  } 
  else {
    Serial.printf("%d networks found.\n",n);
    for (int i = 0; i < n; ++i) {
      Serial.printf("\t%d: %S(%d)\n",i,WiFi.SSID(i).c_str(),WiFi.RSSI(i));
      delay(10);
    }
  }

  delay(5000);
}