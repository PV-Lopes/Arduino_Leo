import serial

# Configuração da porta Serial
porta_serial = "COM3"  # No Windows (Ex: COM3, COM4)
# porta_serial = "/dev/ttyUSB0"  # No Linux/Mac

baud_rate = 9600
respostas_usuario = []

try:
    arduino = serial.Serial(porta_serial, baud_rate)
    print(f"📡 Conectado ao Arduino na porta {porta_serial}")

    while True:
        if arduino.in_waiting > 0:
            resposta = arduino.readline().decode("utf-8").strip()  # Lê a entrada serial
            print(f"🔹 Recebido: {resposta}")

            match resposta:
                case "a" | "b" | "c" | "d":  # Respostas confirmadas do quiz
                    respostas_usuario.append(resposta)
                    print(f"✅ Resposta confirmada: {resposta}")
                
                case "reset":  # Reset do quiz (A + D pressionados)
                    respostas_usuario.clear()
                    print("🔄 Quiz resetado!")

                case "foto":  # Comando de captura de foto (duplo clique no R)
                    print("📸 Foto solicitada!")

                case _:  # Caso padrão (entrada desconhecida)
                    print("⚠ Comando desconhecido!")

except serial.SerialException:
    print("❌ Erro ao conectar ao Arduino. Verifique a porta Serial!")
