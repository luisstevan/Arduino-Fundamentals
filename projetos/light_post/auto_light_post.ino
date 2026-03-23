void setup() {
  Serial.begin(9600);       // Abre a comunicação com o PC
  pinMode(13, OUTPUT);      

void loop() {
  int luz = analogRead(A0); 
  
  Serial.print("Valor da luz: ");
  Serial.println(luz);  

  if (luz < 500) {          // Se estiver escuro 
    digitalWrite(13, HIGH); // Liga o LED
  } 
   
  else {
    digitalWrite(13, LOW);  // Desliga o LED
  }
  
  delay(100);               
}
