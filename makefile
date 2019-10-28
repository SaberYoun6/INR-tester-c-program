CC=gcc
CFLAGS=-lpigpio -lrt lpthread -Wall -g
DEPS= iNR.h
PROG=myprog
#commit why does it want me to tab out the file
%.o: %.c $(DEPS)
        $(CC) -c $(CFLAGS) -o $@ $< $(DEPS)

$(PROG): main.o iNR.o
        $(CC) -c -o $@ $< $^


clean: :$
      \rm -fr *.o 



