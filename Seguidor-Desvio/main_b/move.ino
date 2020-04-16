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
    digitalWrite(motores[i*2], 0);
    digitalWrite(motores[i*2+1], 1);
  }
}
void left(){
  for(int i = 0; i < sizeof(motores)/sizeof(int); i++){
    if((i%2)==0){
      digitalWrite(motores[i*2], 0);
      digitalWrite(motores[i*2+1], 1);
    }
    else{
      digitalWrite(motores[i*2], 1);
      digitalWrite(motores[i*2+1], 0);
    }
  }
}
void right(){
  for(int i = 0; i < sizeof(motores)/sizeof(int); i++){
    if((i%2)==0){
      digitalWrite(motores[i*2], 1);
      digitalWrite(motores[i*2+1], 0);
    }
    else{
      digitalWrite(motores[i*2], 0);
      digitalWrite(motores[i*2+1], 1);
    }
  }
}
void spin_l(){
  
}
