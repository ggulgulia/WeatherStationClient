#FROM resin/rpi-raspbian
FROM yummygooey/raspbian-buster
ENTRYPOINT []
WORKDIR /home/weatherStation
COPY . .

RUN apt-get update && \
    apt-get -qy install curl \
    python3 \
    ca-certificates \
    python3-pip \
    cmake \
    g++ \
    git
#RUN pip3 install rpi.gpio
