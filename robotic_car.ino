#include <SoftwareSerial.h>
// give it a name:
int frontright = 9; //This means that the front right wheel is connected to pin 9 on the Arduino
int frontleft = 3; //What pin is the front left wheel connected to?
int backleft = 11;
int backright = 10;

char input = ' '; //This creates the variable input. We will reference this variable later!

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(frontright, OUTPUT); //This says that you are going to send information to the pin frontright, which we earlier said was pin 9.
  pinMode(frontleft, OUTPUT);
  pinMode(backleft, OUTPUT);
  pinMode(backright, OUTPUT);
  Serial.begin(9600); //This sets the rate at which we read from Serial
  Serial.println("Hello from Arduino!");
}

// the loop routine runs over and over again forever:
void loop() {
  input = Serial.read(); //This reads whatever input you put into the Serial Monitor!
  //Because input is set to be a character, only read one character at a time!

//This next line says "if input is f, then continue into what is between these brackets { }"
  if (input =='f') //you can change this "f" 
  {
      digitalWrite(frontright, HIGH); //This specifies how much energy we send through the front right wheel.
      digitalWrite(frontleft, HIGH);  //HIGH means the wheel will turn, LOW means the wheel will not
      digitalWrite(backleft, HIGH);  
      digitalWrite(backright, HIGH);
      Serial.println("We're going forward!");
  }
  
  if (input == 's') //you can change this "s" 
  {
    digitalWrite(frontright, LOW);  
      digitalWrite(frontleft, LOW);  
      digitalWrite(backleft, LOW);  
      digitalWrite(backright, LOW);
      Serial.println("STOP!");
  }
  if (input == 'l') //you can change this "l" 
  {
    digitalWrite(frontright, LOW);  //Why do we turn off the front and back right wheels to make the car turn left?
    digitalWrite(frontleft, HIGH);  //What wheels should be turned off to make it turn right? Why?
    digitalWrite(backleft, HIGH);  
    digitalWrite(backright, LOW);
    Serial.println("Left!");
  }
   if (input == 'r') //you can change this "r" 
  {
    digitalWrite(frontright, HIGH);  
    digitalWrite(frontleft, LOW);  
    digitalWrite(backleft, LOW);  
    digitalWrite(backright, HIGH);
    Serial.println("Right!");
  } 
  if (input == "?")
  { 
    Serial.println("Enter f for forward, l for left, r for right")
  }
}  


