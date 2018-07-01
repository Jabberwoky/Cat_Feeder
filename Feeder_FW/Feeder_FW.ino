/*
   The Sketch Runs an Automatic cat feeder. 
   It uses the ESP8266 to get the time from the web, check if it's feeding time and if it is dispense food via a stepper motor. 

   Written by: Demian Mendez  
*/

#include <NTPtimeESP.h>

NTPtime NTPus("us.pool.ntp.org");   // Choose server pool as required
char *ssid      = "";               // Set you WiFi SSID
char *password  = "";               // Set you WiFi password

// Variables for capturing time and date values
strDateTime dateTime;
/*
The structure contains following fields:
struct strDateTime
{
  byte hour;
  byte minute;
  byte second;
  int year;
  byte month;
  byte day;
  byte dayofWeek;
  boolean valid;
 }; */
 
    byte actualHour = 1;
    byte actualMinute = 1;
    byte actualsecond = 1;
    int  actualyear = 2018;
    byte actualMonth = 1;
    byte actualday = 1;
    byte actualdayofWeek = 1;

// Flags for meals
  bool breakfastFlag = false; // false means meal has not been dispensed. 
  bool dinnerFlag = false;    


void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booted");
  Serial.println("Connecting to Wi-Fi");

  WiFi.mode(WIFI_STA);
  WiFi.begin (ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("WiFi connected");
}

void loop() {
  Get_Time();  
  
  switch (Meal_Time(actualHour, actualMinute)) {
    case 1:
      Serial.println("Breakfast Time!"); 
      breakfastFlag = true;
      dinnerFlag = false;
      // Add feeding routine here
      break;
    case 2:
      Serial.println("Dinner Time!"); 
      breakfastFlag = false;
      dinnerFlag = true;
      // Add feeding routine here
      break;
    default:   //Not a meal time. Don't feed.
      break;
  }
  
}
