# ESP32 Development Setup with Arduino IDE

This guide will walk you through the process of downloading and configuring the Arduino IDE for ESP32 development on Linux, macOS, and Windows.

## Prerequisites

- Internet connection
- Basic knowledge of using the command line (for Linux and macOS)

## Step 1: Download Arduino IDE

1. Go to the [Arduino Software](https://www.arduino.cc/en/software) page.
2. Download the Arduino IDE appropriate for your operating system:
   - For Linux: Choose the "Linux" version.
   - For macOS: Choose the "macOS" version.
   - For Windows: Choose the "Windows Installer" version.
3. Install the Arduino IDE following the installation instructions for your operating system.

## Step 2: Install ESP32 Board Support

### For Linux and macOS:

1. Open Arduino IDE.
2. Go to `File > Preferences`.
3. In the "Additional Board Manager URLs" field, add the following URL:
https://dl.espressif.com/dl/package_esp32_index.json
4. Click "OK" to close the Preferences window.
5. Go to `Tools > Board > Boards Manager`.
6. Search for "esp32" and install "ESP32 by Espressif Systems".
7. Once installed, select your ESP32 board from `Tools > Board`.

### For Windows:

1. Open Arduino IDE.
2. Go to `File > Preferences`.
3. In the "Additional Board Manager URLs" field, add the following URL:
https://dl.espressif.com/dl/package_esp32_index.json
4. Click "OK" to close the Preferences window.
5. Go to `Tools > Board > Boards Manager`.
6. Search for "esp32" and install "ESP32 by Espressif Systems".
7. Once installed, select your ESP32 board from `Tools > Board`.

## Step 3: Connect ESP32 Board

1. Connect your ESP32 development board to your computer using a USB cable.

## Step 4: Verify Setup

1. Open Arduino IDE.
2. Go to `File > Examples > ESP32 > Blink`.
3. Verify that the correct board and port are selected under `Tools`.
4. Click on the "Upload" button (right arrow icon) to compile and upload the Blink sketch to your ESP32 board.
5. After the upload is complete, the onboard LED should start blinking.

Congratulations! You have successfully set up the Arduino IDE for ESP32 development.


