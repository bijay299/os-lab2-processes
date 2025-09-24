SOURCES = main3.c
OBJS    = $(SOURCES:.c=.o)
TARGET  = my3proc

CC   = gcc
OPTS = -Wall
LIBS =

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
