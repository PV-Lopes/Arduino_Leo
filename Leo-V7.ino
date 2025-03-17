#include <Keyboard.h>

const int buttonPins[] = {2, 3, 4, 5}; // Pinos dos botões (A, B, C, D)
const int confirmButton = 6; // Botão de confirmação (R)
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);
const int debounceDelay = 50;

char selectedOption = '\0'; // Alternativa selecionada
unsigned long lastConfirmPress = 0; // Para verificar duplo clique no botão R

void setup() {
    Serial.begin(9600);
    for (int i = 0; i < numButtons; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }
    pinMode(confirmButton, INPUT_PULLUP);
    Keyboard.begin();
}

void loop() {
    bool aPressed = false;
    bool dPressed = false;

    for (int i = 0; i < numButtons; i++) {
        if (digitalRead(buttonPins[i]) == LOW) {
            delay(debounceDelay);
            if (digitalRead(buttonPins[i]) == LOW) {
                selectedOption = 'a' + i; // Mapeia 'a', 'b', 'c', 'd'
                Serial.println(String("Selecionado: ") + selectedOption);
                while (digitalRead(buttonPins[i]) == LOW);
            }
        }
    }

    if (digitalRead(confirmButton) == LOW) {
        delay(debounceDelay);
        if (digitalRead(confirmButton) == LOW) {
            unsigned long currentTime = millis();

            switch (selectedOption) {
                case 'a':
                case 'b':
                case 'c':
                case 'd':
                    Serial.println(selectedOption); // Confirma a alternativa
                    selectedOption = '\0'; // Reseta a seleção
                    break;

                default:
                    if (currentTime - lastConfirmPress < 400) { 
                        Serial.println("foto"); // Duplo clique em R → "foto"
                    }
                    break;
            }

            lastConfirmPress = currentTime;
            while (digitalRead(confirmButton) == LOW);
        }
    }

    if (digitalRead(buttonPins[0]) == LOW) aPressed = true; // "A"
    if (digitalRead(buttonPins[3]) == LOW) dPressed = true; // "D"

    if (aPressed && dPressed) {
        delay(debounceDelay);
        if (digitalRead(buttonPins[0]) == LOW && digitalRead(buttonPins[3]) == LOW) {
            Serial.println("reset"); // Reset ao pressionar A + D
            while (digitalRead(buttonPins[0]) == LOW || digitalRead(buttonPins[3]) == LOW);
        }
    }
}
