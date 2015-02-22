/*
In my wiring,
Buttons:
12 - Right Trigger
11 - Left Trigger
10 - Up
9 - Right joystick button
8 - Right
7 - Down
6 - Left
5 - Switch
4 - Start (right button)
3 - Select (left button)
Joysticks:
G Y Button X +
  Left Joystick:
    Y: A0
    Button: 13
    X: A1
Right Joystick:
  Y: A2
  Button: A4
  X: A3
*/

int rightTrigger = 12;
int leftTrigger = 11;
int Up = 10;
int Right = 8;
int Down =7;
int Left = 6;
int Switch = 5;
int Start = 4;
int Select = 3;

int oldrightTriggerValue = 3;
int oldleftTriggerValue = 3;
int oldUpValue = 3;
int oldRightValue = 3;
int oldDownValue = 3;
int oldLeftValue = 3;
int oldSwitchValue = 3;
int oldStartValue = 3;
int oldSelectValue = 3;
int oldrightJoyStick = 3;
//analog values
int leftY = A0;
int leftX = A1;
int leftPressed = 13;
int rightY = A2;
int rightX = A3;
int rightPressed = 9;

//flag for left joystick
int movedLR = 0;
int movedUD = 0;

int totalDelay = 100;
//switch value
int switchValue = 1;
void setup() {
  //enable debugging through print statements
  Serial.begin(9600);
  pinMode(13, OUTPUT); 
  //enable internal resistance, use as necessary
  pinMode(rightTrigger, INPUT_PULLUP);
  pinMode(leftTrigger, INPUT_PULLUP);
  pinMode(Start, INPUT_PULLUP);
  pinMode(Select, INPUT_PULLUP);
  // initialize mouse and keyboard control
  Mouse.begin();
  Keyboard.begin();
}

void loop() {
  //keep light on when running
  digitalWrite(13, HIGH);
  
  //read in values for all buttons
  int rightTriggerValue = digitalRead(rightTrigger);
  int leftTriggerValue = digitalRead(leftTrigger);
  int UpValue = digitalRead(Up);
  int RightValue = digitalRead(Right);
  int DownValue = digitalRead(Down);
  int LeftValue = digitalRead(Left);
  int SwitchValue = digitalRead(Switch);
  int StartValue = digitalRead(Start);
  int SelectValue = digitalRead(Select);
  int rightJoyStick = digitalRead(rightPressed);
  //Serial.println(totalDelay);
  
  if (oldSelectValue != SelectValue) {
    if (SelectValue == HIGH && totalDelay > 2) {
      totalDelay = totalDelay - 20;
    }
    oldSelectValue = SelectValue;
  }
  
  if (oldStartValue != StartValue) {
    if (StartValue == HIGH) {
      totalDelay = totalDelay + 20;
    }
    oldStartValue = StartValue;
  }
  //check if right trigger button is pressed
  if (rightTriggerValue == HIGH) {
      Mouse.press();
  }
  if (rightTriggerValue == LOW) {
      Mouse.release();
  }
  if (leftTriggerValue == HIGH) {
      Keyboard.write('f');
  }
  if (leftTriggerValue == HIGH) {
      Keyboard.press('f');
  }
  if (leftTriggerValue == LOW) {
      Keyboard.press('f');
  }
  
  //get right joystick values and move accordingly
  int rightYValue = analogRead(rightY);
  int rightXValue = analogRead(rightX);
  if (abs(rightXValue - 325) < 40) {
     rightXValue = 325;
  } 
  if (abs(rightYValue - 325) < 40) {
     rightYValue = 325;
  } 
  Mouse.move((rightXValue-325)/8,(325-rightYValue)/8);
  
  //get left joystick values and respond accordingly
  int leftYValue = analogRead(leftY);
  int leftXValue = analogRead(leftX);
  if (leftYValue < 100) {
       Keyboard.press('s');
    }
    else {
       Keyboard.release('s'); 
    }
   if (leftXValue > 600) {
       Keyboard.press('d');
   }
   else {
       Keyboard.release('d'); 
    }
   if (leftYValue > 600) {
       Keyboard.press('w');
    }
    else {
       Keyboard.release('w'); 
    }
    if (leftXValue < 100) {
       Keyboard.press('a');
    }else {
       Keyboard.release('a'); 
    }
  
  delay(totalDelay);
  
  int switchValue = digitalRead(Switch);
  //do something here if you have time
  if (switchValue == 1) {
    //?
  }
  
}
