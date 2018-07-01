void Get_Time(){
  // first parameter: Time zone in floating point (for India); second parameter: 1 for European summer time; 2 for US daylight saving time; 0 for no DST adjustment; 
  dateTime = NTPus.getNTPtime(-8.0, 2);

  // Sets all "Actual" Variables
    byte actualHour = dateTime.hour;
    byte actualMinute = dateTime.minute;
    byte actualsecond = dateTime.second;
    int  actualyear = dateTime.year;
    byte actualMonth = dateTime.month;
    byte actualday = dateTime.day;
    byte actualdayofWeek = dateTime.dayofWeek;  // Sunday is 1 

  // Serial output for Debug
  //NTPus.printDateTime(dateTime); 
}


uint8_t Meal_Time(byte currentHour, byte currentMin){
  uint8_t breakfastHour = 7;
  uint8_t breakfastMin = 0;
  uint8_t dinnerHour = 19;
  uint8_t dinnerMin = 0;

    if (currentHour == breakfastHour && currentMin == breakfastMin){
      return 1;
    }
    else if (currentHour == dinnerHour && currentMin == dinnerMin){
      return 2;
    }
    else 
      return 0;
}



