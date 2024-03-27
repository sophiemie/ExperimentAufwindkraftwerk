/*
* meetMINT Space
* Experiment 30. - 31.07.2024
* 
*/

#include <Thermistor.h>
#include <NTC_Thermistor.h>
int Sensor_Pin = A0;
#define Referenzwiderstand   10000 // Widerstandswert des Widerstandes der mit dem NTC in Reihe geschaltet wurde.
#define Nominalwiderstand     10000 // Widerstand des NTC bei Normaltemperatur
#define Nominaltemperatur    25 // Temperatur, bei der der NTC den angegebenen Widerstand hat
#define BWert                3950 // Beta Koeffizient(zu finden im Datenblatt des NTC)
Thermistor* thermistor;

void setup()
{
  Serial.begin(9600);
  // Nun wird der Sensor mit den spezifischen Daten initialisiert.
  thermistor = new NTC_Thermistor(Sensor_Pin, Referenzwiderstand, Nominalwiderstand, Nominaltemperatur, BWert);
}


void loop()
{
  const double celsius = thermistor->readCelsius(); //Temperatur auslesen
  Serial.print("Temperatur: "); // Ausgabe der Temperatur am Seriellen Monitor - hier nur der Text "Temperatur; "
  Serial.print(celsius); // An dieser Stelle wird der Temperaturwert an den Seriellen Monitor gesendet.
  Serial.println(" °C"); // Hinter dem Temperaturwert wird am Seriellen Monitor nun noch die Einheit "C" angezeigt.
  delay(1000); // An dieser Stelle pausiert das Programm für eine Sekunde. Dadurch wird am Seriellen Monitor ein Temperaturwert pro Sekunde angezeigt.
}