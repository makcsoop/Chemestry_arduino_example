# Chemistry project "Electrolysis bath"
---
This [repository](https://youtu.be/dQw4w9WgXcQ?si=2A3OTN-mXz0fHq9t) provides code examples for the OLED matrix `Adafruit lib example for oled.ino`, as well as the current project code required for the operation of the electronics `current_ino.ino`. The `electronic circuit.png` file contains a diagram of the connection of electronic components.
**Libraries used:**wqfekjabwqrjkfwasdf hrwfxbiohger 3iohqwafdxvoigt23r iwaefsxbhitr34r hgfxjk ep3[ie32giphurejlrkweokp2-w=0rinfjk;lp[=`-0ie9ruhfgljdfkslpq [=`w-2o03irj
1. `SPI` - Serial Peripheral Interface (SPI), sometimes called a 4-wire interface, is a serial synchronous data transfer interface.
Unlike I2C and UART, SPI requires more signals to operate but can operate at higher speeds. Does not support addressing, instead uses the SS (slave select) signal, which is also sometimes called CS (chip select), CE (chip enable) or SE (slave enable). Supports only one master per bus. The master sets the communication speed and other parameters such as polarity and clock phase. Data exchange occurs in full duplex mode, which means devices on the bus can simultaneously transmit and receive data. The interface uses the following signals (in AVR nomenclature, to obtain the exact names of the signals, refer to the technical documentation of the chip you are working with):

  * MISO (master in slave out) - master input, slave output
  * MOSI (master out slave in) - master output, slave input
  * SCK (serial clock) - clock signal
  * SS (slave select) - slave selection signal.
---
2. `Wire` - This library allows you to communicate with I2C devices, a feature that is present on all Arduino boards. I2C is a very common protocol, primarly used for reading/sending data to/from external I2C components. To learn more, visit this article for Arduino & I2C.
**Note: There are both 7 and 8-bit versions of I2C addresses. 7 bits identify the device, and the eighth bit determines if it’s being written to or read from. The Wire library uses 7 bit addresses throughout. If you have a datasheet or sample code that uses 8-bit address, you’ll want to drop the low bit (i.e. shift the value one bit to the right), yielding an address between 0 and 127. However the addresses from 0 to 7 are not used because are reserved so the first address that can be used is 8. Please note that a pull-up resistor is needed when connecting SDA/SCL pins. Please refer to the examples for more information. MEGA 2560 board has pull-up resistors on pins 20 and 21 onboard.**
---
3. `Adafruit GFX` - graphics core library, this is the 'core' class that all our other graphics libraries derive from.
Install this library in addition to the display library for your hardware. This library is compatible with **all** architectures so you should be able to use it on all the Arduino boards.
---
4. `Adafruit_SSD1306` - SSD1306 oled driver library for monochrome 128x64 and 128x32 displays. This library is compatible with **all** architectures so you should be able to use it on all the Arduino boards.
---
The project was implemented on the basis of the `Arduino Nano` board.
**Electronic modules:**
  * IRF520 mosfet module
  * OLED display
  * 1k potentiometer
  * breadboard
  * power board
---
1. To upload the code to the board you will need software [ArduinoIDE(official site)](https://www.arduino.cc/en/software).
2. Next, select the `tools -> COM port` to which your board is connected, then select the `type of your board`. **Note:** if you are using Arduino nano in the processor section, to avoid any problems with loading, select ATmega328P (Old Bootloader). If you have a different board and still have problems loading the software, try doing the same. Perhaps this will be the solution to your problem.
3. Paste the software from the file `current ino.ino` into Arduino IDE.
4. Click the upload button.
