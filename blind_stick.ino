#include <SoftwareSerial.h>
#include <TinyGPS.h> //install this library
#include <Ultrasonic.h> //install this library




//pin declaration
#define sos_button  2
#define water_pin   A5
#define buzzer      10
#define s1_trig     13
#define s1_echo     A0
#define s2_trig     A3
#define s2_echo     A2
#define s3_trig     12
#define s3_echo     11

//library objects for sonar
Ultrasonic ultrasonic1(s1_trig, s1_echo);
Ultrasonic ultrasonic2(s2_trig, s2_echo);
Ultrasonic ultrasonic3(s3_trig, s3_echo);

//library object for gps
TinyGPS gps;

//serial declaration
SoftwareSerial gpsSerial(4, 5);
SoftwareSerial gsmSerial(8, 9);


//variables
bool sosFlag = false;
bool startFlag = true;
int8_t answer;
char aux_str[200];


//set distance limit in cm
uint8_t min_below_dist = 25;  //for manholes
uint8_t min_front_dist1 = 70; //for lower sensor
uint8_t min_front_dist2 = 70; //for higher

//gps functions
bool get_gps_loc(float& lat, float& lon);
void hail_sos();

//gsm functions
int8_t sendATcommand(char* ATcommand, char* expected_answer1, unsigned int timeout);
bool setup_gsm();
int8_t sendSms(String smsSIMNumber, char *message);

//sonar and water sensor check
void check_distance();
void check_water();

//misc functions
void sosOn();
void buzzer_pattern1(uint8_t dist);
void buzzer_pattern2();
void buzzer_pattern3();
void buzzer_pattern4(uint8_t dist);









//
