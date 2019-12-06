#define KP 1
#define KI 1
#define KD 1

#define IDEAL 1023
double lastMeasure = 0;
double P, I, D;
const int ultrassonic[] = {};//trig,echo, ... trig[N],echo[N]
const int irs[] = {1,1,1};//pinos(trocar os valores...)
const int sharp_pin = A0;

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
  err_init();
}

void loop() 
{
  //set_time();
  //pid_update(sensor1, sensor2);
  //float x = pid_actuation(3.0, 5.0, 2.0);
  //x -> valor PID; Implementar no algoritmo proporcional do motor(pós essa etapa). 
  double error = IDEAL - analogRead(A0);
  double now = millis();
  
  P = KP * error;
  I += KI * error;
  D = KD * ((analogRead(A0) - lastMeasure)/(millis() - now));

  double PID = P+I+D;

  lastMeasure = analogRead(0);
}
