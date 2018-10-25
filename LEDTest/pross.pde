import processing.serial.*;


Serial myPort;
String val;


void setup(){

  size(200,200);
  String portName = Serial.list()[1]; 
  myPort = new Serial(this,portName,9600);
  line(0,100,200,100);
  line(100,0,100,200);
}

void draw(){
  
  if(mouseX < 100 && mouseY < 100){
    println('1');
    myPort.write('1');
  }
  else if(mouseX > 100 && mouseY < 100){
    println('2');
    myPort.write('2');
  }
  else if(mouseX < 100 && mouseY > 100){
    println('3');
    myPort.write('3');
  }
  else if(mouseX > 100 && mouseY > 100){
    println('4');
    myPort.write('4');
  }
  else{
    myPort.write('0');
  }
}
