MODULES = ../modules

CFLAGS = -g -Wall -I.

PROGRAM = ex3

OBJS = main.o

include $(MODULES)/dictionary/make.inc

$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM)

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)