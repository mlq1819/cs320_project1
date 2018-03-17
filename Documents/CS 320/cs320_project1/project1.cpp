#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]){
	if(argc>2){
		cout << "Too many arguments" << endl;
		return 0;
	}
	ifstream file(argv[1]);
	if(!file){
		cout << "Bad input file" << endl;
		return 0;
	} else {
		cout << "Reading " << argv[1] << endl;
	}
	
	
	
//	in.close();
	return 0;
}