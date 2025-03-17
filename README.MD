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

## 🚀 Como Usar
1. **Conecte o Arduino Leonardo** ao computador.
2. **Carregue o código no Arduino** através do Arduino IDE.
3. **Execute o backend Python**:
   ```bash
   python back-V3.py
   ```
4. **Interaja com os botões**:
   - Selecione uma alternativa (`A`, `B`, `C`, `D`).
   - Pressione `R` para confirmar.
   - Pressione `A` + `D` ao mesmo tempo para resetar.
   - Pressione `R` duas vezes rapidamente para ativar "foto".

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

