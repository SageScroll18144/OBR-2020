#define KP 1
#define KI 1
#define KD 1

const unsigned int ultrassonic[] = {};//trig,echo, ... trig[N],echo[N]
const unsigned int irs[] = {1,1,1};//pinos(trocar os valores...)

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
  set_erro(readIR(irs[0]));//trocar o argumento
}

void loop() 
{
  
}
