FROM yummygooey/raspbian-buster
WORKDIR /home/weatherStation
COPY . .

#RUN apt-get update && \
#    apt-get -qy install curl \
#    ca-certificates \
#    cmake \
#    g++ \
#    git \
#    wget


#RUN apt-get update && \
#    apt-get install -y openjdk-11-jre \
#    wget
#    #apt-get install openjdk-11-jre
#
#RUN wget -q -O - https://pkg.jenkins.io/debian/jenkins.io.key | apt-key add -
#RUN echo 'deb https://pkg.jenkins.io/debian binary/' >> /etc/apt/sources.list.d/jenkins.list
#RUN apt-get update
#RUN apt-get install -y jenkins
# Add Tini
ENV TINI_VERSION v0.19.0
ADD https://github.com/krallin/tini/releases/download/${TINI_VERSION}/tini /bin/tini
RUN chmod +x /bin/tini
COPY jenkins.sh /usr/local/bin/jenkins.sh
RUN chmod +x /usr/local/bin/jenkins.sh
#ENTRYPOINT ["/bin/tini", "--", "/usr/local/bin/jenkins.sh"]
