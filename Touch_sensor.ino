#include <KiwisIoT.h>

const char* ssid = "prakatheesh";        // Replace with your WiFi network name
const char* pass = "123456789";         // Replace with your WiFi network password
const char* topic = "dash_1790068686198"; // Replace with your dashboard topic ID

#define TOUCH_PIN D2

KiwisIoT kiwisiot(ssid, pass, topic);

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(TOUCH_PIN, INPUT);

  kiwisiot.begin();

  Serial.println();
  Serial.println("Touch Sensor Started");
}

void loop() {
  kiwisiot.run();

  int touchValue = digitalRead(TOUCH_PIN);

  Serial.print("Touch Value: ");
  Serial.println(touchValue);

  // Send data to KiwisIoT Channel 1
  kiwisiot.send("1", touchValue);

  delay(2000);
}
