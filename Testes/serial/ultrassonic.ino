//OS SENSORES SÃO ENUMERADOS DE 0 À 4
int ultrassonicRead(int sensor){
  unsigned long duracao;
  unsigned long distancia;
  digitalWrite(ultrassonic[(2*sensor)], LOW);
  delayMicroseconds(2);
  digitalWrite(ultrassonic[(2*sensor)], HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrassonic[(2*sensor)], LOW);
  duracao = pulseIn(ultrassonic[(2*sensor)+1], HIGH);
  distancia = duracao/58;
  
  return distancia;
}
