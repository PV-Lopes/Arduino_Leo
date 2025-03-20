#include <Keyboard.h>

const int buttonPins[] = {2, 3, 4, 5, 6}; // Pinos dos botões A, B, C, D, I
const int debounceDelay = 50;
unsigned long lastPressTime = 0;
bool iPressedOnce = false;

void setup() {
    Serial.begin(9600);
    Keyboard.begin();
    
    for (int i = 0; i < 5; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }
}

void loop() {
    for (int i = 0; i < 5; i++) {
        if (digitalRead(buttonPins[i]) == LOW) {
            delay(debounceDelay);

            char key;
            switch (i) {
                case 0: key = 'a'; break;
                case 1: key = 'b'; break;
                case 2: key = 'c'; break;
                case 3: key = 'd'; break;
                case 4: 
                    unsigned long currentTime = millis();
                    if (iPressedOnce && (currentTime - lastPressTime < 400)) {
                        key = 'f'; 
                        iPressedOnce = false;
                    } else {
                        key = 'i';
                        iPressedOnce = true;
                    }
                    lastPressTime = currentTime;
                    break;
            }

            Serial.println(key);
            Keyboard.print(key);

            while (digitalRead(buttonPins[i]) == LOW);
        }
    }
}
