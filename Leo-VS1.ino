#include <Keyboard.h>

const int buttonPins[] = {2, 3, 4, 5, 6}; // Pinos dos botões A, B, C, D, I
const int debounceDelay = 50; // Tempo para evitar leitura duplicada
unsigned long lastPressTime = 0; // Armazena o tempo da última pressão do botão "I"
bool iPressedOnce = false; // Verifica se o "I" foi pressionado uma vez

void setup() {
    Serial.begin(9600);
    Keyboard.begin();
    
    // Configura todos os botões como entrada com pull-up interno
    for (int i = 0; i < 5; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }
}

void loop() {
    for (int i = 0; i < 5; i++) {
        if (digitalRead(buttonPins[i]) == LOW) {
            delay(debounceDelay); // Evita múltiplas leituras devido ao bouncing

            char key = 'a' + i; // Calcula a letra com base no índice (2 -> 'a', 3 -> 'b', etc.)

            if (key == 'i') { 
                unsigned long currentTime = millis();
                
                if (iPressedOnce && (currentTime - lastPressTime < 400)) {
                    Serial.println("f"); // Envia "f" se o "i" foi pressionado duas vezes rapidamente
                    Keyboard.print("f");
                    iPressedOnce = false; // Reseta o estado
                } else {
                    Serial.println("i");
                    Keyboard.print("i");
                    iPressedOnce = true;
                }

                lastPressTime = currentTime; // Atualiza o tempo da última pressão
            } else {
                Serial.println(key);
                Keyboard.print(key);
            }

            while (digitalRead(buttonPins[i]) == LOW); // Espera o botão ser solto
        }
    }
}
