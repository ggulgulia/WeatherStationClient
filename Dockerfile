FROM yummygooey/raspbian-buster
WORKDIR /home/weatherStation
COPY . .

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

# install webhook tools
RUN apt-get install -y wget
RUN wget -O /usr/local/bin/relay https://storage.googleapis.com/webhookrelay/downloads/relay-linux-arm
RUN /bin/bash -c 'chmod +wx /usr/local/bin/relay'
# Jenkins version

ENV JENKINS_VERSION 2.222.1

# Other env variables
ENV JENKINS_HOME /var
ENV JENKINS_SLAVE_AGENT_PORT 50000


# Get Jenkins
RUN curl -fL -o /opt/jenkins.war https://repo.jenkins-ci.org/public/org/jenkins-ci/main/jenkins-war/{$JENKINS_VERSION}/jenkins-war-{$JENKINS_VERSION}.war

# Expose volume
VOLUME ${JENKINS_HOME}

# Expose ports
EXPOSE 8080 ${JENKINS_SLAVE_AGENT_PORT}
