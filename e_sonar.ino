void check_distance(){
  int dist_front1 = ultrasonic1.read(CM);  //read from sonar 1
  int dist_front2 = ultrasonic3.read(CM);  //read from sonar 2
  int dist_below = ultrasonic2.read(CM);  //read from sonar 2
  if( (dist_front1 < min_front_dist1) || (dist_front2 < min_front_dist2) ){        //check distance
    //sound buzzer pattern 1
    if(dist_front1 < dist_front2){
      Serial.println("small");
      buzzer_pattern4(dist_front1);          //buzzer 
    }else if( (dist_front1 == dist_front2) || (dist_front1 > dist_front2) ){
      Serial.println("big");
      buzzer_pattern1(dist_front2);
    }
  }
  if(dist_below > min_below_dist){        //check distance
    //sound buzzer pattern 2
    Serial.println("below");
    buzzer_pattern2();                    //buzzer
  }
  
}

void check_water(){
  uint8_t state = analogRead(water_pin);  //read water sensor
//  Serial.println(state); 
  if( state < 100){
    Serial.println("water");
    digitalWrite(buzzer, HIGH);
//    buzzer_pattern3();
  }else{
    digitalWrite(buzzer, LOW);
  }
  
}








//
