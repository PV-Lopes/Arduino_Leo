#include <Keyboard.h>

const int buttonPins[] = {2, 3, 4, 5}; // Pinos dos botões
const char keyMap[] = {'a', 'b', 'c', 'd'}; // Letras enviadas
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]); // Número de botões
const int debounceDelay = 50; // Tempo de debounce em milissegundos

void setup() {
    for (int i = 0; i < numButtons; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP); // Configura os botões como entrada pull-up
    }
    Keyboard.begin(); // Inicializa a biblioteca Keyboard
}

void loop() {
    for (int i = 0; i < numButtons; i++) {
        if (digitalRead(buttonPins[i]) == LOW) { // Se o botão for pressionado
            delay(debounceDelay); // Aguarda para evitar múltiplos cliques indesejados
            if (digitalRead(buttonPins[i]) == LOW) { // Confirma que ainda está pressionado
                Keyboard.print(keyMap[i]); // Envia a tecla correspondente
                while (digitalRead(buttonPins[i]) == LOW); // Aguarda o botão ser solto
            }
        }
    }
}
