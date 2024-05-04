#include <ESP8266WiFi.h>

WiFiServer telnet(23);

void setup() {
  Serial.begin(115200);
  WiFi.softAP("moz", "12345678");
  telnet.begin();
}

void loop() {
  WiFiClient client = telnet.available();
  if (client) {
    client.print("\033[2J");
    client.print("\033[31;103;103m");
    for (int i = 0; i < 10; i++) {
      client.print(" MOZ ");
      delay(900);
      client.print("\033[2J");
    }
      client.stop();
}
}
