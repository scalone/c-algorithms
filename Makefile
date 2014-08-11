
CC=gcc
TARGET=linear_list

all:
	$(CC) -o $(TARGET) $(TARGET).c

clean:
	rm $(TARGET)