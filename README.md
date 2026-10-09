# HackClubHalfLife PCB Week
My project is inspired from easily available LED Display Module. I plan to make PCB aroung its circuitry and logics. \
The LEDs on this display module works because of an IC called TM1637 IC. \
The TM1637 IC can run LED displays & Keyboards in 6by8 and 2by8 matrix repectively. 

<img width="300" height="300" alt="image" src="https://github.com/user-attachments/assets/ee46d2f1-e65e-416a-8f27-b4b746badebf" />


# Features of using TM1637 ic to make the led display pcb:
1. Display mode & Keyboard mode
2. Key scan pins, Segment pins & Grid pins
3. Adjustable brightness of 8 cycles 
4. 20 pin IC

<img width="500" height="200" alt="image" src="https://github.com/user-attachments/assets/4b86bff5-dba3-41b1-91d1-78d7a9799000" />


# Can display using many things:
1. Number and selected alphabets
2. Temperature in degree celsius and fahrenheit
3. Scrolling text
4. Number counter or timer
5. Alarm clock by adding time module

# My project specifications- 
4 Digits made with 7 segments with one colon between them. \
Total 30 leds, 2 resitors, 2 capacitors and 1 TM1637 IC required that will be soldered on the PCB. \
Other components needed for running the PCB are jumper cables and ESP32 microcontroller. \
There are two types of led connection we can make- common anode or common cathode configuration.

# TM1637 IC connections
1. 8 SEGMENT pins & 4 GRID pins on the IC will be used to make LED display.
2. GRID pins will be used for each digit in a display. IC has 6 grid pins. I am making a 4 digit 7 segment display. So, I will only use 4 grid pins.
3. SEGMENT pins will be used for each segment in a display. IC has 8 segment pins. I am making a 4 digit 7 segment display. So, I will use all pins because 7 pins for 7 segments & 1 for colon leds.

<img width="300" height="300" alt="image" src="https://github.com/user-attachments/assets/cc25d200-0f94-4601-b434-81924b6c133b" />





<img width="1143" height="225" alt="image" src="https://github.com/user-attachments/assets/0c764abb-a595-417b-a6bc-b8eec3a4042f" />
