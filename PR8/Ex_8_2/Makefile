CC = gcc
CFLAGS = -Wall

TARGET = alarm_app

all: $(TARGET)

$(TARGET): alarm_app.c
	$(CC) $(CFLAGS) -o $(TARGET) alarm_app.c

clean:
	rm -f $(TARGET)