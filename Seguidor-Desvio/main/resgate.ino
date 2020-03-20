void resgate(){

  while(true){
    if(Serial.available() > 0){
      String x = Serial.readString();
      if(x == "S"){
        
      }else if(x == "F"){//frente
        
      }else if(x == "B"){//trás
        
      }else if(x == "L"){//esquerda
        
      }else if(x == "R"){//direita
        
      }else if(x == "E"){//sair
        
      }
    }
    
  }

}
