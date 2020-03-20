void resgate(){
  while(true){
      String x = Serial.readString();
      if(x == "SL"){//giro para esquerda
        spinRobot('L');
      }else if(x == "SR"){//giro para direita
        spinRobot('R');
      }else if(x == "F"){//frente
        forward();
      }else if(x == "B"){//trás
        backward();
      }else if(x == "L"){//esquerda
        go_left();
      }else if(x == "R"){//direita
        go_right();
      }else if(x == "E"){//sair
        break;
      }
      
      if(sharp_read() < 4){
        Serial.write(1);
      }
    
  }

}
