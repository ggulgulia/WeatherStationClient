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
* All Components for the project: 
![](Images/setup1.jpg)
* Setup  (connected components)
![](Images/setup2.jpg)
* Close up of sensor connection: front view
![](Images/setup3.jpg)
* Close up of sensor connection: rear view
![](Images/setup4.jpg)

### Step 4: Get the data from the device files
Run the following commands
* cd /sys/bus/w1/devices && ls
* cd 28-XXXXXXXXXXX (where xxx is the file number you will see with ls)
* cat temperature (this will print the temperature on terminal)

### Step 5 Docker Image with all dependencies including jenkins
* To build the docker image from the dockerfile run the following:
	docker build -t <name-of-image> . 
  '.' refers to path to the docker file here assumed that docker file is in current directory

* To run the docker image making sure the volume having jenkins state (p/w's , plugins etc.)
  persisted run the (new) docker container as
	docker run --network="host" -v jenkins:/var/jenkins_home -it --name=<name-of-container> <name-of-image> bash

* To run the docker image with a binded volume to system files run the following command
  docker run --network="host" -it -v jenkinsVol1:/var/jenkinsVol --mount  type=bind,source=/sys/bus/w1/devices/28-00000b65fafc,target=/sys/bus/w1/devices/28-00000b65fafc/ --name=as1 rpi bash
  source is where the sensor files are stored on your system and target is where you want to copy those files on your docker container. 

