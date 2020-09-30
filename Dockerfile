FROM yummygooey/raspbian-buster

RUN apt-get update && \
    apt-get -qy install curl \
    ca-certificates \
    cmake \
    g++ \
    git 
    
RUN apt-get install -y libxml2-dev libxslt-dev python3-dev
RUN apt-get install -y python3-pip
RUN apt-get install -y python3-lxml python-lxml
RUN pip3 install gcovr 


RUN apt-get install -y openjdk-11-jre
RUN apt-get install -y curl

# install Paho 
RUN apt-get install -y libssl-dev
RUN git clone https://github.com/eclipse/paho.mqtt.c.git
WORKDIR /paho.mqtt.c
RUN cmake -Bbuild -H. -DPAHO_WITH_SSL=ON
RUN cmake --build build/ --target install
RUN ldconfig
WORKDIR /
RUN git clone https://github.com/eclipse/paho.mqtt.cpp
WORKDIR /paho.mqtt.cpp
RUN cmake -Bbuild -H. -DPAHO_BUILD_DOCUMENTATION=FALSE
RUN cmake --build build/ --target install

WORKDIR /home/weatherStation
COPY . .

# install webhook tools
RUN apt-get install -y wget
RUN wget -O /usr/local/bin/relay https://storage.googleapis.com/webhookrelay/downloads/relay-linux-arm
RUN /bin/bash -c 'chmod +wx /usr/local/bin/relay'

#Jenkins version
ENV JENKINS_VERSION 2.222.1

# Other env variables
ENV JENKINS_HOME /var/jenkins_home
ENV JENKINS_SLAVE_AGENT_PORT 50000
ENV RELAY_KEY cbf989c8-5c87-4561-856b-44c7285720f1
ENV RELAY_SECRET 2aQXLjBbRIbH


# Get Jenkins
RUN curl -fL -o /opt/jenkins.war https://repo.jenkins-ci.org/public/org/jenkins-ci/main/jenkins-war/{$JENKINS_VERSION}/jenkins-war-{$JENKINS_VERSION}.war

# Expose volume
VOLUME ${JENKINS_HOME}

# Expose ports
EXPOSE 8080 ${JENKINS_SLAVE_AGENT_PORT}
