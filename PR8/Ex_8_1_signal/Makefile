CC = gcc
CFLAGS = -Wall -Werror

TARGET = signal_handling

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)