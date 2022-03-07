// ------------
// Blink name
// ------------
#include <map>

#define UNIT 200 // the unit time, controls the speed of blink
const int led = D7;
const char *name = "JESSIE"; // the name to blink in morse code

std::map<char, char*> morse_code { {'J', ".---",}, {'E', "."}, {'S', "..."}, {'I', ".."}};

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

void blink_char(char c) {
    int i = 0;
    while (morse_code[c][i]) {
        if (morse_code[c][i] == '.')
            dot();
        else
            dash();
        between_parts();
        i++;
    }
}

void blink_name() {
    int i = 0;
    while (name[i]) {
        blink_char(name[i]);
        between_letters();
        i++;
    }
}
        
// Next we have the loop function, the other essential part of a microcontroller program.
// This routine gets repeated over and over, as quickly as possible and as many times as possible, after the setup function is called.
// Note: Code that blocks for too long (like more than 5 seconds), 
// can make weird things happen (like dropping the network connection).  
// The built-in delay function shown below safely interleaves required background activity, 
// so arbitrarily long delays can safely be done if you need them.

void loop() {
    blink_name();
    between_words();
}


