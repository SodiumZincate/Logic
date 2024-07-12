if [ -z "$1" ]; then
	echo -e "Usage: $0 <Number of Bits(1-8)>\nExample: ./cbuild.sh 2"
	exit 1
fi

g++ -o main.o -c main.cpp
g++ -o circuit.o -c circuit.cpp

g++ -o main main.o circuit.o
./main $1

rm *.o > /dev/null 2>&1