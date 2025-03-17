# 🎮 Controle de Quiz com Arduino Leonardo

Este projeto implementa um controle de quiz utilizando um **Arduino Leonardo** com 5 botões físicos. Quatro botões são usados para enviar respostas ("a", "b", "c" e "d") e um quinto botão serve para **resetar o quiz**, limpando as respostas armazenadas no backend.

## 📌 Funcionalidades
✅ Envio de respostas ("a", "b", "c", "d") para um backend via comunicação **Serial**.  
✅ Botão de **reset** para limpar as respostas no backend.  
✅ Utilização da biblioteca **Keyboard.h** para simular entrada de teclado.  
✅ Comunicação **sem necessidade de internet**, usando **porta Serial**.  

---

## 🛠 Componentes Utilizados
- **Arduino Leonardo**
- **5 Botões Push Button**
- **Resistores Pull-up Internos** (ativados via código)
- **Cabo USB para comunicação com o PC**

---


## 🔧 Como Testar
1. **Suba o código no Arduino Leonardo** usando a **IDE do Arduino**.
2. **Descubra a porta Serial** do Arduino:
   - No Windows: **Gerenciador de Dispositivos > Portas (COM & LPT)**.
   - No Linux/Mac: Execute `ls /dev/ttyUSB*` no terminal.
3. **Edite o script Python** e configure a **porta COM correta**.
4. **Execute o backend Python** (`python backend.py`).
5. **Pressione os botões** no Arduino e veja as respostas chegando no terminal.
6. **Pressione o botão de reset** para limpar as respostas do quiz.

---

## 🎯 Possíveis Melhorias
- 🔹 Adicionar **feedback visual** (LEDs para indicar respostas enviadas).
- 🔹 Implementar **som** para alertar sobre respostas corretas/erradas.
- 🔹 Criar uma **interface gráfica** para visualizar as respostas.
- 🔹 Expandir para suportar mais botões e opções de quiz.