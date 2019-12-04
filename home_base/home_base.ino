// CPE123 - Embedded systems and robotics 
// Name: Kitty, Van, Vincent, Kin, Briana     Team: 10 
// Simply Tracking

#include <CPutil.h>

// Define your pins
// e.g. const int redLedPin = 38;

// Create your hardware
// e.g. Led redLed(redLedPin);

void setup() 
{
  
	// Set up serial monitor and print out program info
	Serial.begin(9600);
	setupMessage(__FILE__, "Put a start message here");
	delay(500); 
	
	// Initialize your hardware
	// e.g. redLed.off();

 
}

void loop() 
{
	// Call your control function(s) here 
	
}
