#include <Keyboard.h>

// Definição dos pinos dos botões
const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;

void setup() {
    // Configurar os pinos como entrada com pull-up interno
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
    pinMode(button3, INPUT_PULLUP);
    pinMode(button4, INPUT_PULLUP);

    // Inicializa a comunicação do teclado
    Keyboard.begin();
}

void loop() {
    if (digitalRead(button1) == LOW) {
        Keyboard.print("a"); // Envia a tecla "a"
        delay(300); // Pequeno atraso para evitar múltiplos envios
    }

    if (digitalRead(button2) == LOW) {
        Keyboard.print("b"); // Envia a tecla "b"
        delay(300);
    }

    if (digitalRead(button3) == LOW) {
        Keyboard.print("c"); // Envia a tecla "c"
        delay(300);
    }

    if (digitalRead(button4) == LOW) {
        Keyboard.print("d"); // Envia a tecla "d"
        delay(300);
    }
}
