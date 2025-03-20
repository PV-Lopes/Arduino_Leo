#include <Keyboard.h>

const int botao1 = 8;
const int botao2 = 9;
const int botao3 = 10;
const int botao4 = 11;
const int botao5 = 12;

const int debounceDelay = 50;

void setup() {
    Serial.begin(9600);
    
    pinMode(botao1, INPUT_PULLUP);
    pinMode(botao2, INPUT_PULLUP);
    pinMode(botao3, INPUT_PULLUP);
    pinMode(botao4, INPUT_PULLUP);
    pinMode(botao5, INPUT_PULLUP);

    Keyboard.begin(); // Inicializa a comunicação com o teclado
}

void loop() {
    if (digitalRead(botao1) == LOW) {
        Keyboard.press('a');
        Serial.println("Botão A pressionado");
        delay(debounceDelay);
    } else {
        Keyboard.release('a');
    }

    if (digitalRead(botao2) == LOW) {
        Keyboard.press('b');
        Serial.println("Botão B pressionado");
        delay(debounceDelay);
    } else {
        Keyboard.release('b');
    }

    if (digitalRead(botao3) == LOW) {
        Keyboard.press('c');
        Serial.println("Botão C pressionado");
        delay(debounceDelay);
    } else {
        Keyboard.release('c');
    }

    if (digitalRead(botao4) == LOW) {
        Keyboard.press('d');
        Serial.println("Botão D pressionado");
        delay(debounceDelay);
    } else {
        Keyboard.release('d');
    }
    if(digitalRead(botao5)  == LOW){
      Keyboard.press('e');
      Serial.println("Botão E pressionado");
      delay(debounceDelay);
    }else{
      Keyboard.release('e');
    }  
}