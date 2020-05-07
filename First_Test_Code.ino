
const int  buttonPin = 8 ;    // the pin that the pushbutton is attached to
const int ledPin = 7;       // the pin that the LED is attached to
// Variables will change:
int counter = 1;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button



#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 1600
#define home_switchA 9
#define home_switchA2 10

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(home_switchA, INPUT_PULLUP);
  pinMode(home_switchA2, INPUT_PULLUP);
    // Set the spinning direction clockwise:
 pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);


}
void loop() {
    buttonState = digitalRead(buttonPin);
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // went from off to on:
      counter++;
      Serial.println(counter);
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  
   if (counter == 2) {
    digitalWrite(ledPin, HIGH);

  // Set the spinning direction clockwise:
  digitalWrite(dirPin, HIGH);
  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerRevolution && digitalRead(home_switchA) ; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(200);
  }
  delay(1000);
  // Set the spinning direction counterclockwise:
  digitalWrite(dirPin, LOW);
  // Spin the stepper motor 1 revolution quickly:
  for (int i = 0; i < stepsPerRevolution && digitalRead(home_switchA2); i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(200);
  }
  delay(500);
   
  }


 else if (counter == 1){
   digitalWrite(ledPin, LOW);

   // Set the spinning direction clockwise:
  digitalWrite(dirPin, HIGH);
  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerRevolution && digitalRead(home_switchA) ; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(400);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(400);
  }
  delay(1000);
  // Set the spinning direction counterclockwise:
  digitalWrite(dirPin, LOW);
  // Spin the stepper motor 1 revolution quickly:
  for (int i = 0; i < stepsPerRevolution && digitalRead(home_switchA2); i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(400);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(400);
  }
  delay(500); 
 }
 else if (counter>4)
 {
  counter =0;
  }
  
}
