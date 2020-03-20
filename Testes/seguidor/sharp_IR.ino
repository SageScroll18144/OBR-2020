//retorno em CM
float sharp_read(){
  return (6762/((analogRead(sharp_pin)-9))) - 4;
}
