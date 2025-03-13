import serial #Não esquecer de baixar

# Configuração da porta serial (verifique qual porta seu Arduino está usando)
porta_serial = "COM3"  # No Windows (Ex: COM3, COM4)
# porta_serial = "/dev/ttyUSB0"  # No Linux/Mac

baud_rate = 9600  # Deve ser o mesmo do código Arduino

try:
    arduino = serial.Serial(porta_serial, baud_rate)
    print(f"Conectado ao Arduino na porta {porta_serial}")

    while True:
        if arduino.in_waiting > 0:
            resposta = arduino.readline().decode("utf-8").strip()  # Lê a resposta do Arduino
            print(f"Resposta recebida: {resposta}")

            # Aqui você pode processar a resposta e determinar se está correta
            resposta_correta = "b"  # Exemplo de resposta correta
            if resposta == resposta_correta:
                print("✅ Resposta correta!")
            else:
                print("❌ Resposta incorreta!")

except serial.SerialException:
    print("Erro ao conectar ao Arduino. Verifique a porta Serial!")
