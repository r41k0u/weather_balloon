#include <SoftwareSerial.h>

#define READING 0
#define CLOSED 1

int NO2pin = A0;
int NO2value = 0;
float NO2resistance;
float NO2seriesResistor = 22000;
float NO2measure = 0;

void setup() {
  state = READING;

  Serial.begin(9600);
  pinMode(NO2pin, INPUT);
}

void loop() {

  if (state == READING) {
    int NO2rawInput = analogRead(NO2pin);
    NO2resistance = NO2seriesResistor * ((1023.0 / NO2rawInput) - 1.0);
    NO2measure = NO2resistance / 100;
    Serial.print(',');
    Serial.println(NO2measure)
    delay(500);
  }