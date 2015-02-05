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
void setup() {
  //enable debugging through print statements
  Serial.begin(9600);
  
  //enable internal resistance, use as necessary
  pinMode(rightTrigger, INPUT_PULLUP);
  
  // initialize mouse and keyboard control
  Mouse.begin();
  Keyboard.begin();
}

void loop() {
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
  if (oldrightTriggerValue != rightTriggerValue) {
    if (rightTriggerValue == HIGH) {
      Keyboard.write(0x20);
    }
    oldrightTriggerValue = rightTriggerValue;
  }
  if (oldrightJoyStick != rightJoyStick) {
    if (rightJoyStick == HIGH) {
      Mouse.click();
    }
    oldrightJoyStick = rightJoyStick;
  }
  int rightYValue = analogRead(rightY);
  int rightXValue = analogRead(rightX);  
  Mouse.move((rightXValue-325)/8,(325-rightYValue)/8);
  //Mouse.move((leftXValue-325)/8,(leftYValue-325)/8);
  delay(100);
}
