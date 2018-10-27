const byte numPins = 7;
byte pins[] = {0,1,2,3,4,5,6};
int analogPin = A0;
byte value = 0;

void writeVoltage(byte val);
void readVoltage(void);
int bitState(byte val, byte i);

void setup() {
  pinMode(analogPin, INPUT);
  Serial.begin(9600); // This starts a serial connection at a 9600 baud rate
}

void loop() {
  int expectedV = 0;
  /*
  if(Serial.available()){
    val = Serial.read();
  }
  */
  Serial.print(value);
  Serial.print("\t");
  writeVoltage(value);
  delay(10);
  readVoltage();
  value = (value + 1)%128;
  delay(10);
 

  
}

void writeVoltage(byte val) {
    for(byte i = 0; i < numPins; i++){
    int state = bitState(val,i);
    digitalWrite(pins[i],state);  
    delay(10);
  }
}

void readVoltage() {
  float voltage = analogRead(analogPin) * (5.0/1023.0);
  byte val = (byte)(voltage * 5.0 / 128.0);
  Serial.println(voltage);
}

int bitState(byte val, byte i) {
  byte mask = 1 << i;
  byte result = mask && val;
  if (result)
    return HIGH;
  else 
    return LOW;
}
