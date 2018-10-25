char val;
int topLeft = 13;
int topRight = 12;
int botLeft = 11;
int botRight = 10;

void setup() {
  pinMode(topLeft, OUTPUT);
  pinMode(topRight, OUTPUT);
  pinMode(botLeft, OUTPUT);
  pinMode(botRight, OUTPUT);

  Serial.begin(9600); // This starts a serial connection at a 9600 baud rate
}

void loop() {
 
  if(Serial.available()){
    val = Serial.read();
  }
  else if( val == '1'){
    digitalWrite(topLeft, HIGH);
    digitalWrite(topRight, LOW);
    digitalWrite(botLeft, LOW);
    digitalWrite(botRight, LOW);
  }
  else if( val == '2'){
    digitalWrite(topLeft, LOW);
    digitalWrite(topRight, HIGH);
    digitalWrite(botLeft, LOW);
    digitalWrite(botRight, LOW);
  }
  else if( val == '3'){
    digitalWrite(topLeft, LOW);
    digitalWrite(topRight, LOW);
    digitalWrite(botLeft, HIGH);
    digitalWrite(botRight, LOW);
  }
  else if( val == '4'){
    digitalWrite(topLeft, LOW);
    digitalWrite(topRight, LOW);
    digitalWrite(botLeft, LOW);
    digitalWrite(botRight, HIGH);
  }
  delay(10);
}
