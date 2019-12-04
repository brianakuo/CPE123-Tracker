// CPE123 - Embedded systems and robotics 
// Name: Kitty, Van, Vincent, Kin, Briana   Team: 10
// Simply Tracking 

#include <CPutil.h>
#include <SPI.h>
#include <MFRC522.h>

// ____________________________________________________________________
// Tracker Hardware Includes: 1 Red Led, 1 Buzzer, 1 RFID Tag

// Input: RFID Signal
// Output: LED and Buzzer
// Manual: When RFID Signal indicates item

const int ledPin = 4;

Led myLed(ledPin);
pinMode(3, OUTPUT);

void setup() 
{
  
	Serial.begin(9600);
	setupMessage(__FILE__, "Put a start message here");
	delay(500); 
	  
  myLed.off();
 
}

void loop() 
{

  lostMode();
	
}

int tracker();
{
  static int lost = false;
  
  if (Serial.available())
  {
    lost = Serial.readString();
    
    if (lost == true())
    {
      lostMode();
    }
  }
}

void lostMode()
{
  
}
