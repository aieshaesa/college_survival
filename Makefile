CFLAGS = -I ./include
##LIB    = ./lib/fmod/libfmodex64.so
LFLAGS = -lrt -lX11 -lGLU -lGL -lm #-lXrandr

all: dmesa.o college

dmesa.o: dmesa.cpp
	g++ -c dmesa.cpp -Wall

college: college_survival.cpp log.cpp
	g++ $(CFLAGS) college_survival.cpp log.cpp libggfonts.a dmesa.o -Wall -Wextra $(LFLAGS) -o college

clean:
	rm -f college
	rm -f *.o

