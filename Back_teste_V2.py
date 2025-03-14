import serial

# Configuração da porta serial
porta_serial = "COM3"  # No Windows (Ex: COM3, COM4)
# porta_serial = "/dev/ttyUSB0"  # No Linux/Mac

baud_rate = 9600
respostas_usuario = []

try:
    arduino = serial.Serial(porta_serial, baud_rate)
    print(f"Conectado ao Arduino na porta {porta_serial}")

    while True:
        if arduino.in_waiting > 0:
            resposta = arduino.readline().decode("utf-8").strip()  # Lê a entrada serial
            print(f"Resposta recebida: {resposta}")

            if resposta == "reset":
                respostas_usuario.clear()  # Limpa as respostas do usuário
                print("🔄 Quiz resetado! Todas as respostas foram apagadas.")
            else:
                respostas_usuario.append(resposta)
                print(f"📌 Respostas até agora: {respostas_usuario}")

except serial.SerialException:
    print("Erro ao conectar ao Arduino. Verifique a porta Serial!")
