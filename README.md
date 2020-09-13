## This is the client side set up for IoT Weather Station
### Step 1: Set up Raspberry Pi
* Flash Raspberry Pi OS on an SD Card
* Check if RPI is working and functional

### Step 2: Configure Raspberry PI GPIO Pins
Run the following commands on raspberry pi
* $ sudo vim /boot/config.txt
* Add dtoverlay=w1-gpio on the last line of the file
* sudo reboot
* login again on to your RPI

### Step 3: Set up hardware
* Look at the images provides to attach temperature sensor to RPI 
* Components: ![Optional Text](Images/setup1)

### Step 4: Get the data from the device files
Run the following commands
* cd /sys/bus/w1/devices && ls
* cd 28-XXXXXXXXXXX (where xxx is the file number you will see with ls)
* cat temperature (this will print the temperature on terminal)