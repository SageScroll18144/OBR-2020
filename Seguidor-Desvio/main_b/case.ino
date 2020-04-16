void PID(float ideal){
 pid_update(analogRead(irs[2]), analogRead(irs[5]));
 float x = pid_actuation(3.0, 5.0, 2.0);
 Serial.println(x);
 if((digitalRead(irs[0]) == 1 || digitalRead(irs[7]) == 1 ) && analogRead(IR_F) > 500){
  forward();
 }
  
 if(x < (ideal - 0.5f)){
  for(int i = 0; i < 4; i++){
    set_velocity(i, 512*x/ideal);
  }
   spin_l();
 }
 else if(x > (ideal + 0.5f)){
  for(int i = 0; i < 4; i++){
    set_velocity(i, 512*ideal/x);
  }
   spin_r();
 }
  
 else {
  for(int i = 0; i < 4; i++){
    set_velocity(i, 512);
  }
   forward();
 }  

}

void desvio(){
  left();
  delay(1000);
  forward();
  delay(2300);
  right();
  delay(1000);
  stopRobot();
  delay(1000);
}
