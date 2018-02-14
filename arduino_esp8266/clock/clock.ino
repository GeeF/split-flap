#include "clock.h"
#include "splitflap.h"

SplitFlap hour_flap  (HOUR_ENCODER, 40, PIN_TRIAC_HOUR_N, PIN_STROBE_HOUR,
                               PIN_EC_HOUR_0, PIN_EC_HOUR_1, PIN_EC_HOUR_2, PIN_EC_HOUR_3,
                               PIN_EC_HOUR_4, PIN_EC_HOUR_5);
SplitFlap minute_flap(MIN_ENCODER,  62, PIN_TRIAC_MIN_N,  PIN_STROBE_MIN,
                               PIN_EC_MIN_0, PIN_EC_MIN_1, PIN_EC_MIN_2, PIN_EC_MIN_3,
                               PIN_EC_MIN_4, PIN_EC_MIN_5);

void setup() {
  Serial.begin(9600);
  pinMode(PIN_TRIAC_HOUR_N, OUTPUT);
  pinMode(PIN_STROBE_HOUR, INPUT);
  pinMode(PIN_TRIAC_MIN_N, OUTPUT);
  pinMode(PIN_STROBE_MIN, INPUT);
  pinMode(PIN_EC_HOUR_0, INPUT);
  pinMode(PIN_EC_HOUR_1, INPUT);
  pinMode(PIN_EC_HOUR_2, INPUT);
  pinMode(PIN_EC_HOUR_3, INPUT);
  pinMode(PIN_EC_HOUR_4, INPUT);
  pinMode(PIN_EC_HOUR_5, INPUT);
  pinMode(PIN_EC_MIN_0, INPUT);
  pinMode(PIN_EC_MIN_1, INPUT);
  pinMode(PIN_EC_MIN_2, INPUT);
  pinMode(PIN_EC_MIN_3, INPUT);
  pinMode(PIN_EC_MIN_4, INPUT);
  pinMode(PIN_EC_MIN_5, INPUT);
  digitalWrite(PIN_TRIAC_HOUR_N, 0);
  digitalWrite(PIN_STROBE_HOUR,  0);
  digitalWrite(PIN_TRIAC_MIN_N,  0);
  digitalWrite(PIN_STROBE_MIN,   0);
  
  Serial.println("init done.");
}



void isr_strobe_hour() {
  hour_flap.strobe_int++;
}

void isr_strobe_min() {
  minute_flap.strobe_int++;
}

// the loop function runs over and over again forever
void loop() {
  hour_flap.setValue(23);
  delay(5000);
  hour_flap.setValue(5);
  delay(5000);
}
