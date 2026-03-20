const int pinoPIR    = 11;
const int pinoBuzzer = 8;
const int ledRed     = 5;
const int ledBlue    = 6;
const int ledGreen   = 7;

void setup() {
  pinMode(pinoPIR, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  Serial.begin(9600);
  Serial.println("SISTEMA MONITORANDO: VERDE ATIVADO");
  
  // Aguarda o sensor PIR estabilizar (Warm-up)
  delay(5000); 
}

void loop() {
  int movimento = digitalRead(pinoPIR);

  if (movimento == HIGH) { // INTRUSO DETECTADO
    Serial.println("!!! ALERTA VERMELHO !!!");

    // Desliga Verde e Azul, liga apenas Vermelho
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledBlue, LOW);
    digitalWrite(ledRed, HIGH);

    // Sirene Descendente (1000Hz para 500Hz)
    for (int freq = 1000; freq > 500; freq -= 10) {
      tone(pinoBuzzer, freq);
      delay(5);
    }
  } 
  else { // CAMINHO LIVRE
    noTone(pinoBuzzer);
    
    // Garante que o Vermelho apague e o Verde brilhe puro
    digitalWrite(ledRed, LOW);
    digitalWrite(ledBlue, LOW);
    digitalWrite(ledGreen, HIGH);
  }

  delay(50); 
}
