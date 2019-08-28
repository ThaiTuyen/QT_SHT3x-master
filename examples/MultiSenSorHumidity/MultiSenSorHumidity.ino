
#include <QT_SHT3x.h>

SHT3x Humidity_Sensor1;
SHT3x Humidity_Sensor2;

bool enableDebugPort = true;

void setup() {

  Serial.begin(9600);
  
  Humidity_Sensor1.Begin(3, 2); //yellow, blue
  Humidity_Sensor2.Begin(5, 4);
}

void loop() {
  
  String message = get_Message_Data();;
  if (enableDebugPort == true)
  {
  Serial.println("OK");
  }
  delay(2000);
}

float get_Humidity_Data1()
{
  float humidity;
  Humidity_Sensor1.UpdateData();
  humidity = Humidity_Sensor1.GetRelHumidity();
  if (enableDebugPort == true)
  {
    Serial.print("Air Humidity: ");
    Serial.print(humidity);
    Serial.println("%");
  }
  return humidity;
}

float get_Humidity_Data2()
{
  float humidity;
  Humidity_Sensor2.UpdateData();
  humidity = Humidity_Sensor2.GetRelHumidity();
  if (humidity == true)
  {
    Serial.print("Air Humidity: ");
    Serial.print(humidity);
    Serial.println("%");
  }
  return humidity;
}

String get_Message_Data()
{
  float humidity1;
  float humidity2;
  String message; 
  
  humidity1 = get_Humidity_Data1();
  humidity2 = get_Humidity_Data2();
   
  if (enableDebugPort == true)
  {
  Serial.print("Message: ");
  Serial.println(message);
  }
  return message;
}
