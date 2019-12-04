// CPE123 - Embedded systems and robotics 
// Name: Kitty, Van, Vincent, Kin, Briana   Team: 10
// Simply Tracking 

#include <CPutil.h>

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

int lostMode();
{
  static int lost = false;
  
  if (Serial.available())
  {
    lost = Serial.readString();
    
    if (lost == true())
    {
      
    }
  }
}
