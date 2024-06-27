#include <Wire.h>

#include <Adafruit_Sensor.h> 

#include <Adafruit_ADXL345_U.h>
#include "classifier1.h"

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();
Eloquent::ML::Port::RandomForest clf;

void setup(void) 

{

   Serial.begin(9600);  

   if(!accel.begin())

   {

      Serial.println("No valid sensor found");

      while(1);

   }

}

void loop(void) 

{

   sensors_event_t event; 

   accel.getEvent(&event);

   Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");

   Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");

   Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");

   Serial.println("m/s^2 ");
   float sample[3]={event.acceleration.x,event.acceleration.y,event.acceleration.z};
   Serial.println(clf.predict(sample));
  delay(1000);


}
