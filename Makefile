CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lm

TARGET = simulador_artemis
OBJS = main.o artemis.o validaciones.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
	
