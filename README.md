# 🎮 Controle de Quiz com Arduino Leonardo projeto Chico

## 📌 Sobre o Projeto
Este projeto utiliza um **Arduino Leonardo** para criar um **controle de quiz para o Chico** com botões físicos. As respostas selecionadas são enviadas para um **backend em Python** via comunicação serial.

## ⚙️ Funcionalidades
- **Seleção de Respostas**: Botões físicos permitem escolher alternativas (`A`, `B`, `C`, `D`).
- **Confirmação**: A resposta só é enviada ao pressionar o botão "R".
- **Reset do Quiz**: Pressionar os botões `A` + `D` simultaneamente reseta o quiz.
- **Comando "Foto"**: Pressionar "R" duas vezes seguidas envia o comando `foto`.

---

## 🛠️ Hardware Necessário
- **Arduino Leonardo**
- **5 Botões** (Alternativas `A`, `B`, `C`, `D` + Confirmação `R`)
- **Jumpers e protoboard**

### 🎛️ **Esquema de Conexão**
| Botão | Pino Arduino |
|--------|------------|
| `A` | `2` |
| `B` | `3` |
| `C` | `4` |
| `D` | `5` |
| `R` (Confirmação) | `6` |

Cada botão deve ser conectado a um pino digital com um **pull-up interno** (`INPUT_PULLUP`).

---

## 💻 Código do Arduino
O código do **Arduino Leonardo** detecta a pressão dos botões e envia as informações via **Serial**.


---

## 🖥️ Código do Backend em Python
O backend recebe os dados do Arduino pela porta serial e processa os comandos.

---

## 🚀 Como Rodar o Projeto

### 1️⃣ **Carregar o Código no Arduino**
1. Conecte o **Arduino Leonardo** ao computador via **cabo USB**.
2. Abra a **IDE do Arduino**.
3. Copie o código do Arduino e cole na IDE.
4. **Selecione a placa**:
   - Vá em **Ferramentas > Placa > Arduino Leonardo**.
5. **Selecione a porta**:
   - Vá em **Ferramentas > Porta** e selecione a porta COM correspondente (Ex: `COM3` no Windows ou `/dev/ttyACM0` no Linux).
6. Clique no **botão de upload** (seta para a direita) para enviar o código para o Arduino.

---

### 2️⃣ **Rodar o Backend em Python**
1. Certifique-se de que o Arduino está conectado ao PC.
2. Instale a biblioteca necessária (caso ainda não tenha):
   ```bash
   pip install pyserial
   ```
3. Descubra a porta serial do Arduino:
   - **No Windows**:
     - Abra o **Gerenciador de Dispositivos** e procure por "Portas (COM & LPT)".
     - Identifique algo como `COM3`, `COM4`, etc.
   - **No Linux/macOS**:
     - Execute o comando:
       ```bash
       ls /dev/tty*
       ```
     - O Arduino geralmente aparece como `/dev/ttyACM0` ou `/dev/ttyUSB0`.

4. Edite o código Python e altere a variável `porta_serial` conforme necessário.

5. Execute o backend Python:
   - No **Windows**:
     ```bash
     python back-V3.py
     ```
   - No **Linux/macOS**:
     ```bash
     python3 back-V3.py
     ```

---

## ✅ **Testando o Funcionamento**
1. Pressione os botões no controle do Arduino.
2. Veja se os dados aparecem no **Monitor Serial da IDE do Arduino** e no **terminal do Python**.
3. Se `a`, `b`, `c`, `d`, `reset` ou `foto` aparecerem no terminal do Python, significa que a comunicação está funcionando!


---

## 📚 Tecnologias Utilizadas
- **Arduino Leonardo**
- **C++ (Arduino)**
- **Python (Backend Serial)**

---

## 🎯 Melhorias Futuras
- Implementar comunicação por led para indentificar que o botao foi acionado.
- Criar uma interface gráfica para exibir o quiz em tempo real.

---

## 📌 Autor
👨‍💻 **PV-Lopes** - Desenvolvedor do projeto.

