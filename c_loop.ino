void loop() {
  // put your main code here, to run repeatedly:
  //if button pressed
  if(sosFlag){
    sosFlag = false;
    hail_sos();
    attachInterrupt(digitalPinToInterrupt(sos_button), sosOn, FALLING);
  }

  //measure distance and react
  check_distance();

  //check water sensor
  check_water();





  

}
