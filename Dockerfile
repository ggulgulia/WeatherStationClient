FROM yummygooey/raspbian-buster
WORKDIR /home/weatherStation
COPY . .

RUN apt-get update && \
    apt-get -qy install curl \
    ca-certificates \
    cmake \
    g++ \
    git


RUN apt-get install -y openjdk-11-jre
RUN apt-get install -y curl
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

# Start Jenkins
CMD ["sh", "-c", "java -jar /opt/jenkins.war"]
