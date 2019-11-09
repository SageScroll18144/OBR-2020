#define KP 1
#define KI 1
#define KD 1

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
  set_erro(readIR(irs[0]));//trocar o argumento
}

void loop() 
{
  
}
