// Define the LED pin
const int ledPin = 13;

// Define the push button pin
const int buttonPin = 2;

// Define Morse code for your first name
const char* morseCode = "- . - . . . . . . .  - . . - . - .";

// Define the Morse code timings (in milliseconds)
const int dotDuration = 200;
const int dashDuration = 600;
const int spaceDuration = 200; // Space between characters

// Variable to track whether the LED is currently blinking
bool isBlinking = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor for the button
  digitalWrite(ledPin, LOW); // Turn off the LED initially
}

void loop() {
  // Check if the button is pressed (buttonPin is LOW when pressed)
  if (digitalRead(buttonPin) == LOW) {
    if (!isBlinking) {
      blinkMorseCode();
      isBlinking = true;
    }
  } else {
    isBlinking = false;
  }
}

void blinkMorseCode() {
  for (int i = 0; morseCode[i]; i++) {
    char currentChar = morseCode[i];
    if (currentChar == ' ') {
      delay(spaceDuration);
    } else {
      if (currentChar == '.') {
        digitalWrite(ledPin, HIGH);
        delay(dotDuration);
      } else if (currentChar == '-') {
        digitalWrite(ledPin, HIGH);
        delay(dashDuration);
      }
      digitalWrite(ledPin, LOW);
      delay(spaceDuration); // Space between dots and dashes
    }
  }
}
