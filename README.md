como Funciona? /n
-O Arduino envia as letras a, b, c, d pela porta Serial ao pressionar um botão.
-O script Python no PC recebe os dados Serial e processa as respostas do usuário.
-O Python pode verificar se a resposta está correta, sem precisar de internet.

Como Testar?
-Suba o código no Arduino Leonardo usando a IDE do Arduino.
-Descubra a porta COM do seu Arduino:
  No Windows: Vá até o Gerenciador de Dispositivos > Portas (COM & LPT).
  No Linux/Mac: Execute ls /dev/ttyUSB* no terminal.
-Edite o script Python e substitua "COM3" pela porta correta.
-Execute o script Python e pressione os botões do Arduino para ver os inputs chegando no terminal.
