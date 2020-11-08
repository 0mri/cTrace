	# All Targets
all: main

# Tool invocations
# Executable "hello" depends on the files hello.o and run.o.
main: bin/main.o
	@echo 'Building target: main'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/cTrace bin/*.o
	@echo ' '



# SOURCES := src/main.cpp src/Session.cpp src/Graph.cpp src/Tree.cpp src/Agent.cpp src/Virus.cpp src/ContactTracer.cpp

# Depends on the source and header files
bin/main.o: bin/Session.o
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp

bin/Session.o: bin/Graph.o
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Session.o src/Session.cpp

bin/Graph.o: bin/Tree.o
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Graph.o src/Graph.cpp

bin/Tree.o: bin/Virus.o
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Tree.o src/Tree.cpp

bin/Agent.o: bin/Virus.o
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Agent.o src/Agent.cpp

bin/Virus.o: bin/ContactTracer.o
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Virus.o src/Virus.cpp

bin/ContactTracer.o:
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/ContactTracer.o src/ContactTracer.cpp


#Clean the build directory
clean: 
	rm -f bin/*

run:
	bin/cTrace "config1.json"