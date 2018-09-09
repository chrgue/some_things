#define MY_RADIO_NRF24

#include <MySensors.h>
#include "MYSLog.h"

#define CHILD_ID 0
#define TEMP_SENSOR A0
#define SLEEP_TIME 5000
#define INVERT_SENSOR 0

MyMessage respondMoisture(CHILD_ID, V_LEVEL);

void setup(){ 
  
}

void presentation(){
    LOG("presentation");
    sendSketchInfo("Soil Moisture Sensor Reverse Polarity", "1.0");
    present(CHILD_ID, S_MOISTURE);
}

void loop(){
    LOG("loop");
    int value = readSensor();
    MyMessage msg = respondMoisture.set(value);
    LOG(F("Sending value=%i\n"), value);
    send(msg);
    delay(SLEEP_TIME);
}

int readSensor(){  
  int sensorValue = analogRead(TEMP_SENSOR);

  #if INVERT_SENSOR == 1
    sensorValue = 1023 - sensorValue;
  #endif
  
  return constrain(map(sensorValue, 0, 1023, 0, 100), 0, 100);
}
