#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


int input1 = 2, 
    input2 = 3,
    input3 = 4,
    input4 = 5,
    input5 = 6;

#define LED_PIN    8
#define LED_COUNT 10
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

const uint32_t purple = strip.Color(112,40,163);
const uint32_t off = strip.Color(0,0,0);

void setup() {
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif
  
  Serial.begin(9600);
  pinMode(input1, INPUT_PULLUP);
  pinMode(input2, INPUT_PULLUP);
  pinMode(input3, INPUT_PULLUP);
  pinMode(input4, INPUT_PULLUP);
  pinMode(input5, INPUT_PULLUP);

  strip.begin();
  strip.setBrightness(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
  bool button1 = !digitalRead(input1);
  bool button2 = !digitalRead(input2);
  bool button3 = !digitalRead(input3);
  bool button4 = !digitalRead(input4);
  bool button5 = !digitalRead(input5);

  accomplishments(button1);
  fostering(button2);
  future_goals(button3);
  opportunities(button4);
  community_outreach(button5);
}

void accomplishments(bool on) {
  uint32_t color;
  if(on) {
    color = purple;
  } else {
    color = off;
  }

  set_color(color, 0, 2);
}

void future_goals(bool on) {
  uint32_t color;
  if(on) {
    color = purple;
  } else {
    color = off;
  }

  set_color(color, 4, 2);
}

void opportunities(bool on) {
  uint32_t color;
  if(on) {
    color = purple;
  } else {
    color = off;
  }

  set_color(color, 6, 2);
}

void community_outreach(bool on) {
  uint32_t color;
  if(on) {
    color = purple;
  } else {
    color = off;
  }

  set_color(color, 8, 2);
}

void fostering(bool on) {
  uint32_t color;
  if(on) {
    color = purple;
  } else {
    color = off;
  }

  set_color(color, 2, 2);
}

void set_color(uint32_t color, int starting_led_number, int led_count) {
  for(int i = starting_led_number; i < starting_led_number + led_count; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}
