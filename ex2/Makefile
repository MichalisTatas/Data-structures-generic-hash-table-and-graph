MODULES = ../modules

CFLAGS = -g -Wall -I.

PROGRAM = ex2

OBJS = main.o

include $(MODULES)/graphs/make.inc

$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM)

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)