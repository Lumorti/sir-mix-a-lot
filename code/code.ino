
// Pin numbers
int buttonStart = 0;
int buttonStop = 1;
int dial1 = A2;
int dial2 = A3;
int dial3 = A4;
int dial4 = A5;
int opto1 = 13;
int opto2 = 12;
int opto3 = 11;
int opto4 = 10;

// For reading data
int stateStart = 0;
int stateStop = 0;
int state1 = 0;
int state2 = 0;
int state3 = 0;
int state4 = 0;

// Whether the system is doing nothing (0), pouring (1)
boolean isPouring = false;

// Runs once at the start
void setup(){
  
  // Init the input pins
  pinMode(buttonStart, INPUT);
  pinMode(buttonStop, INPUT);
  pinMode(dial1, INPUT);
  pinMode(dial2, INPUT);
  pinMode(dial3, INPUT);
  pinMode(dial4, INPUT);
  
  // Init the output pins
  pinMode(opto1, OUTPUT);
  pinMode(opto2, OUTPUT);
  pinMode(opto3, OUTPUT);
  pinMode(opto4, OUTPUT);
  
}

// Runs forever after the setup
void loop(){
  
  // If not doing anything yet
  if (!isPouring){

    // If the start button is pressed
    if (digitalRead(buttonStart) == HIGH){
      
      // Start pouring
      isPouring = true;
      
      // Get the amounts from the dials (between 0 and 1023)
      state1 = analogRead(dial1);
      state2 = analogRead(dial2);
      state3 = analogRead(dial3);
      state4 = analogRead(dial4);
      
      // Start pouring
      digitalWrite(opto1, HIGH); 
      digitalWrite(opto2, HIGH); 
      digitalWrite(opto3, HIGH); 
      digitalWrite(opto4, HIGH); 
      
    }
    
    // Check if liquid 1 should keep pouring
    if (state1 > 0){
      state1 -= 1;
      if (state1 == 0){
       digitalWrite(opto1, LOW); 
      }
    }
    
    // Check if liquid 2 should keep pouring
    if (state2 > 0){
      state2 -= 1;
      if (state2 == 0){
       digitalWrite(opto2, LOW); 
      }
    }
    
    // Check if liquid 3 should keep pouring
    if (state3 > 0){
      state3 -= 1;
      if (state3 == 0){
       digitalWrite(opto3, LOW); 
      }
    }
    
    // Check if liquid 5 should keep pouring
    if (state4 > 0){
      state4 -= 1;
      if (state4 == 0){
       digitalWrite(opto4, LOW); 
      }
    }
    
  // If currently pouring
  } else {
    
    // If the stop button is pressed
    if (digitalRead(buttonStop) == HIGH){
      
      // Stop pouring
      isPouring = false;
      digitalWrite(opto1, LOW); 
      digitalWrite(opto2, LOW); 
      digitalWrite(opto3, LOW); 
      digitalWrite(opto4, LOW); 
      
    }
    
  }
  
  // Slight delay for timings
  delay(10);
  
}
