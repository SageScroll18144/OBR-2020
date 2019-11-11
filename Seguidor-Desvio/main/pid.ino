#define ERROR_LENGTH 20

float ERRO[ERROR_LENGTH];
unsigned long time_last = 0;

void set_time(){
  time_last = millis();
}

unsigned long get_time(){
  return time_last;
}
void err_init(){
  for(int i = 0; i < ERROR_LENGTH; i++){
    ERRO[i] = 0;
  }
}
void pid_update(unsigned int raw_left, unsigned int raw_right) {
  float norm_left = pid_normalize(raw_left);
  float norm_right = pid_normalize(raw_right);

  float erro = 0;

  erro -= norm_left;
  erro += norm_right;

  pid_push(erro);

}

void pid_push(float val) {
  for (int i = 1; i < ERROR_LENGTH; i++) {
    float a = ERRO[0];
    float b = ERRO[i];
    ERRO[0] = a + b;
    ERRO[i] = a - b;
    ERRO[0] = a - b;
  }
  ERRO[0] = val;

}

// P_W, peso da proporcio, D_W, peso da derivada, I_W peso da integral.
float pid_actuation(float p_w, float d_w, float i_w) {
  return (p_w * pid_prop()) + (d_w * pid_derivada()) + (i_w * pid_integral());
}

// Erro proporcional básico do pid
float pid_prop() {
  return ERRO[0];
}

// Derivada dp pid, equivalente a velocidade em que a linha se move.
float pid_derivada() {
  return (ERRO[0]-ERRO[1])/(get_time()-millis());
}

// Integral do pid, equivalente ao erro acumulado em ERROR_LENGTH ciclos.
float pid_integral() {

  float erro_ac = 0.0f;

  for(unsigned int i = 0; i < ERROR_LENGTH; i++) {
    erro_ac += ERRO[i];
  }

  return erro_ac/ (float)ERROR_LENGTH;
}

float pid_normalize(unsigned int data) {
  unsigned int MAX = (1<<10);

  float normalizado = (float)(MAX-data)/(float)MAX;

  return 1.0f - normalizado;
}
