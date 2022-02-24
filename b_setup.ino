void setup() {
  // put your setup code here, to run once:
  //Serial begin
  Serial.begin(115200);
  gpsSerial.begin(9600);
  gsmSerial.begin(9600);

  startFlag = true;
  
  //pin setup
  pinMode(water_pin, INPUT);
  pinMode(buzzer, OUTPUT);

  //interrupt declaration
  pinMode(sos_button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(sos_button), sosOn, FALLING);

  
  //delay for gsm to be stable
  delay(16000); //do not remove this delay
  
  //wait until gsm is connected to network
  while(!setup_gsm());

  Serial.println("ready");

  //debounceing
  sosFlag = false;
  
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, LOW);
  
}
