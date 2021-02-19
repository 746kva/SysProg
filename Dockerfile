FROM ubuntu

MAINTAINER "Vladimir Kolov"

RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    nano && \
    mkdir /lab1

ENTRYPOINT ["/bin/bash"]
