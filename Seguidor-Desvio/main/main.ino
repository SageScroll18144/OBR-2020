/*
 M0  ####  M3.
    ######       -> chassi do robô
    ######       -> M(motor)[número do motor]
 M1  ####  M2
*/

#define KP 1
#define KI 1
#define KD 1

#define IDEAL 1023

double lastMeasure = 0;
double lastTime = 0;
double P, I, D;

const int ultrassonic[] = {1,1,1,1};//trig,echo, ... trig[N],echo[N]
const int irs[] = {1,1,1,1,1,1,1,1};//pinos(trocar os valores...)
const int sharp_pin = A1;

const int dir[] = {51,53,45,43,41,39,47,49};//pinos de direção dos motores
                                            //F[0]; B[0];F[1];B[1];...;F[N];B[N]
const int motores[] = {A1,A2,A6,A7};//pinos de velocidade

boolean canI = true;

void setup() 
{
  for(int i = 0; i < sizeof(irs)/sizeof(int); i++){
      pinMode(irs[i], INPUT);
  }   
  for(int i = 0; i < sizeof(ultrassonic)/sizeof(int); i++){
    if ((i%2) == 0)
      pinMode(ultrassonic[i], OUTPUT);
    else
      pinMode(ultrassonic[i], INPUT);
  }
  pinMode(sharp_pin, INPUT);
  Serial.begin(9600);
}

void loop() 
{

  if(Serial.available() > 0){
    canI = false;
    int input = Serial.read();
    if(input == 1){//get ball
      resgate();
    }else if(input == 2){//giro
      spinRobot('L');
    }else if(input == 3){//esquerda
      go_left();
    }else if(input == 4){//direita
      go_right();
    }
    
  }
  else if(sharp_read() <= 5){
    go_left();
    delay(1000);
    forward();
    delay(2300);
    go_right();
    delay(1000);
    for(int i = 0;i<4; i++){
      stopRobot(i);
    }
    delay(1000);
  }
  else if(canI == true){
    //set_time();
    //pid_update(sensor1, sensor2);
    //float x = pid_actuation(3.0, 5.0, 2.0);
    //x -> valor PID; Implementar no algoritmo proporcional do motor(pós essa etapa). 
    double error = IDEAL - analogRead(A0);
    
    P = KP * error;
    I += KI * error;
    D = KD * ((analogRead(A0) - lastMeasure)/(millis() - lastTime));
  
    double PID = P+I+D;
  
    lastMeasure = analogRead(A0);//trocar pelo sensor IR[N]
    lastTime = millis();
  }
}
