#include <Keyboard.h>

const int buttonPins[] = {2, 3, 4, 5}; // Pinos dos botões
const char keyMap[] = {'a', 'b', 'c', 'd'}; // Letras enviadas
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]); 
const int debounceDelay = 50;

void setup() {
    Serial.begin(9600); // Inicia a comunicação serial com o PC
    for (int i = 0; i < numButtons; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }
    Keyboard.begin();
}

void loop() {
    for (int i = 0; i < numButtons; i++) {
        if (digitalRead(buttonPins[i]) == LOW) { // Se o botão foi pressionado
            delay(debounceDelay);
            if (digitalRead(buttonPins[i]) == LOW) { // Confirmação do botão pressionado
                Serial.println(keyMap[i]); // Envia a tecla pela Serial
                while (digitalRead(buttonPins[i]) == LOW); // Espera soltar o botão
            }
        }
    }
}
