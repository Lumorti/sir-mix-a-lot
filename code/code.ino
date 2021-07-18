
// Pin numbers
int buttonStart = 2;
int buttonStop = 3;
int dial1 = A2;
int dial2 = A3;
int dial3 = A5;
int dial4 = A4;
int opto1 = 13;
int opto2 = 12;
int opto3 = 11;
int opto4 = 10;

// Maxs for the analog values
int max1 = 685;
int max2 = 685;
int max3 = 685;
int max4 = 685;

// How long to pour for max for each valve
int maxPour1 = 5000;
int maxPour2 = 5000;
int maxPour3 = 5000;
int maxPour4 = 5000;

// For reading data
int state1 = 0;
int state2 = 0;
int state3 = 0;
int state4 = 0;

// Whether the system is doing nothing (0), pouring (1)
boolean isPouring = false;

// How long to wait between iterations
int milliPer = 1000;

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
  digitalWrite(opto1, LOW); 
  digitalWrite(opto2, LOW); 
  digitalWrite(opto3, LOW); 
  digitalWrite(opto4, LOW);
  
  // For debugging
  Serial.begin(9600);
  
}

// Convert the analog value to milliseconds
int analogToMilli(int analog, int maxVal, int maxPour){
 return (maxPour * analog) / maxVal; 
}

// Runs forever after the setup
void loop(){
  
  Serial.print(isPouring);
  Serial.print(" ");
  Serial.print(analogRead(dial1));
  Serial.print(" ");
  Serial.print(analogRead(dial2));
  Serial.print(" ");
  Serial.print(analogRead(dial3));
  Serial.print(" ");
  Serial.print(analogRead(dial4));
  Serial.println();
  
  // If not doing anything yet
  if (!isPouring){

    // If the start button is pressed
    if (digitalRead(buttonStart) == LOW){
      
      // Start pouring
      isPouring = true;
      
      // Get the amounts from the dials and convert
      state1 = analogToMilli(analogRead(dial1), max1, maxPour1);
      state2 = analogToMilli(analogRead(dial2), max2, maxPour2);
      state3 = analogToMilli(analogRead(dial3), max3, maxPour3);
      state4 = analogToMilli(analogRead(dial4), max4, maxPour4);
      
      // Start pouring
      //digitalWrite(opto1, HIGH); 
      //digitalWrite(opto2, HIGH); 
      //digitalWrite(opto3, HIGH); 
      //digitalWrite(opto4, HIGH); 
      
    }
    
  // If currently pouring
  } else {
    
    // If the stop button is pressed
    if (digitalRead(buttonStop) == LOW){
      
      // Stop pouring
      isPouring = false;
      state1 = 0;
      state2 = 0;
      state3 = 0;
      state4 = 0;
      //digitalWrite(opto1, LOW); 
      //digitalWrite(opto2, LOW); 
      //digitalWrite(opto3, LOW); 
      //digitalWrite(opto4, LOW); 
      
    // Otherwise pour
    } else {
      
      // Check if liquid 1 should keep pouring
      if (state1 > 0){
        state1 -= milliPer;
        if (state1 == 0){
         //digitalWrite(opto1, LOW); 
        }
      }
      
      // Check if liquid 2 should keep pouring
      if (state2 > 0){
        state2 -= milliPer;
        if (state2 == 0){
         //digitalWrite(opto2, LOW); 
        }
      }
      
      // Check if liquid 3 should keep pouring
      if (state3 > 0){
        state3 -= milliPer;
        if (state3 == 0){
         //digitalWrite(opto3, LOW); 
        }
      }
      
      // Check if liquid 5 should keep pouring
      if (state4 > 0){
        state4 -= milliPer;
        if (state4 == 0){
         //digitalWrite(opto4, LOW); 
        }
      }
      
      // Once all are finished, stop
      if (state1 <= 0 && state2 <= 0 && state3 <=0 && state4 <= 0){
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
