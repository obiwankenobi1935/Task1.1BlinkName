// Pin definitions
const int ledPin = LED_BUILTIN;  
const int buttonPin = 2;         

// Morse code timing
const int dotDuration = 200;   
const int dashDuration = 600;   
const int intraCharGap = 200;  
const int interCharGap = 600;   

void setup() {
  pinMode(ledPin, OUTPUT);       
  pinMode(buttonPin, INPUT_PULLUP); 
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { 
    blinkMorse("Kavish");              
    delay(1000);                       
  }
}

void blinkMorse(const char* text) {
  while (*text) {
    switch (toupper(*text)) {
      case 'K':
        dash(); dot(); dash();
        break;
      case 'A':
        dot(); dash();
        break;
      case 'V':
        dot(); dot(); dot(); dash();
        break;
      case 'I':
        dot(); dot();
        break;
      case 'S':
        dot(); dot(); dot();
        break;
      case 'H':
        dot(); dot(); dot(); dot();
        break;
    }
    delay(interCharGap); 
    text++;              
  }
}

void dot() {
  digitalWrite(ledPin, HIGH);
  delay(dotDuration);
  digitalWrite(ledPin, LOW);
  delay(intraCharGap);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delay(dashDuration);
  digitalWrite(ledPin, LOW);
  delay(intraCharGap);
}
