CC = g++
OBJ= assign4.o heap.o

all : a

a : $(OBJ)
	@echo "target = $@"
	@echo "sources = $?"
	@echo "wassat $<"
	#$(CC) -o $@ %.o

%.o : %.c %.h
	#$(CC) -c -g $<
