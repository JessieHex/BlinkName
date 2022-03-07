// ------------
// Blink name
// ------------
#define UNIT 200 // the unit time
const int led = D7;

void setup() {
  pinMode(led, OUTPUT);
}

 // The length of a dot is one unit
void dot() {
    digitalWrite(led, HIGH);
    delay(UNIT);
}

// A dash is three units
void dash() {
    digitalWrite(led, HIGH);
    delay(UNIT * 3);
}

// The space between parts of the same letter is one unit
void between_parts() {
    digitalWrite(led, LOW);
    delay(UNIT);
}

// The space between letters is three units
void between_letters() {
    digitalWrite(led, LOW);
    delay(UNIT * 3);
}

// The space between words is seven units
void between_words() {
    digitalWrite(led, LOW);
    delay(UNIT * 7);
}


        
// Next we have the loop function, the other essential part of a microcontroller program.
// This routine gets repeated over and over, as quickly as possible and as many times as possible, after the setup function is called.
// Note: Code that blocks for too long (like more than 5 seconds), 
// can make weird things happen (like dropping the network connection).  
// The built-in delay function shown below safely interleaves required background activity, 
// so arbitrarily long delays can safely be done if you need them.

void loop() {
    // J '.---'
    dot();
    between_parts();
    dash();
    between_parts();
    dash();
    between_parts();
    dash();
    between_letters();
    // E '.'
    dot();
    between_letters();
    // S '...'
    dot();
    between_parts();
    dot();
    between_parts();
    dot();
    between_letters();
    // S '...'
    dot();
    between_parts();
    dot();
    between_parts();
    dot();
    between_letters();
    // I '..'
    dot();
    between_parts();
    dot();
    between_letters();
    // E '.'
    dot();
    between_words();
}
