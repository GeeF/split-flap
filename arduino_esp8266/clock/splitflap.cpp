#include <Arduino.h>

#include "splitflap.h"

uint8_t lookup_hour(uint8_t encoder_val)
{
  // a bit nicer than having a 256 lut the other way round
  for(int i = 0; i < 24; ++i)
  {
    if(hour_lut[i] == encoder_val) return i;
  }
  return 99;
}

uint8_t lookup_minute(uint8_t encoder_val)
{
  for(int i = 0; i < 60; ++i)
  {
    if(minute_lut[i] == encoder_val) return i;
  }
  return 99;
}

void SplitFlap::readEncoder() {
  int prev_val = encoder_val;
  int oneflip = prev_val - 1;
  if (oneflip < 1)
    oneflip = flap_count;

  pinMode(strobe_pin, OUTPUT);
  digitalWrite(strobe_pin, 0); // pull down strobe, this lets us read the EC pins
  
  delay(2);
  
  encoder_val =  digitalRead(ec0_pin);
  encoder_val += digitalRead(ec1_pin) << 1;
  encoder_val += digitalRead(ec2_pin) << 2;
  encoder_val += digitalRead(ec3_pin) << 3;
  encoder_val += digitalRead(ec4_pin) << 4;
  encoder_val += digitalRead(ec5_pin) << 5;

  Serial.println("read encoder value: " + String(encoder_val) + "   hour: " + String(lookup_hour(encoder_val)));
  //Serial.print("single bits: ");
  //for (int i = 0; i < 8; i++) {
  //    Serial.print(!!((encoder_val << i) & 0x80));
  //}
  //Serial.print("\n");

  /*if (encoder_val == 63 || encoder_val != oneflip) { // re-trigger a read if we read an unexpected result. this eliminates the need for real-time finetuning of the read interval.
    encoder_val = prev_val;
    //timerReadEncoder.once_ms(ENCODER_REREAD_DELAY, readEncoder);
    read_error_count++;
    return;
  }*/

  if (encoder_val == encoder_desired_val) {
    digitalWrite(triac_pin, 0);  // stop the motor when we have reached the desired position.
  }

  pinMode(strobe_pin, INPUT); // strobe back to input, this allows the interrupt to be triggered
  strobe_int = 0;
  
  // TODO: nur encoder checken. Management raus in setValue. in ENCODER_REREAD_DELAY Abstand checken
}

void SplitFlap::setValue(uint8_t value)
{
  if(encoder_type == HOUR_ENCODER && value < 24) {
      encoder_desired_val = hour_lut[value];
      
      digitalWrite(triac_pin, 1);
      while(encoder_desired_val != encoder_val)
      {
        delay(.1);
        readEncoder();
        // enter failsafe after x seconds to avoid permanently running motos in case of an error
      }
  }
  else if(encoder_type == MIN_ENCODER && value < 60) {
    encoder_desired_val = minute_lut[value];
    
  }
  else {
    return;
  }
}