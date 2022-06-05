pp = g++
OBJS = main.o User.o Character.o Enemy.o 

all: maple

maple: main.o User.o Character.o Enemy.o 
	$(pp) $(OBJS) -o maple.exe
	./maple.exe
	del *.o
main.o: main.cpp
	$(pp) -c main.cpp

User.o: User.cpp User.hpp
	$(pp) -c User.cpp

Character.o: Character.cpp Character.hpp
	$(pp) -c Character.cpp

Enemy.o: Enemy.cpp Enemy.hpp
	$(pp) -c Enemy.cpp

clean:
	del main.o User.o Character.o Enemy.o 