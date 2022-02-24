
void sosOn(){                   //ISR function
  Serial.println("sos");
  if(!startFlag){
    detachInterrupt(digitalPinToInterrupt(sos_button));  //debouncing
    sosFlag = true;
    for(int i = 0; i < 200; i++);
  }
  startFlag = false;
    
}

void buzzer_pattern1(uint8_t dist){
  digitalWrite(buzzer, HIGH);
  delay(dist * 10);
  digitalWrite(buzzer, LOW);
  delay(dist * 10);
}

void buzzer_pattern2(){
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(300);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(300);
}

void buzzer_pattern3(){
  digitalWrite(buzzer, HIGH);
  delay(500);
//  digitalWrite(buzzer, LOW);
//  delay(50);
//  digitalWrite(buzzer, HIGH);
//  delay(250);
//  digitalWrite(buzzer, LOW);
//  delay(50);
//  digitalWrite(buzzer, HIGH);
//  delay(50);
  digitalWrite(buzzer, LOW);
}

void buzzer_pattern4(uint8_t dist){
  digitalWrite(buzzer, HIGH);
  delay(400);
  digitalWrite(buzzer, LOW);
  delay(400);
}









//
