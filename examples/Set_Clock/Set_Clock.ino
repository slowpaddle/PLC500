 /*
 Example Sketch
 Setting the Real Time Clock on the CANADUINO PLC 500 Series boards.
 Dave Gillen - davebuildsthings.ca
 Written February 16, 2022 / Updated April 2, 2023
 This sample code is open source and free to use/modify.
 --------------------------------------------------------------------------------------------------------------------------------
 PLC 500-AC - https://universal-solder.ca/product/canaduino-plc-500-ac-industrial-plc-120-240v-ac-wifi-compatible-with-arduino/
 PLC 500-24 - https://universal-solder.ca/product/canaduino-plc-500-24-industrial-plc-12-24v-dc-wifi-compatible-with-arduino/
 --------------------------------------------------------------------------------------------------------------------------------
*/

#include <SPI.h>
#include <Wire.h>
#include <RtcDS3231.h>

RtcDS3231<TwoWire> Rtc(Wire);
#include <StringSplitter.h>

int YEAR, MONTH, DAY, HOUR, MIN, SEC, OK = 0;
String date, a;

#define countof(a) (sizeof(a) / sizeof(a[0]))

void setup() {
  Serial.begin(115200);
  Rtc.Begin();
  RtcDateTime now = Rtc.GetDateTime();
  BuildDateTime(now);
  Serial.println("Clock set to: " + date);
  Serial.println("Set time: (FORMATTED AS YYYY,M,D,H,M,S - Eg: 2021,11,30,13,33,54)");
  
}

void loop() {
  while(Serial.available()) {
    String item;
    int counter = 0;
    int fault_flag = 0;
    a = Serial.readString();// read the incoming data as string

    counter = countchar(a, ',');
    if(counter == 5) {
      for(int i=0; i<6; i++) {
        //Characters always return a zero from the toInt() function.
        if(getValue(a, ',', i).toInt() == 0) {          
          fault_flag = 1;
        }
      }
      if(fault_flag == 1) {
        fault_flag = 0;
        Serial.println("-----------------------------------------------------------------");
        Serial.println("No zeros or characters allowed and number of arguments must be 6.");
        Serial.println("Set time: (FORMATTED AS YYYY,M,D,H,M,S - Eg: 2021,11,30,13,33,54)");
        Serial.println("-----------------------------------------------------------------");
        break;
      }
      YEAR = getValue(a, ',', 0).toInt();
      MONTH = getValue(a, ',', 1).toInt();
      DAY = getValue(a, ',', 2).toInt();
      HOUR = getValue(a, ',', 3).toInt();
      MIN = getValue(a, ',', 4).toInt();
      SEC = getValue(a, ',', 5).toInt();
      
      RtcDateTime compiled = RtcDateTime (YEAR,MONTH,DAY,HOUR,MIN,SEC);
      Rtc.SetDateTime (compiled);
      RtcDateTime now = Rtc.GetDateTime();
      BuildDateTime(now);
      Serial.println("Clock set to: " + date);
    }
  }
}

void BuildDateTime(const RtcDateTime& dt)
{
  char datestring[31]; // Build the time string shown on the Main Page  
    snprintf_P(datestring, countof(datestring),
            PSTR("Date: %02u/%02u/%04u - Time: %02u:%02u"),
            dt.Day(),
            dt.Month(),
            dt.Year(),
            dt.Hour(),
            dt.Minute() );
            date = datestring;
}

//===============================================================
//                  getValue()
//      Routine used to parse serial data
//===============================================================
String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

int countchar(String a, char b) {
  int sizeis = a.length();
  int found = 0;
  for(int i=0; i<=sizeis; i++) {
    if(a.charAt(i)==b) {
      found++;
    }
  }
  return found;
}
