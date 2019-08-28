/*
 * The simplest operation using SHT3x
 */


#include <QT_SHT3x.h>
SHT3x Sensor;
void setup() {
  
  Serial.begin(19200);
  Sensor.Begin(3,2); //sda,scL
}

void loop() {

  Sensor.UpdateData();
  Serial.print("Temperature: ");
  Serial.print(Sensor.GetTemperature());
  Serial.write("\xC2\xB0"); //The Degree symbol
  Serial.println("C");
  Serial.print("Humidity: ");
  Serial.print(Sensor.GetRelHumidity());
  Serial.println("%");

  delay(333);
}
