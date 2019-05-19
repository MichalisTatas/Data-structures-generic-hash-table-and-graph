MODULES = ../modules

CFLAGS = -g -Wall -I.

PROGRAM = ex1

OBJS = main.o

include $(MODULES)/hash-tables/make.inc

$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM)

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)