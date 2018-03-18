P=project1
Q=Predictors
CFLAGS= -g -Wall

all: $(P)

$(P): $(P).o $(Q).o
	g++ $(CFLAGS) $(P).o $(Q).o -o $(P)

$(P).o: $(P).cpp $(Q).h
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o
	
$(Q).o: $(Q).cpp $(Q).h
	g++ $(CFLAGS) -c $(Q).cpp -o $(Q).o

clear:
	clear
	clear
	make run
	
run: all
	./$(P)

checkmem:  all
	valgrind ./$(P)

clean:
	rm -rf $(P)
	rm -rf $(P).o
	rm -rf $(Q).o
	