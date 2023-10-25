# Makefile to compile programs for Escape From CS 162 Game.

CC=g++ -std=c++11 -g
exe_file=run

$(exe_file): interface.cpp mazeLocation.o wall.o openSpace.o maze.o mazePerson.o intrepidStudent.o TA.o instructor.o game.o
	$(CC) interface.cpp mazeLocation.o wall.o openSpace.o maze.o mazePerson.o intrepidStudent.o TA.o instructor.o game.o -o $(exe_file)

mazeLocation.o: mazeLocation.cpp mazeLocation.h
	$(CC) -c mazeLocation.cpp

wall.o: wall.cpp wall.h
	$(CC) -c wall.cpp

openSpace.o: openSpace.cpp openSpace.h
	$(CC) -c openSpace.cpp

maze.o: maze.cpp maze.h
	$(CC) -c maze.cpp

mazePerson.o: mazePerson.cpp mazePerson.h
	$(CC) -c mazePerson.cpp

intrepidStudent.o: intrepidStudent.cpp intrepidStudent.h
	$(CC) -c intrepidStudent.cpp

TA.o: TA.cpp TA.h
	$(CC) -c TA.cpp

instructor.o: instructor.cpp instructor.h
	$(CC) -c instructor.cpp

game.o: game.cpp game.h
	$(CC) -c game.cpp

clean:
	rm -f *.o $(exe_file)