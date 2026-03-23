int sensor = A0;

int green = 3;
int blue = 5;
int red = 6;

int buzzer = 8;

void setup() {
  Serial.begin(9600);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  pinMode(buzzer, OUTPUT);
}

void loop() {
  int valor = analogRead(sensor);
  Serial.println(valor);

  if (valor < 600) {
    //  seco
    analogWrite(red, 255);
    analogWrite(green, 255);
    analogWrite(blue, 255);

    noTone(buzzer);

  }

  else if (valor < 700) {
    //  Médio
    analogWrite(red, 255);
    analogWrite(green, 255);
    analogWrite(blue, 0);

    noTone(buzzer);
  }

  else { 
    // Molhado
    analogWrite(red, 255);
    analogWrite(green, 0);
    analogWrite(blue, 0);

    tone(buzzer, 2000);
    delay(200);
    
    tone(buzzer, 1000);
  }

  delay(500);
}
