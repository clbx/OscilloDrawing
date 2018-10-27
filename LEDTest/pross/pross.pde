import processing.serial.*;


Serial myPort;
String val;


void setup(){

  size(200,255);
  String portName = Serial.list()[1]; 
  myPort = new Serial(this,portName,9600);

}

void draw(){
  int myNum = (int)map(mouseY, 0, height, 0, 128);
  myPort.write(myNum);
  println(mouseY);
}
