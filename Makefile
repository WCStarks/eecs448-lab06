QueueDemo: main.o Queue.o QueueTester.o
	g++ -g -Wall -std=c++11 main.o Queue.o QueueTester.o -o QueueDemo

QueueTester.o: QueueTester.cpp
	g++ -g -std=c++11 -c QueueTester.cpp

main.o: main.cpp 
	g++ -g -std=c++11 -c main.cpp

clean:
	rm main.o QueueDemo *~
