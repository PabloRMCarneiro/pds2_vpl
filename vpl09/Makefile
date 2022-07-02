./jogo_execution: jogo_da_vida.o main.o
	c++ -o ./jogo_execution jogo_da_vida.o main.o
./jogo_da_vida.o: jogo_da_vida.h jogo_da_vida.cpp
	c++ -c jogo_da_vida.cpp -o jogo_da_vida.o
./main.o: jogo_da_vida.h main.cpp
	c++ -c main.cpp
clean:
	rm *.o
execution:
	./jogo_execution
	