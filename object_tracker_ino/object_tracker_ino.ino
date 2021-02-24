#include <Servo.h> 
Servo base;
Servo neck;

int x_err = 0, y_err = 0;
int base_pos = 90, neck_pos = 110;

void setup(){
  Serial.begin(9600);
  base.attach(6);
  neck.attach(5);
  base.write(base_pos);
  neck.write(neck_pos);
}


void loop(){
  if(Serial.available()>0){
    String data = Serial.readStringUntil('\n');
    int x_err = data.substring(0,2).toInt() - 50;
    int y_err = data.substring(2).toInt() - 50;
    Serial.print(x_err);
    Serial.print("  ");
    Serial.println(y_err);
    
    update_pos(x_err, y_err, 0.1);
  }
}


void update_pos(int x_err, int y_err, float kp){
  base_pos += kp*x_err;
  neck_pos += kp*y_err;
  base.write(base_pos);
  neck.write(neck_pos);
}



