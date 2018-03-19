P=Predictors
CFLAGS= -g -Wall

all: $(P)

$(P): $(P).o
	g++ $(CFLAGS) $(P).o -o $(P)

$(P).o: $(P).cpp $(P).h
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

clear:
	clear
	clear
	make run
	
clearmem:
	clear
	claer
	make mem
	
run: all
	rm st1_output.txt
	./$(P) short_trace1.txt st1_output.txt

mem: all
	rm st1_output.txt
	valgrind ./$(P) short_trace1.txt st1_output.txt
	
	
checkmem:  all
	valgrind ./$(P)

clean:
	rm -rf $(P)
	rm -rf $(P).o
	