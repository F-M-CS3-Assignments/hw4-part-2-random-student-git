all:
	g++ -g -Wall main.cpp -o bdc 

run:
	./bdc

try: all run

