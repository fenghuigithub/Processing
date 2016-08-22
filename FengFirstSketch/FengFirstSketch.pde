//The original code which is called "Translate" comes from processing.org website.
//The original code allows two rectangles to move from left to right within the window.
//The revised code allows tow rectangles to move from top-eft corner to right-bottom corner,
//and moving rates of them are bigger. Furthermore, two rectangles' colors are more beautiful than earlier ones.





float x, y;
float dim = 80.0;

void setup() {
  size(640, 360);
  noStroke();
}

void draw() {
  background(102);
  
  y = y + 2.0;
  x = x + 0.8;             //I magnified the change quantity of x and y 
  
  if (y > height + dim) {
    y = -dim;
  }                        //I modified the vertical position of rectangles
  if(x >width + dim){
  x=-dim;
}
  
  translate(x, y);
  fill(#436EEE);          //I changed the first rectangle's color
  rect(-dim/2, -dim/2, dim, dim);
  
  // Transforms accumulate. Notice how this rect moves 
  // twice as fast as the other, but it has the same 
  // parameter for the x-axis value
  translate(x, y);
  fill(#CAFF70);          //I changed the second rectangle's color
  rect(-dim/2, -dim/2, dim, dim);
}