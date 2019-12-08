// CPE123 - Embedded systems and robotics 
// Name: Kitty, Van, Vincent, Kin, Briana     Team: 10 
// Simply Tracking

#include <CPutil.h>
#include <SPI.h>
#include <MFRC522.h>

//____________________________________________________________________
//Sudo Code 
// HomeBase Hardware Includes: 1 Red Led, 1 Green Led, 1 Button, 1 RFID Reader

// Input: RFID signal
// Output: LED
// Manual: When RFID signal indicates item is in range, Green LED is on. When item is out of range, Red LED is on. 


// Input: Button
// Output: Serial Output
// Manual: When Button is pushed, if item is in range, print to serial "Button is pushed, Item in range".
//         If item is not in range, print to serial "Button is pushed, Item not in range".


// Define your pins
#define SS_PIN 10
#define RST_PIN 9
const int redLedPin = 4;
const int greenLedPin = 3;
const int button = 2;


// Create your hardware
// e.g. Led redLed(redLedPin);
Led redLed = redLedPin;
Led greenLed = greenLedPin;
Button redButton = button;
MFRC522 mfrc522(SS_PIN, RST_PIN);     // Create MFRC522 instance.

void setup() 
{
  
	// Set up serial monitor and print out program info
	Serial.begin(9600);
  SPI.begin(); 
  mfrc522.PCD_Init();
	setupMessage(__FILE__, "Checking if the ");
	delay(500); 
	
	// Initialize your hardware
  redLed.off();
  greenLed.off();
 
}

void loop() 
{
	// Call your control function(s) here 
  detectItem();
  if (buttonPushed())
  {
    Serial.print("1");
  }
  else
  {
    Serial.print("0");
  }
  
}

void detectItem()
{
  static MSTimer greenTimer;
  enum{GREEN, RED};
  static int state = RED;
  bool res = lookingForCard();

  switch(state)
  {
    case(GREEN):
    if (res == false and greenTimer.done())
    {
      redLed.on();
      greenLed.off();
       state = RED;
    }
    break;
    
    case(RED):
    if (res == true)
    {
      greenLed.on();
      redLed.off();
      greenTimer.set(1000);
      state = GREEN;
    }
    break;
  } 
}

bool buttonPushed()
{
  int returnValue = 0;
  if (redButton.wasPushed())
  {
    returnValue = true;
  }
  else
  {
    returnValue = false;
  }
  return returnValue;
}

bool lookingForCard()
{
  int returnValue = 0;
  if (mfrc522.PICC_IsNewCardPresent()) { // (true, if RFID tag/card is present ) PICC = Proximity Integrated Circuit Card
      returnValue = true;
  }
  else
  {
      returnValue = false;
  }
  return returnValue;
}
