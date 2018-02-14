#ifndef SPLITFLAP_H
#define SPLITFLAP_H

#include "clock.h"

class SplitFlap {
  public:
    const uint8_t encoder_type = HOUR_ENCODER;
    const uint8_t flap_count = 0;
    
    const uint8_t triac_pin  = 0;
    const uint8_t strobe_pin = 0;
    const uint8_t ec0_pin = 0;
    const uint8_t ec1_pin = 0;
    const uint8_t ec2_pin = 0;
    const uint8_t ec3_pin = 0;
    const uint8_t ec4_pin = 0;
    const uint8_t ec5_pin = 0;

    uint8_t read_error_count = 0;
    uint8_t encoder_val = 0;
    uint8_t encoder_desired_val = 0;
    volatile uint8_t strobe_int = 0;

    SplitFlap(uint8_t type, uint8_t flap_count, uint8_t triac_pin, uint8_t strobe_pin,
              uint8_t ec0_pin, uint8_t ec1_pin, uint8_t ec2_pin, uint8_t ec3_pin,
              uint8_t ec4_pin, uint8_t ec5_pin) :
                encoder_type(type), flap_count(flap_count), triac_pin(triac_pin),
                strobe_pin(strobe_pin), ec0_pin(ec0_pin), ec1_pin(ec1_pin), ec2_pin(ec2_pin),
                ec3_pin(ec3_pin), ec4_pin(ec4_pin), ec5_pin(ec5_pin)
              {}

    void readEncoder();
    void setValue(uint8_t value);
};

#endif