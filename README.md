# Tactical Vision Unit
A Raspberry Pi powered tactical vision unit (thermal and infrared) OLED Driver from: 
https://www.buydisplay.com/full-color-1-5-inch-arduino-raspberry-pi-oled-display-module-128x128

## Building on a Raspberry Pi
1. Wire up the OLED as described in the [wiring PDF](https://www.buydisplay.com/full-color-1-5-inch-arduino-raspberry-pi-oled-display-module-128x128)
2. Install the [bcm2835](https://www.airspayce.com/mikem/bcm2835/) library
3. Clone this repo and run `make` from the repo's root directory
4. Install picamera and numpy
5. Run the following programs for infrared vision
`
python3 ir_camera.py
./oled infrared
`
