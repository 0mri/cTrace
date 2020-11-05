	# All Targets
all: main

# Tool invocations
# Executable "hello" depends on the files hello.o and run.o.
main: bin/main.o
	@echo 'Building target: main'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/run bin/main.o
	@echo ' '

# Depends on the source and header files
bin/main.o: src/main.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp

#Clean the build directory
clean: 
	rm -f bin/*