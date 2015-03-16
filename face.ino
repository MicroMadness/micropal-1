#include <MicroView.h>

void setup() {
  Serial.begin(57600);
  uView.begin();		// start MicroView
  uView.clear(PAGE);		// clear page
  uView.print("Hi Evan!");	// say hi
  uView.display();
  delay(1000);
}

int mood = 3;
int tick = 0;

void loop () {
  
    if (Serial.available()) {
      mood = Serial.parseInt();
      
      drawFace();
    }
    
    if (random(0, 60) == 1)
      mood = random(1,4);
      drawFace();
    if (random(0,10) == 1) talk();
    
    if (random(0,70) == 1) sing();
    
    if (tick % 40 == 0) blinkFaceAnimation();
      
    delay(100);
    tick = tick + 1;
}

void drawFace() { 
  uView.clear(PAGE);
  
  drawEyes();
  drawNose();
  drawMouth();    

  uView.display();        // display current page buffer
}

void drawEyes() {
  uView.circle(20, 15, 5);
  uView.circle(45, 15, 5);
}

void drawNose() {
  uView.line(30, 22, 35, 32);
  uView.line(35, 32, 31, 32);
}

void drawMouth() {
  uView.line(25, 45, 40, 45);
  
  if(mood == 1){
  // Happy
  uView.line(20, 40, 25, 45);
  uView.line(40, 45, 45, 40);
  }
  //okay mood
  else if(mood == 3){
    uView.line(20, 45, 25, 45);
    uView.line(40, 45, 45, 45);
  }
  else if(mood == 2){
  // Sad
  uView.line(20, 50, 25, 45);
  uView.line(40, 45, 45, 50);
  }
  
}
void sing(){
  for (int i = 0; i < 7; i++) {
    uView.clear(PAGE);
    
    switch (i) {
      case 0: 
      case 7:
        
        delay(10000);
        uView.line(25, 45, 40, 45); 
        
        break;
      case 1:
      case 6: 
        
        uView.circle(19, 45, 2);
        break;
      case 2:
      case 5:
        uView.circle(19, 45, 4);
        
        break;
      case 3:
      case 4: 
        uView.circle(19, 45, 7);
        
        break;
    }
  
    // draw the static parts of the face    
    drawEyes();
    drawNose();
    
    // display and wait for the next frame to start
    uView.display();
    delay(50);
  }  
}  
void talk() {
  for (int i = 0; i < 7; i++) {
    uView.clear(PAGE);
    
    switch (i) {
      case 0: 
      case 7:
      case 13:  
        
        uView.line(25, 45, 40, 45); 
        
        break;
      case 1:
      case 6:
      case 8: 
      case 12:  
        uView.rect(23, 41, 20, 4);
        break;
      case 2:
      case 5:
      case 9:  
      case 11:  
        uView.rect(23, 41, 20, 6);
        
        break;
      case 3:
      case 4:
      case 10: 
        uView.rect(23, 41, 20, 8);
        
        break;
    }
  
    // draw the static parts of the face    
    drawEyes();
    drawNose();
    
    // display and wait for the next frame to start
    uView.display();
    delay(40);
  }  
}  
void blinkFaceAnimation() {
  for (int i = 0; i < 7; i++) {
    uView.clear(PAGE);
    
    // animate two eyes for the blink
    switch (i) {
      case 0: 
      case 6:
        uView.circle(45, 15, 5);
        uView.circle(20, 15, 5);
        break;
      case 1:
      case 5: 
        uView.rect(40, 12, 10, 5);
        uView.rect(15, 12, 10, 5);
        break;
      case 2:
      case 4:
        uView.rect(40, 14, 10, 2);
        uView.rect(15, 14, 10, 2);
        break;
      case 3: 
        uView.line(40, 15, 50, 15);
        uView.line(15, 15, 50, 15);
        break;
    }

    // draw the static parts of the face    
    drawNose();
    drawMouth();
    
    // display and wait for the next frame to start
    uView.display();
    delay(50);
  }  
}
