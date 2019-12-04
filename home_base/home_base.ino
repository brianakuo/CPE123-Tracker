// CPE123 - Embedded systems and robotics 
// Name: Kitty, Van, Vincent, Kin, Briana     Team: 10 
// Simply Tracking

#include <CPutil.h>
#include <SPI.h>
#include <MFRC522.h>

//____________________________________________________________________
//Sudo Code 
// HomeBase Hardware Include: 1 Red Led, 1 Green Led, 1 Button, 1 RFID

// Input: RFID signal
// Output: LED
// Manual: When RFID signal indicate item is in range, Green LED is on. When item is out of range, Red LED is on. 


// Input: Button
// Output: Serial Output
// Manual: When Button is pushed, if item is in range, print to serial "Button is pushed, Item in range".
//         If item is not in range, print to serial "Button is pushed, Item not in range".


// Define your pins
#define SS_PIN 10
#define RST_PIN 9
#define redLedPin 4
#define greenLedPin 3
#define button 2


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
}

void detectItem()
{
  if (lookingForCard() == true)
  {
    greenLed.on();
    redLed.off();
  }
  else if (lookingForCard() == false)
  {
    greenLed.off();
    redLed.on();
  }
}

bool lookingForCard()
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "DA 16 87 16") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();

  }
 
 else   {
    Serial.println(" Access denied");

  }
} 
