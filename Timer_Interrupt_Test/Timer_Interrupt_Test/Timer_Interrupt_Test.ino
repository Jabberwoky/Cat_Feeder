/* Test Code to try out the timer on the ESP8266
 *  
 *  Thanks to Tuxamito (http://tuxamito.com/wiki/index.php/Arduino_Environment_and_Esp8266)
 *  
 *  Note: timer0 set to 2ms is known to cause issues with the WiFi functionaility of the ESP8266
 */

volatile bool tick = false; // Anything variables that will be changed in the ISR are outside the main program and must be declared as volatile. 


void timer0_ISR (void){
  tick = true;
  // Set-up the next interrupt cycle
  timer0_write(ESP.getCycleCount() + 80000000*30); //80Mhz -> 80*10^6 = 1 sec 
}

void setup() {
  noInterrupts();
  timer0_isr_init();
  timer0_attachInterrupt(timer0_ISR);
  timer0_write(ESP.getCycleCount() + 80000000*30); //80Mhz -> 80*10^6 = 1 sec Timer limit is 52 seconds. 
  interrupts();
  Serial.begin(9600);
  Serial.println("Setup Complete");
}

void loop() {
  if (tick == true){
    Serial.println("Tick");
    tick = false;
  }
  yield();
}
