bool get_gps_loc(float& lat, float& lon){
  bool newData = false;
  bool validity = true;
  

  // For one second we parse GPS data and report some key values
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (gpsSerial.available())
    {
      char c = gpsSerial.read(); //read gps data
      Serial.print(c);
      if (gps.encode(c))  // translate gps data
        newData = true;   // new data flag
    }
  }

  if (newData) //if new data available
  {
    unsigned long age;
    gps.f_get_position(&lat, &lon, &age);       //get data
    if(lat == TinyGPS::GPS_INVALID_F_ANGLE ){   //if invalid data found
      lat = 23.7508595;                                //set value to zero
      validity = false;
    }
    if(lon == TinyGPS::GPS_INVALID_F_ANGLE ){   //if invalid data found
      lat = 90.4030951;                                //set value to zero
      validity = false;
    }
  }
  return validity;
}


//23.754751,90.392013
void hail_sos(){
  String num_list[] = {"01864144040"}; //emergency number list
  float lat, lon = 0.0;                                     //gps position variables
  get_gps_loc(lat, lon);                                    //get gps location
  String msg = "I need assistance. my location is: http://www.google.com/maps/place/";       //prepare emergency msg
  msg += String(lat);   
  msg += ",";
  msg += String(lon);
  Serial.println(msg);
  for(int i = 0; i < 1; i++){                               //send sms to all number in the list
    sendSms(num_list[i], msg.c_str());
    Serial.println(num_list[i]);
    delay(1000);
  }
  sosFlag = false;
  detachInterrupt(digitalPinToInterrupt(sos_button));
}














//
