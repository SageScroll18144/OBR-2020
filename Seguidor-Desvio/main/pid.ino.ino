#define KP 1
#define KI 1
#define KD 1
#define IDEAL 1023

unsigned int last_time = 0;

float ERRO[20];

void update_erro(float val)
{
  for (int i = 1; i < sizeof(ERRO)/sizeof(float); i++) {
    float a = ERRO[0];
    float b = ERRO[i];
    ERRO[0] = a + b;
    ERRO[i] = a - b;
    ERRO[0] = a - b;
  }
  ERRO[0] = val;
}

void set_erro(float val) {//implmentar no setup para que a queue não fique vazia
  for (int i = 0; i < sizeof(ERRO)/sizeof(float); ++i) {
    ERRO[i] = IDEAL - val;
  }
}

void set_time(){
  last_time = millis();
}

float pid_prop() {
  return ERRO[0];
}

float pid_integral(){
  
  float erro_ac = 0.0f;
  for(int i = 0; i < sizeof(ERRO)/sizeof(float); i++){
    erro_ac += ERRO[i]; 
  }
  
  return erro_ac;
  
}

float pid_derivada(){
  return (ERRO[0]-ERRO[1])/(millis()-last_time);
}

float pid_control(float kp, float ki, float kd){
  return kp*pid_prop() + ki * pid_integral() + kd*pid_derivada();
}
