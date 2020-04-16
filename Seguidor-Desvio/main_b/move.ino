void set_velocity(int motor, int vel){
  analogWrite(motores[motor], vel);
}
void forward(){
  for(int i = 0; i < sizeof(motores)/sizeof(int); i++){
    digitalWrite(dir[motores[i]*2], 1);
    digitalWrite(dir[motores[i]*2+1], 0);
  }
}
void backward(){
  for(int i = 0; i < sizeof(motores)/sizeof(int); i++){
    digitalWrite(dir[motores[i]*2], 0);
    digitalWrite(dir[motores[i]*2+1], 1);
  }
}
void left(){
  for(int i = 0; i < sizeof(motores)/sizeof(int); i++){
    if((i%2)==0){
      digitalWrite(dir[motores[i]*2], 0);
      digitalWrite(dir[motores[i]*2+1], 1);
    }
    else{
      digitalWrite(dir[motores[i]*2], 1);
      digitalWrite(dir[motores[i]*2+1], 0);
    }
  }
}
void right(){
  for(int i = 0; i < sizeof(motores)/sizeof(int); i++){
    if((i%2)==0){
      digitalWrite(dir[motores[i]*2], 1);
      digitalWrite(dir[motores[i]*2+1], 0);
    }
    else{
      digitalWrite(dir[motores[i]*2], 0);
      digitalWrite(dir[motores[i]*2+1], 1);
    }
  }
}
void spin_l(){
  digitalWrite(dir[motors[0]*2], 0);
  digitalWrite(dir[motors[0]*2+1], 1);
  digitalWrite(dir[motors[1]*2], 0);
  digitalWrite(dir[motors[1]*2+1], 1);
  digitalWrite(dir[motors[2]*2], 1);
  digitalWrite(dir[motors[2]*2+1], 0);
  digitalWrite(dir[motors[3]*2], 1);
  digitalWrite(dir[motors[3]*2+1], 0);
}
