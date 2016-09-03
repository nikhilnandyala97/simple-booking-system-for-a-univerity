all: sample

sample:  main.o LecList.o LabList.o RList.o
	g++ main.o LecList.o LabList.o RList.o -o sample

main.o: main.cpp
	g++ -c main.cpp

LecList.o: LecList.cpp
	g++ -c LecList.cpp

LabList.o: LabList.cpp
	g++ -c LabList.cpp

RList.o: RList.cpp
	g++ -c RList.cpp



clean:
	rm *o sample
