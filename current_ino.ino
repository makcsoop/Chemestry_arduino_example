// import the required libs below


#include <SPI.h>
#include <Wire.h> 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

#define VERIF 5.1 // Voltage on pin

#define mosfet_pin 3 // pin that controls the MOSFET

static const unsigned char PROGMEM logo_bmp[] = // logo bitmap
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

  int pot;
  int out;

void setup() {
  Serial.begin(115200);

  pinMode(mosfet_pin, OUTPUT); // define control pin as output

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
}

void loop() {
  testdrawstyles();    // Draw 'stylized' characters
}


void testdrawstyles(void) {
  display.clearDisplay();

  display.setTextSize(2);            // 2:1 pixel scale
  display.setTextColor(WHITE);       // Draw white text
  display.setCursor(15,17);            // Start x: 15, y: 17

  float voltage = (float)analogRead(A1) * VERIF / 1024; // voltage read from analog pin A1
  float current = (float)voltage; // (float)voltage / 1000 for basic math

  pot = analogRead(A1); // reading data from potentiometer
  out = map(pot, 0, 1023, 0, 255); // transferring the potentiometer value for writing to the digital mosfet port
  analogWrite(mosfet_pin, out); // writing data to the digital mosfet port

  String output = String("V:") + voltage + " V  " + "I:" + current + " mA"; // output string on display

  display.println(output); // writing output on the screen

  display.display();
  delay(2);
}
