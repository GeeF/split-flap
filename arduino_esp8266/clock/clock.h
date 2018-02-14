#ifndef CLOCK_H
#define CLOCK_H


#define PIN_EC_HOUR_0    2
#define PIN_EC_HOUR_1    3
#define PIN_EC_HOUR_2    4
#define PIN_EC_HOUR_3    5
#define PIN_EC_HOUR_4    6
#define PIN_EC_HOUR_5    7
#define PIN_TRIAC_HOUR_N 8
#define PIN_STROBE_HOUR  9

#define PIN_EC_MIN_0     10
#define PIN_EC_MIN_1     11
#define PIN_EC_MIN_2     12
#define PIN_EC_MIN_3     13
#define PIN_EC_MIN_4     14 // A0
#define PIN_EC_MIN_5     15 // A1
#define PIN_TRIAC_MIN_N  16 // A2
#define PIN_STROBE_MIN   17 // A3

#define STROBE_READ_DELAY 30
#define ENCODER_REREAD_DELAY 4

#define HOUR_ENCODER   0
#define MIN_ENCODER 1

static const uint8_t hour_lut[24] = {
  62, // 0
  61, // 1
  60, // 2
  59, // 3
  58, // 4
  57, // 5
  56, // 6
  55, // 7
  54, // 8
  53, // 9
  52, // 10
  51, // 11
  50, // 12
  49, // 13
  48, // 14
  47, // 15
  46, // 16
  45, // 17
  44, // 18
  43, // 19
  42, // 20
  41, // 21
  40, // 22
  39  // 23
};

static const uint8_t minute_lut[60] = {
  62, // 0
  61, // 1
  60, // 2
  59, // 3
  58, // 4
  57, // 5
  56, // 6
  55, // 7
  54, // 8
  53, // 9
  52, // 10
  51, // 11
  50, // 12
  49, // 13
  48, // 14
  47, // 15
  46, // 16
  45, // 17
  44, // 18
  43, // 19
  42, // 20
  41, // 21
  40, // 22
  39, // 23
  38, // 24
  37, // 25
  36, // 26
  35, // 27
  34, // 28
  33, // 29
  32, // 30
  30, // 31
  29, // 32
  28, // 33
  27, // 34
  26, // 35
  25, // 36
  24, // 37
  23, // 38
  22, // 39
  21, // 40
  20, // 41
  19, // 42
  18, // 43
  17, // 44
  16, // 45
  15, // 46
  14, // 47
  13, // 48
  12, // 49
  11, // 50
  10, // 51
  9,  // 52
  8,  // 53
  7,  // 54
  6,  // 55
  5,  // 56
  4,  // 57
  3,  // 58
  2   // 59
};

#endif