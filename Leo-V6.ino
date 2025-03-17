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

    // Verifica se uma alternativa foi pressionada
    for (int i = 0; i < numButtons; i++) {
        if (digitalRead(buttonPins[i]) == LOW) {
            delay(debounceDelay);
            if (digitalRead(buttonPins[i]) == LOW) {
                selectedOption = 'a' + i; // Mapeia 'a', 'b', 'c', 'd'
                Serial.println(String("Selecionado: ") + selectedOption);
                while (digitalRead(buttonPins[i]) == LOW); // Aguarda soltar o botão
            }
        }
    }

    // Verifica se o botão de confirmação foi pressionado
    if (digitalRead(confirmButton) == LOW) {
        delay(debounceDelay);
        if (digitalRead(confirmButton) == LOW) {
            unsigned long currentTime = millis();

            // Duplo clique no botão de confirmação = "foto"
            if (currentTime - lastConfirmPress < 400) { 
                Serial.println("foto");
            } else if (selectedOption != '\0') {
                Serial.println(selectedOption); // Confirma a alternativa
                selectedOption = '\0'; // Reseta a seleção
            }

            lastConfirmPress = currentTime;
            while (digitalRead(confirmButton) == LOW);
        }
    }

    // Verifica se "A" e "D" foram pressionados ao mesmo tempo para reset
    if (digitalRead(buttonPins[0]) == LOW) aPressed = true; // "A" (botão 0)
    if (digitalRead(buttonPins[3]) == LOW) dPressed = true; // "D" (botão 3)

    if (aPressed && dPressed) {
        delay(debounceDelay);
        if (digitalRead(buttonPins[0]) == LOW && digitalRead(buttonPins[3]) == LOW) {
            Serial.println("reset"); // Comando de reset
            while (digitalRead(buttonPins[0]) == LOW || digitalRead(buttonPins[3]) == LOW);
        }
    }
}
