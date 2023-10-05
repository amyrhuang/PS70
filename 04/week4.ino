const int A1A = 3;  // define pin 3 for A-1A (speed)
const int A1B = 4;  // define pin 4 for A-1B (direction)
int buttonPin = 8;
int potPin = A1;
int potVal;
int motorSpeed;

void setup() {
  pinMode(A1A, OUTPUT);     // specify these pins as outputs
  pinMode(A1B, OUTPUT);
  digitalWrite(A1A, LOW);   // start with the motors off 
  digitalWrite(A1B, LOW);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  motorSpeed = (potVal*255)/1024;

  // Serial.println(analogRead(potPin));
  if(digitalRead(buttonPin) == LOW){
    digitalWrite(A1A, LOW);  // A1A needs to be LOW to switch direction
    analogWrite(A1B, motorSpeed); 
  }
  else{
    analogWrite(A1A, motorSpeed); 
    // digitalWrite(A1A, HIGH);   
    digitalWrite(A1B, LOW);
  }


}