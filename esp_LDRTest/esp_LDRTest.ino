#include <Arduino.h>
#include "LDR.h"

const int RESOLUTION = 12; // Could be 9-12

//LDR     description - a descriptive name for this LDR (not used in communication with MQTT or JMRI)
//        pin - the analog pin that the LDR is connected to
//        JMRI ID - the ID in JMRI of the sensor that will be updated when the LDR state changes
//        Light threshold - the value read from the LDR under which the sensor will be deemed 'active'
//        Debounce time - millisecond value representing the amount of time the LDR must be reporting over or under the threshold value for, before state is switched
//        Debounce mode - 0 = to off only; 1 = to on only; 2 = on and off

LDR ldr = LDR("TestName", 36, "3001", 2100, 300, 0);

void setup()
{
  Serial.begin(19200);
  delay(1000);
  analogReadResolution(RESOLUTION);
}

void loop()
{
  //Check the state of the sensor to see if it's changed - if it has changed, report the new state to the console window
  bool changed = ldr.UpdateSensor();
  if (changed) {
    Serial.println(ldr.JMRIId + " changed " + ldr.State);
  }

  // Get the raw value from the LDR
  //  int raw = ldr.GetRaw();
  //  Serial.println(String(raw));

  //sleep for some time before next read
  delay(100);
}
