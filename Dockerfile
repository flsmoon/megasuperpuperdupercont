FROM alpine:3.23 AS builder

RUN apk add --no-cache g++ musl-dev

WORKDIR /app
COPY . .

RUN g++ -std=c++17 -Os -s -static \
    -o slot-machine \
    main.cc Evaluator.cc Overdrive.cc PayLine.cc Paytable.cc Reel.cc SlotMachine.cc

FROM scratch

COPY --from=builder /app/slot-machine /slot-machine

CMD ["/slot-machine"]
