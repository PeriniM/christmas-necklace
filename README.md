# Introduction
Arduino sketch that uses a time-of-flight (ToF) range finder sensor and OLED display to detect objects (people) within a certain distance and display a message. The code also uses a piezo buzzer and LED to greet the person in front of you!

# Prerequisites
Before you get started, you'll need to have the following tools installed:

- Arduino IDE (download from the official site);
- Adafruit SSD1306 library (can be installed through the Arduino Library Manager);
- Deneyap_DerinlikOlcer library (can be installed through the Arduino Library Manager).

You'll also need the following hardware:

- Arduino-compatible microcontroller board (such as an Arduino Uno)
- OLED display that is compatible with the SSD1306 library
- ToF range finder sensor
- Piezo buzzer and LED (optional)

# Installing
To get started, follow these steps:

1. Download the code from this repository and extract the zip file to a local directory.
2. Open the xyz.ino file in the Arduino IDE.
3. Install the Adafruit SSD1306 library and the Deneyap_DerinlikOlcer library if you haven't already done so.
4. Connect your OLED display and ToF range finder sensor to your microcontroller board according to the wiring diagrams in the code comments.
5. Upload the code to your microcontroller board.

# Usage
Once the code is uploaded to your microcontroller board, it will automatically begin detecting objects within a certain distance and displaying a message on the OLED display. If a piezo buzzer and LED are connected, they will also be used to indicate when an object is detected.

You can adjust the distance at which the sensor will detect objects by changing the detect variable in the code. The default value is 20 cm.

# Support
If you have any questions or issues with this project, please feel free to open an issue on this repository.

# License
This project is licensed under the MIT License - see the LICENSE file for details.
