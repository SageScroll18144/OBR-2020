const unsigned int ultrassonic[] = {};//trig,echo, ... trig[N],echo[N]

void setup() {
   for(int i = 0; i < sizeof(ultrassonic)/sizeof(int); i++){
    if ((i%2) == 0)
      pinMode(ultrassonic[i], OUTPUT);
    else
      pinMode(ultrassonic[i], INPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
