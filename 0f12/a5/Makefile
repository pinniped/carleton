CC = g++
#CFLAGS = -g -O2
CFLAGS = -Wall
OBJECTS = assign5.o node.o

a.exe : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

%.o : %.c %.h
	$(CC) $(CFLAGS) -c $<
