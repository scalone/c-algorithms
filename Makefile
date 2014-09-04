
CC=gcc
ifndef TARGET
	TARGET=stack
endif


all:
	$(CC) -o $(TARGET).o $(TARGET).c

clean:
	rm $(TARGET)

execute:
	./$(TARGET).o