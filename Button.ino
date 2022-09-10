//Ishan Arora

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;  //moisture sensor  colored   // the number of the pushbutton pin
const int ledPin =  13; //pump indicator
const int buttonPin2 = 9; //water sensor
const int ledPin2 = 8; // empty indicator
int IN1 = 3;   //relays
int IN2 = 4;
int IN3 = 5;
int IN4 = 6;
#define ON   0
#define OFF  1
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;

void setup() {
  relay_init();
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin2, OUTPUT);


}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
          relay_SetStatus(ON, OFF, OFF,OFF);

  } else {
    // turn LED off:
              relay_SetStatus(OFF, OFF, OFF,OFF);


    digitalWrite(ledPin, LOW);
  }
      if (buttonState2 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin2, HIGH);

  } else {
    // turn LED off:

    digitalWrite(ledPin2, LOW);
  }
}
void relay_init(void)//initialize the relay
{  
  //set all the relays OUTPUT
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  relay_SetStatus(OFF,OFF,OFF,OFF);//turn off all the relay
}
void relay_SetStatus( unsigned char status_1,  unsigned char status_2, unsigned char status_3,unsigned char status_4)
{
  digitalWrite(IN1, status_1);
  digitalWrite(IN2, status_2);
  digitalWrite(IN3, status_3);
  digitalWrite(IN4, status_4);

}
