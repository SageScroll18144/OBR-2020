/*
 * FALTA IMPLEMENTAR AS FUNÇÕES DOS MOTORES!
 * 
 *  
 */

void PID(float ideal){
 pid_update(analogRead(irs[2]), analogRead(irs[5]));
 float x = pid_actuation(3.0, 5.0, 2.0);
 Serial.println(x);
 if((digitalRead(irs[0]) == 1 || digitalRead(irs[7]) == 1 ) && analogRead(IR_F) > 500){
  forward();
 }
  
 if(x < (x - 0.5f)){
  for(int i = 0; i < 4; i++){
    set_velocity(i, 512*x/ideal);
  }
   spinRobot('L');
 }
 else if(x > (x + 0.5f)){
  for(int i = 0; i < 4; i++){
    set_velocity(i, 512*ideal/x);
  }
   spinRobot('R');
 }
  
 else {
  for(int i = 0; i < 4; i++){
    set_velocity(i, 512);
  }
   forward();
 }  

}
