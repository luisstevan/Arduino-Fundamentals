const int pinoSensor = 11;
const int pinoBuzzer = 8;
const int ledRed = 5;
const int ledGreen = 7;
const int ledBlue = 6;

void setup() {
  pinMode(pinoSensor, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("--- SISTEMA MONITORANDO ---");
}

void loop() {
  int detectou = digitalRead(pinoSensor); // Lemos apenas uma vez aqui

  if (detectou == LOW) { // Lógica Inversa: 0V = Objeto presente
    Serial.println("!!! INTRUSO DETECTADO !!!");
    
    // Status Visual: Alerta Vermelho
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledBlue, LOW);
    
    // Som da Sirene (Descendo a frequência)
    for (int freq = 1000; freq > 500; freq -= 10) {
      tone(pinoBuzzer, freq); 
      delay(5);
    }
  } 
  else { // Caminho livre
    noTone(pinoBuzzer);
    
    // Status Visual: Seguro (Verde)
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledBlue, LOW);
  }

  delay(50); // Estabilização do sensor
}
