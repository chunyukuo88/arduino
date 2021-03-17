// ******************************************************
// 
//            Mute Zoom quickly with a big red button
//
//           Designed for Adafruit Trinket M0
//                   
//                  by Alex Gochenour
//
// ******************************************************

// Add the keyboard library
#include <Keyboard.h>

void setup() {
 
    // Configure Pin 2 as input switch.
    // Triggered when connected to ground. 
    pinMode(2, INPUT_PULLUP);

    // Start running the board as a virtual computer keyboard
    Keyboard.begin();
  
}

void loop() {
  
    // Check for a button press event
    if (digitalRead(2) == LOW) {
   
        // Press command w and wait 1/10 second
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('a');
        delay(100);
    
        // Release all keyboard keys
        Keyboard.releaseAll();

        // Press the return key and wait 1/10 second
        Keyboard.press(KEY_RETURN);
        delay(100);
    
        // Release all keyboard keys
        Keyboard.releaseAll();

        // Wait for the pushbutton to be released before resuming
        while (digitalRead(2) == LOW){
           delay(1000);
        }
 
    }

}
