
// Pin numbers
const int buttonPower = 4;
const int buttonStart = 2;
const int buttonStop = 3;
const int dial1 = A2; // blue
const int dial2 = A3; // green
const int dial3 = A4; // yellow
const int dial4 = A5; // orange
const int opto1 = 8; // blue
const int opto2 = 9; // green
const int opto3 = 10; // yellow
const int opto4 = 11; // orange

// Maxs for the analog values
const long max1 = 681;
const long max2 = 681;
const long max3 = 681;
const long max4 = 681;

// How long to pour for max for each valve
// For 3x5 it's approx 80ml / min
const long maxPour1 = 120000;
const long maxPour2 = 120000;
const long maxPour3 = 120000;
const long maxPour4 = 120000;

// For reading data
long state1 = 0;
long state2 = 0;
long state3 = 0;
long state4 = 0;

// Whether the system is doing nothing (0), pouring (1)
boolean isPouring = false;

// How long to wait between iterations
int milliPer = 5;

// Runs once at the start
void setup(){
  
  // Init the input pins
  pinMode(buttonStart, INPUT_PULLUP);
  pinMode(buttonStop, INPUT_PULLUP);
  pinMode(dial1, INPUT);
  pinMode(dial2, INPUT);
  pinMode(dial3, INPUT);
  pinMode(dial4, INPUT);
  
  // Init the output pins
  pinMode(opto1, OUTPUT);
  pinMode(opto2, OUTPUT);
  pinMode(opto3, OUTPUT);
  pinMode(opto4, OUTPUT);
  pinMode(buttonPower, OUTPUT);
  digitalWrite(opto1, HIGH); 
  digitalWrite(opto2, HIGH); 
  digitalWrite(opto3, HIGH); 
  digitalWrite(opto4, HIGH);
  digitalWrite(buttonPower, HIGH);
  
}

// Convert the analog value to milliseconds
long analogToMilli(int analog, long maxVal, long maxPour) {
  return (maxPour * analog) / maxVal;
}

// Runs forever after the setup
void loop() {
  
  // If not doing anything yet
  if (!isPouring) {

    // If the start button is pressed
    if (digitalRead(buttonStart) == LOW) {
      
      // Start pouring
      isPouring = true;
      
      // Get the amounts from the dials and convert
      state1 = analogToMilli(analogRead(dial1), max1, maxPour1);
      state2 = analogToMilli(analogRead(dial2), max2, maxPour2);
      state3 = analogToMilli(analogRead(dial3), max3, maxPour3);
      state4 = analogToMilli(analogRead(dial4), max4, maxPour4);
      
      // Start pouring
      if (state1 > 0) {
        digitalWrite(opto1, LOW);
      } 
      if (state2 > 0) {
        digitalWrite(opto2, LOW);
      }
      if (state3 > 0) {
        digitalWrite(opto3, LOW); 
      }
      if (state4 > 0) {
        digitalWrite(opto4, LOW);
      }
      
    }
    
  // If currently pouring
  } else {
    
    // If the stop button is pressed
    if (digitalRead(buttonStop) == LOW) {
      
      // Stop pouring
      isPouring = false;
      state1 = 0;
      state2 = 0;
      state3 = 0;
      state4 = 0;
      digitalWrite(opto1, HIGH); 
      digitalWrite(opto2, HIGH); 
      digitalWrite(opto3, HIGH); 
      digitalWrite(opto4, HIGH); 
      
    // Otherwise pour
    } else {
      
      // Check if liquid 1 should keep pouring
      if (state1 > 0) {
        state1 -= milliPer;
        if (state1 <= 0) {
          digitalWrite(opto1, HIGH); 
        }
      }
      
      // Check if liquid 2 should keep pouring
      if (state2 > 0) {
        state2 -= milliPer;
        if (state2 <= 0) {
          digitalWrite(opto2, HIGH); 
        }
      }
      
      // Check if liquid 3 should keep pouring
      if (state3 > 0) {
        state3 -= milliPer;
        if (state3 <= 0) {
          digitalWrite(opto3, HIGH); 
        }
      }
      
      // Check if liquid 5 should keep pouring
      if (state4 > 0) {
        state4 -= milliPer;
        if (state4 <= 0) {
          digitalWrite(opto4, HIGH); 
        }
      }
      
      // Once all are finished, stop
      if (state1 <= 0 && state2 <= 0 && state3 <=0 && state4 <= 0) {
        
        // Reset the state
        isPouring = false;
        state1 = 0;
        state2 = 0;
        state3 = 0;
        state4 = 0;
      
      }
    
    }
    
  }
  
  // Slight delay for timings
  delay(milliPer);
  
}
