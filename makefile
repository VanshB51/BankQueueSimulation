# all: tdQ

# tdQ: testDriver_Q.o Queue.h Event.o EmptyDataCollectionException.o
# 	g++ -o tdQ -Wall testDriver_Q.o Event.o EmptyDataCollectionException.o
	
# testDriver_Q.o: testDriver_Q.cpp 
# 	g++ -c -Wall testDriver_Q.cpp
	
# Event.o: Event.cpp Event.h
# 	g++ -c -Wall Event.cpp

# EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h 
# 	g++ -c -Wall EmptyDataCollectionException.cpp

# clean:	
# 	rm -f tdQ *.o

all: bsim

bsim: BankSimApp.o PriorityQueue.h BinaryHeap.h Queue.h Event.o EmptyDataCollectionException.o
	g++ -Wall -o bsim BankSimApp.o Event.o EmptyDataCollectionException.o

BankSimApp.o: BankSimApp.cpp
	g++ -Wall -c BankSimApp.cpp  
	
Event.o: Event.h Event.cpp
	g++ -Wall -c Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:	
	rm -f bsim *.o