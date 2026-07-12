FROM ubuntu:26.04 AS BASE


FROM BASE AS DEV_INIT
RUN apt-get update && \ 
    apt-get install -y --no-install-recommends \
    build-essential \
    cmake

FROM DEV_INIT AS FINISH_LINE

RUN echo "Build finished! =^u^= "