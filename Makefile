CXX=c++
CXXFLAGS=-Wall -Wextra -std=c++17 -ggdb


#all: ./build/vpl_execution

./vpl_execution: ./build/Funcionario.o ./build/Pessoa.o ./build/Professor.o ./build/main.o 
	${CXX} ${CXXFLAGS} -o ./vpl_execution ./build/*.o

./build/Funcionario.o: ./include/Funcionario.hpp ./src/entidades/Funcionario.cpp 
	${CXX} ${CXXFLAGS} -I ./include/ -c ./src/entidades/Funcionario.cpp -o ./build/Funcionario.o

./build/Pessoa.o: ./include/Pessoa.hpp ./src/entidades/Pessoa.cpp 
	${CXX} ${CXXFLAGS} -I ./include/ -c ./src/entidades/Pessoa.cpp -o ./build/Pessoa.o

./build/Professor.o: ./include/Professor.hpp ./src/entidades/Professor.cpp 
	${CXX} ${CXXFLAGS} -I ./include/ -c ./src/entidades/Professor.cpp -o ./build/Professor.o

./build/main.o: ./include/Funcionario.hpp ./include/Pessoa.hpp ./include/Professor.hpp ./src/main.cpp 
	${CXX} ${CXXFLAGS} -I ./include/ -c ./src/main.cpp -o ./build/main.o

clean:
	rm -rf .build/*