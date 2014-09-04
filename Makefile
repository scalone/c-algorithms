
CC=gcc
ifndef TARGET
	TARGET=stack_static
endif

all:
	$(CC) -o $(TARGET).o $(TARGET).c

clean:
	rm $(TARGET)

execute: all
	./$(TARGET).o