#include <TM1637Display.h>

#define CLK 8
#define DIO 9

TM1637Display display(CLK,DIO);

// Define segment patterns for the upper and lower halves of an '8'
// Segment bit mapping (0bDPGEDCBA):
//   ---a----
//  |        |
//  f        b
//  |        |
//   ---g----
//  |        |
//  e        c
//  |        |
//   ---d----

// Full '8' = 0x7F (all segments a,b,c,d,e,f,g)

// Upper half of '8' (segments a,b,f,g)
//  a (0x01) | b (0x02) | f (0x03) | g (0x40) | 

// Lower half of '8' (segments c,d,e,g)
//  c (0x04) | d (0x08) | e (0x10) | g (0x40) | 

const uint8_t SEG_UPPER_HALF_8 = 0x63;
const uint8_t SEG_LOWER_HALF_8 = 0x5C;
const uint8_t SEG_ALL_OFF = 0x00;

const uint8_t ANIMATION_FRAMES [4] = {

    //Forward glowing sequence
    {SEG_ALL_OFF, SEG_ALL_OFF, SEG_ALL_OFF, SEG_ALL_OFF}, //F1- All off
    {SEG_UPPER_HALF_8, SEG_ALL_OFF, SEG_ALL_OFF, SEG_ALL_OFF}, //F1- Digit1- Upper half glows
    {SEG_UPPER_HALF_8, SEG_LOWER_HALF_8, SEG_ALL_OFF, SEG_ALL_OFF}, //F2- Digit1- Upper, Digit2- Lower glows
    {SEG_UPPER_HALF_8, SEG_LOWER_HALF_8, SEG_UPPER_HALF_8, SEG_ALL_OFF}, //F3- Digit1- Upper, Digit2- Lower, Digit3- Lower, Digit4- Upper glows
    {SEG_UPPER_HALF_8, SEG_LOWER_HALF_8, SEG_UPPER_HALF_8, SEG_LOWER_HALF_8}, //F4- Digit1- Upper, Digit2- Lower, Digit3- Upper, Digit4- Lower glows
    SEG_ALL_OFF, seg_lower_half, segment extracolon, semicon 
}

// number of animation frames
const int NUM_ANIMATION_FRAMES = sizeof(ANIMATION_FRAMES) / sizeof(ANIMATION_FRAMES[0]);

// delay between each animation frame
const int ANIMATION_DELAY_MS = 150;

void setup() {
    Serial.begin(115200);
    Serial.println("ESP TM1637 Custom Half-8 Alternating Animation");
     
    //set brightness of display (0-7, 7 is brightest)
    display.setBrightness(0x0c);

    // clear initial display
    display.clear();
    Serial.println("Display cleared...")
}

void loop()  {
    for (int i=0; i < NUM_ANIMATION_FRAMES; i++) 
    {
        display.setSegments(ANIMATION_FRAMES[i], 4, 0);

        Serial.print("Displaying frame: ")
        for (int j= 0, j< 4; j++)
        {
            Serial.print(ANIMATION_FRAMES[i][j],HEX);
            Serial.print(" ");
        }
        Serial.println();
        delay(ANIMATION_DELAY_MS);
    }
}


