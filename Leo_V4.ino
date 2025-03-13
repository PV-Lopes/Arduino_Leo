#include <Keyboard.h>

const int buttonPins[] = {2, 3, 4, 5, 6}; // Pinos dos botões (inclui o reset)
const char keyMap[] = {'a', 'b', 'c', 'd', 'R'}; // "R" será interpretado como reset
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]); 
const int debounceDelay = 50;

void setup() {
    Serial.begin(9600); // Comunicação Serial
    for (int i = 0; i < numButtons; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }
    Keyboard.begin();
}

void loop() {
    for (int i = 0; i < numButtons; i++) {
        if (digitalRead(buttonPins[i]) == LOW) { // Botão pressionado
            delay(debounceDelay);
            if (digitalRead(buttonPins[i]) == LOW) { // Confirma que ainda está pressionado
                if (keyMap[i] == 'R') {
                    Serial.println("reset"); // Envia o comando de reset
                } else {
                    Serial.println(keyMap[i]); // Envia a resposta normal (a, b, c, d)
                }
                while (digitalRead(buttonPins[i]) == LOW); // Aguarda soltar o botão
            }
        }
    }
}
