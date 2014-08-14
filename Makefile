
CC=gcc
TARGET=linear_list

all:
	$(CC) -o $(TARGET).o $(TARGET).c

clean:
	rm $(TARGET)

execute:
	./$(TARGET).o