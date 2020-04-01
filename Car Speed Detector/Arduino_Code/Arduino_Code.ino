#include <SoftwareSerial.h>

int bluetoothTx = 7;  // TX-O pin of bluetooth mate
int bluetoothRx = 6;  // RX-I pin of bluetooth mate
 
int led = 13; // pin no of led connected to
 
int buttonPin1 = 3; // pin no of pushbutton1(ON) connected to
int buttonPin2 = 4; // pin no of pushbutton1(OFF) connected to
int button1State = 0;
int button2State = 0;

int dataFromBt; // variable to read data sent from bluetooth
 
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx); // Software Serial Object for bluetooth communication

void setup()
{
  Serial.begin(9600); // to begin Arduino
  bluetooth.begin(9600); // to begin Bluetooth
  pinMode(led, OUTPUT); // led set as output
  pinMode(buttonPin1, INPUT); // push buttons set as input
  pinMode(buttonPin2, INPUT);
}
 
void loop()
{
 
  if (bluetooth.available() > 0) // if bluetooth is sending any data
  { 
    dataFromBt = bluetooth.read(); // read the data bluetooth is sending
 
    if (dataFromBt == '1') { // if sent data is 1 then turn on led
      digitalWrite(led, HIGH);
    }
    if (dataFromBt == '0') { // else turn off led
      digitalWrite(led, LOW);
    } 

  }
  
  button1State = digitalRead(buttonPin1); // read data from push buttons
  button2State = digitalRead(buttonPin2);
  
  if (button1State == 1) { // if pushbutton1(on) is pressed turn on the led and send 1 to bluetooth
    digitalWrite(led, HIGH);
    Serial.print("1"); // prints one in serial monitor
    bluetooth.print("1"); // sends one to bluetooth
    delay(250);
    
    }
  if (button2State == 1) {
    digitalWrite(led, LOW);
    Serial.print("0");
    bluetooth.print("0");
    delay(250);
    }

}
