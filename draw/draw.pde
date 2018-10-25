PrintWriter output;
 
void setup()
{
  size(256,256);
  output = createWriter("positions.txt");
}
 
// x0=-1 means "the next click is the start of a new line segment"
int x0=-1,y0=-1;
int x,y;
 
void draw() {}
 
void mouseDragged() {
  x = mouseX;
  y = mouseY;
  output.println(String.format("%d,%d",x,(256-y)));
  output.flush();
  if (x0>=0) {
    line(x0,y0,x,y);
  }
  x0=x;
  y0=y;
}
 
void mouseReleased() {
  x0=-1;
}
