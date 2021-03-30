## Instructions on how to run the Weather station

### Step 1: Starting the Jenkins CI
* From the browser log on to 192.168.0.226:8080 
* Enter the login credentials
* If the jenkins is configured to use the local volume that caches all data then we're good to go
* Else create a local volume and restart jenkins, configure all plugins and create a 'multibranch' pipeline
* In the configuration for the pipeline specify the correct path to jenkinsfile

## Step 2: Running the Weather Station
* log in to the raspberry pi
* start the container:
```
    docker start WeatherStation
```
* Attach a terminal to the container:
```
    docker exec -it WeatherStation bash
```
This command should land the user in the `weatherStation` directory
* Once inside the docker container, cd to the build directory of sensor interface:
```
    cd sensor_interface\build
```
* Build the project:
```
    cmake .. -DCMAKE_BUILD_TYPE=Debug -DCOVERAGE=On
```
this creates an executable `weather_station` in the build directory

* On execution of the application, the temperature is published on the local host, which is the docker container in this case. To be able to subscribe to the temperature data, open a terminal in another computer within the same network as the raspberry pi and run the following command:
```
    mosquitto_sub -h 192.168.0.226 -t '#'
```  
where the ip address is that of the raspberry pi and -t flag denotes the topic to be subscribed and the wildcard `#` denotes any topic being published by the app 


