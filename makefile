# All Targets
all: bin/cTrace

bin/cTrace: bin/main.o
	@echo 'Invoking: C++ Linker'
	g++ -o bin/cTrace bin/*.o
	@echo 'Done.'




# Depends on the source and header files
bin/main.o: bin/Session.o bin/Graph.o bin/CycleTree.o bin/MaxRankTree.o bin/RootTree.o bin/Tree.o bin/Virus.o bin/ContactTracer.o bin/Agent.o
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp

bin/Session.o: 
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Session.o src/Session.cpp

bin/Graph.o: 
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Graph.o src/Graph.cpp

bin/CycleTree.o: 
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/CycleTree.o src/CycleTree.cpp

bin/MaxRankTree.o: 
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/MaxRankTree.o src/MaxRankTree.cpp

bin/RootTree.o: 
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/RootTree.o src/RootTree.cpp

bin/Tree.o: 
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Tree.o src/Tree.cpp

bin/Virus.o: 
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Virus.o src/Virus.cpp

bin/ContactTracer.o: 
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/ContactTracer.o src/ContactTracer.cpp

bin/Agent.o: 
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Agent.o src/Agent.cpp

#Clean the build directory
clean: 
	rm -f bin/*


run:
	bin/cTrace config1.json

# Check memory leaks
ml:
	valgrind --leak-check=full --show-reachable=yes bin/cTrace config1.json

# clean, compile and run
s: clean all run