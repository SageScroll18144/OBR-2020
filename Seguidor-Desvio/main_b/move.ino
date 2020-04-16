void set_velocity(int motor, int vel){
  analogWrite(motores[motor], vel);
}
void forward(){
  for(int i = 0; i < sizeof(motores)/sizeof(int); i++){
    digitalWrite(motores[i*2], 1);
    digitalWrite(motores[i*2+1], 0);
  }
}
void backward(){
  for(int i = 0; i < sizeof(motores)/sizeof(int); i++){
    digitalWrite(motores[i*2], 1);
    digitalWrite(motores[i*2+1], 0);
  }
}
void right(){
  
}
void left(){
  
}
void spin_l(){
  
}
