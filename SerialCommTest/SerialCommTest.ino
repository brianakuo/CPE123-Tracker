#include <CPutil.h>

// Define your pins


const int redLedPin = 7;

// Create your hardware

Led redLed(redLedPin);

void setup() 
{
  
  // Set up serial monitor and print out program info
  Serial.begin(9600);
  setupMessage(__FILE__, "Blinks an LED");
  delay(500);
  
  // Initialize your hardware
  redLed.off();
}

void setup90
{
  Serial2.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
   readSerial();
}

bool readSerial()
{
  int buttonPushed = 0;
  if (Serial.available())
    buttonPushed = Serial.parseInt();
    if (buttonPushed == "1")
    {
      blinkLed();
    }
}

void blinkLed()
{
  static MSTimer ledTimer;
  static int ledOnFlag = false;

  if (ledTimer.done() == true)
  {
    // reset the timer to 1 second
    ledTimer.set(1000);

    // turn on/off the led
    if (ledOnFlag == false)
    {
      redLed.on();
      ledOnFlag = true;
    }
    else
    {
      redLed.off();
      ledOnFlag = false;
    }
  }
   
}
