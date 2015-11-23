#include "Ultrasonic.h" 
Ultrasonic ultrasonic(6,7); //(Trigger pin,Echo pin) 

int Piezo_Pin=9;
int dist_cm=0;

void setup(){  
  pinMode(Piezo_Pin,OUTPUT);
  Serial.begin(9600);
}

void PIEZO_BUZZ(unsigned char delay_milis,int pwm1,int pwm2){
  analogWrite(9, pwm1);      
  delay(delay_milis);          
  analogWrite(9, pwm2);       
  delay(delay_milis);  
} 

void loop(){
   
  dist_cm=ultrasonic.Ranging(CM); //Medimos la distancia en cm.
  
  Serial.println(dist_cm);

  if (dist_cm<5){
    PIEZO_BUZZ(800, 130, 0);
  } else if (dist_cm<10){
    PIEZO_BUZZ(50, 130, 0);
  } else if (dist_cm<17){
    PIEZO_BUZZ(100, 130, 0);
  } else if (dist_cm<23){
    PIEZO_BUZZ(400, 130, 0);
  } else if (dist_cm<30){
    PIEZO_BUZZ(1500, 130, 0);
  } else {
    PIEZO_BUZZ(0, 0, 0); 
  }
}
