FROM resin/rpi-raspbian
ENTRYPOINT []
WORKDIR /home/weatherStation
COPY . .

RUN apt-get update && \
    apt-get -qy install curl \
                build-essential python3-dev \
                ca-certificates \
		python3-pip \
		cmake \
		git
#RUN pip3 install rpi.gpio
CMD ["git", "clone", "git@github.com:google/googletest.git"]
