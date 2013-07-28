CFLAGS += -I ./dfilt_fxp

all: dfilt.o dfilt_fxp.o
	gcc dfilt.o dfilt_fxp.o -o dfilt  

dfilt_fxp.o: dfilt_fxp/dfilt_fxp.c
	@echo $< $@ $^ $*
	gcc $(CFLAGS) -c $<

clean:
	-rm  dfilt.o dfilt_fxp.o dfilt

