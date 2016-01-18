/**
 * FreeIMU library serial communication protocol
 */
#define EXCLUDE_ICOMPASS

#include <MS561101BA.h> //Comment out for APM 2.5
#include <I2Cdev.h>
#include <MPU60X0.h>
//#include <AP_Baro_MS5611.h>  //Uncomment for APM2.5


//These are mandatory
//#include <AP_Math_freeimu.h>
#include <Butter.h>    // Butterworth filter
#ifndef EXCLUDE_ICOMPASS
  #include <iCompass.h>
#endif
#include <MovingAvarageFilter.h>

#include <Wire.h>
#include <SPI.h>

#if defined(__AVR__)
  #include <EEPROM.h>
#endif

//#define DEBUG
//#include "DebugUtils.h"
//#include "CommunicationUtils.h"
#include "FreeIMU.h"
#include "DCM.h"
#include "FilteringScheme.h"
#include "RunningAverage.h"

/*#include <StandardCplusplus.h>
#include <FilteringScheme.h>
#include <MovingAvarageFilter.h>
#include <AP_Math_freeimu.h>


//#include <HMC58X3.h>
#include <MS561101BA.h>
#include <I2Cdev.h>
//#include <MPU60X0.h>

#include <EEPROM.h>

#include <FreeIMU.h>
#include <Wire.h>
#include <SPI.h>
*/

// Adafruit nRF8001 Library
//#include <Adafruit_BLE_UART.h>
//Adafruit_BLE_UART BTLEserial = Adafruit_BLE_UART(10, 7, 9); // REQ, RDY, RST

int ypr[9];
//char chrData[17]; // Yaw (5 bytes), Pitch (5 bytes), Roll (5 bytes) ...delimeter is a pipe '|'

// Set the FreeIMU object
FreeIMU my3IMU = FreeIMU();


void setup() {
  Wire.begin();
  while(!Serial);
  Serial.begin(115200);
  
  my3IMU.init(true);
  //BTLEserial.begin();
}

void loop() {
  
//  if (ACI_EVT_CONNECTED == BTLEserial.pollACI()) {
    
    my3IMU.getRawValues(ypr);

//    dtostrf(ypr[0], 1, 1, &chrData[0]);
//    dtostrf(ypr[1], 1, 1, &chrData[5]);
//    dtostrf(ypr[2], 1, 1, &chrData[10]);
//    chrData[5] = chrData[10] = '|';
  
//    BTLEserial.write((byte*)chrData, 15);
    Serial.print(ypr[0]);
    Serial.print(ypr[1]);
    Serial.print(ypr[2]);
    Serial.print(ypr[3]);
    Serial.print(ypr[4]);
    Serial.print(ypr[5]);
    Serial.print(ypr[6]);
    Serial.print(ypr[7]);
    Serial.print(ypr[8]);
    Serial.println(ypr[9]);
//    Serial.print(ypr[0]);
//    Serial.print(F("|"));
//    Serial.print(ypr[1]);
//    Serial.print(F("|"));
//    Serial.print(ypr[2]);
//    Serial.println(F(""));
//  }
}

