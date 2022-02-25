CFLAGS = -I ./include
##LIB    = ./lib/fmod/libfmodex64.so
LFLAGS = -lrt -lX11 -lGLU -lGL -lm #-lXrandr

all: college

college: college_survival.cpp log.cpp
	g++ $(CFLAGS) college_survival.cpp log.cpp libggfonts.a -Wall -Wextra $(LFLAGS) -o college

clean:
	rm -f college
	rm -f *.o

