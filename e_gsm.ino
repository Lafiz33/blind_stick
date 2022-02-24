int8_t sendSms(String smsSIMNumber, char *message){                                 //send sms function
  snprintf(aux_str, sizeof(aux_str), "AT+CMGS=\"%s\"",smsSIMNumber.c_str());        //concat sms command AT+CMGS="number"
  Serial.println("sending to: " + smsSIMNumber);                                    
  answer = sendATcommand(aux_str, ">", 2000);                                       //prepare to send text
  if (answer == 1)
  {
    gsmSerial.println(message);                                                     //write text
    gsmSerial.write(0x1A);                                                          //put send command
    answer = sendATcommand("", "OK", 20000);                                        //send and wait for response for 20s
    if (answer == 1)
    {
        return 1;    
    }else{
      return 0;
    }
  }
}

bool setup_gsm(){                                             //setup gsm
  unsigned long gsm_on_time = millis()/1000;                  //start counter
  while (sendATcommand("AT+CREG?", "+CREG: 0,1", 2000) == 0){ //wait till gps is network connected
    Serial.println(".");
    if( ((millis()/1000) - gsm_on_time) > 10){                //if not connected in 10s then break
      return false;
    }
  }
  answer = sendATcommand("AT+CMGF=1", "OK", 1000);            //if connected, set up for sms
  return answer;
  
}


int8_t sendATcommand(char* ATcommand, char* expected_answer1, unsigned int timeout){

  uint8_t x=0,  answer=0;
  char response[100];
  unsigned long previous;
  Serial.print("Command :");Serial.println(ATcommand);
  memset(response, '\0', 100);    // Initialize the string

  delay(100);

  while( gsmSerial.available() > 0) gsmSerial.read();    // Clean the input buffer

  gsmSerial.println(ATcommand);    // Send the AT command 
  x = 0;
  previous = millis();

  // this loop waits for the answer
  do
  {
    if(gsmSerial.available() != 0){    
        response[x] = gsmSerial.read();
        x++;
        
        // check if the desired answer is in the response of the module
        if (strstr(response, expected_answer1) != NULL)    
        {
            answer = 1;
        }
    }
      // Waits for the asnwer with time out
  }while((answer == 0) && ((millis() - previous) < timeout));
  Serial.print("response :");Serial.println(response);
  return answer;
}
















//
