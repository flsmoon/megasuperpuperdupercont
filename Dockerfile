FROM debian:12-slim

RUN apt-get update && apt-get install -y \
    g++ \
    libpqxx-dev \
    libpq-dev \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /app

COPY . .
RUN g++ -std=c++17 -O2 \
    -o slot-machine \
    main.cc Database.cc Evaluator.cc Overdrive.cc PayLine.cc Paytable.cc Reel.cc SlotMachine.cc \
    -lpqxx -lpq

CMD ["./slot-machine"]
