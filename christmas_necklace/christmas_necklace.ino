#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Deneyap_DerinlikOlcer.h> 
#include "pitches.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
          
TofRangeFinder TofRangeFinder;   
#define BUZZER 5
#define LED 9

uint8_t distance = 240;
uint8_t detect = 20;
uint8_t counter = 0;

int melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

int tempo[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

void setup() {
    pinMode(BUZZER, OUTPUT);
    pinMode(LED, OUTPUT);
    Serial.begin(115200);             
    TofRangeFinder.begin(0x29);  
    
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display(); 
  delay(1000);     
}

void loop() {
    display.clearDisplay();
    distance = TofRangeFinder.ReadDistance();
    
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    if (distance<200){
      display.setTextSize(2); 
      if (distance<detect){
        sing(counter);
        writeAuguri();
        digitalWrite(LED, counter%2==0);
        Serial.print(sizeof(tempo));
        if (counter==25) counter = 0;
        else counter++;
        
        }
      else{
        display.invertDisplay(false);
        noTone(BUZZER);
        }
      }
    else {
      display.invertDisplay(false);
      noTone(BUZZER);
      }
    display.display();      // Show initial text                                      
}

void writeAuguri() {
  
  display.invertDisplay(counter%2==0);
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor((SCREEN_WIDTH - 6 * 8) / 2, (SCREEN_HEIGHT - 8) / 2);
  display.println("AUGURI");

}

void sing(uint8_t note2sing) {
  // iterate over the notes of the melody:
      
      tone(BUZZER, melody[note2sing], 1000 / tempo[note2sing]);
    
      delay(1000 / tempo[note2sing] * 1.30);
      // stop the tone playing:
      noTone(BUZZER);
  
}
