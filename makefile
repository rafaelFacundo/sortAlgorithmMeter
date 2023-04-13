main: ./build/main.o
	g++ -Wall -Wextra -std=c++17 -pedantic -o programa ./build/main.o

./build/main.o: ./include/VectorElements.h ./include/SortAlgos.h ./include/RandomNumbers.h
	g++ -c main.cpp -o ./build/main.o


clean:
	rm ./build/*.o