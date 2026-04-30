# Slot-Machine in Docker

## Описание проекта

Данный проект представляет собой мою самую крутую лабу по С++ и вместе с тем консольное приложение, имитирующее работу игрового автомата **Slot Machine** (однорукий бандит).
---

## Что происходит при запуске

После запуска контейнера стартует само приложение, а не командная строка контейнера.
То есть контейнер используется не как отдельная Linux-среда для ручной работы, а как готовая среда для запуска приложения. И все с ходу можно играть.

---

## Структура проекта

В проекте используются следующие файлы исходного кода:

- `main.cc` — точка входа в программу;
- `Evaluator.cc`, `Evaluator.h` — вычисление выигрыша;
- `Overdrive.cc`, `Overdrive.h` — логика overdrive;
- `PayLine.cc`, `PayLine.h` — линии выплат;
- `Paytable.cc`, `Paytable.h` — таблица выплат;
- `Reel.cc`, `Reel.h` — барабаны;
- `SlotMachine.cc`, `SlotMachine.h` — логика игрового автомата;
- `Field.h`, `Player.h`, `IOverdrive.h`, `IReel.h`, `Symbol.h` — вспомогательные файлы и интерфейсы.

---
## Какие пакеты используются в Dockerfile

На этапе сборки устанавливаются:

- `g++` — компилятор C++;
- `musl-dev` — системные development-файлы для сборки под Alpine.
Они нужны, чтобы собрать исполняемый файл из исходников C++.
В финальном образе пакеты отсутствуют, потому что используется `scratch` — пустой минимальный образ, в который копируется только готовый бинарный файл программы.Сделано все возможное для того чтобы получить доп балл за размер :)
---

## Как устроен Dockerfile

Dockerfile использует **многоэтапную сборку**:

### 1 этап — builder
На этом этапе:
- берётся образ `alpine:3.23`;
- устанавливаются пакеты для сборки;
- создаётся рабочая директория `/app`;
- туда копируются исходники;
- проект компилируется в исполняемый файл `slot-machine`.

### 2 этап — final
На этом этапе:
- используется `scratch`;
- в финальный образ копируется только готовый бинарник;
- при запуске контейнера автоматически запускается программа.

---

## Сам Dockerfile проекта

```dockerfile
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
```
## Надеюсь вы дочитали до этого момента ведь тут ответ на вопрос как же это чудо запустить
Выполните эти команды и наслаждайтесь:

```bash
git clone <ССЫЛКА_НА_РЕПОЗИТОРИЙ>
cd <ИМЯ_РЕПОЗИТОРИЯ>
```
- Сборка
```bash
docker build -t slot-machine .
```
- Запуск
```bash
docker run -it --rm slot-machine
```
- Просмотр размера
```bash
 docker image ls slot-machine
 ```
 ##Запуск с  Docker Compose
  ## Запуск проекта

Для первого запуска проекта вместе с базой данных выполните команды:
```bash
docker compose -f DockerCompose.yml up --build
docker compose -f DockerCompose.yml run --rm game
```

---
##In this point, I remembered that it's better to write README.md in English, but it was too late :((((((
