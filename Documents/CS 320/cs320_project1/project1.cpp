#include "Predictors.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]){
	/*if(argc<2){
		cout << "Not enough arguments" << endl;
		return 0;
	}*/
	bool go = true;
	do{
		cout << "Enter file: ";
		string name;
		cin >> name;
		
		
		ifstream file;
		file.open(name);
		while(!file || !file.good()){
			cout << "Bad input file\nEnter file: ";
			if(file.is_open())
				file.close();
			cin >> name;
			file.open(name);
		}
		cout << "Reading " << name << endl;
		AlwaysTaken alwaysTaken = AlwaysTaken();
		cout << "Always Taken: " << alwaysTaken.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		NeverTaken neverTaken = NeverTaken();
		cout << "Never Taken: " << neverTaken.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		SingleBimodal singleBimodal = SingleBimodal();
		cout << "Single Bimodal: " << singleBimodal.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		DoubleBimodal doubleBimodal = DoubleBimodal();
		cout << "Double Bimodal: " << doubleBimodal.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		if(file.is_open())
			file.close();
		
		cout << "Continue? Y/N: ";
		char ch;
		cin >> ch;
		go=(ch=='Y');
	} while (go);
	return 0;
}