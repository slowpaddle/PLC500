 /*
 Example Sketch
 Reading and writing the SD Card on the CANADUINO PLC 500 Series boards.
 Dave Gillen - davebuildsthings.ca
 February 16, 2022
 This sample code is open source and free to use/modify.
 --------------------------------------------------------------------------------------------------------------------------------
 PLC 500-AC - https://universal-solder.ca/product/canaduino-plc-500-ac-industrial-plc-120-240v-ac-wifi-compatible-with-arduino/
 PLC 500-24 - https://universal-solder.ca/product/canaduino-plc-500-24-industrial-plc-12-24v-dc-wifi-compatible-with-arduino/
 --------------------------------------------------------------------------------------------------------------------------------

 CS - pin 53
*/

#include <SD.h>

const int CS_PIN = 53; // Mega board
String FileName = "test.txt";
File myFile;

void setup()
{
  Serial.begin(115200);
  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(53, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(CS_PIN)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  
  if (!SD.exists(FileName)) {
  Serial.println("File test.txt does not exist. Creating the file.");
    myFile = SD.open(FileName, FILE_WRITE);
    myFile.println("A small line of text.");
    myFile.close();
  }
  
  myFile = SD.open(FileName);
  if (myFile) {
    Serial.println("Contents of test.txt:");
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
    Serial.write(myFile.read());
  }
  // close the file:
  myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("Error opening test.txt");
  }
  Serial.println("Deleting the file....");
  SD.remove(FileName);
  Serial.println("Done!");
}

void loop()
{
 
}
