/*
* meetMINT Space
* Experiment 30. - 31.07.2024
* 
*/

#include <IRremote.h>

int irPin = 2;  // Pin, an dem der OUT-Pin des VS1838B angeschlossen ist

void setup() {
  pinMode(irPin, INPUT);    // Setze irPin als Eingang
  Serial.begin(9600);       // Starte die serielle Kommunikation mit 9600 Baud
}

void loop() {
  int irState = digitalRead(irPin); // Lese den Zustand des IR-Sensors

  // Gebe den Zustand des IR-Sensors auf der seriellen Schnittstelle aus
  if (irState == HIGH) {
    Serial.println("1"); // IR-Signal erkannt
  } else {
    Serial.println("0"); // Kein IR-Signal erkannt
  }

  delay(100); // Kurze Pause, um die Ausgabe lesbar zu machen
}
