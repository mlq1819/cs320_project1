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
		
		SingleBimodal singleBimodal = SingleBimodal(16);
		cout << "Single Bimodal 16: " << singleBimodal.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		singleBimodal = SingleBimodal(32);
		cout << "Single Bimodal 32: " << singleBimodal.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		singleBimodal = SingleBimodal(128);
		cout << "Single Bimodal 128: " << singleBimodal.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		singleBimodal = SingleBimodal(256);
		cout << "Single Bimodal 256: " << singleBimodal.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		singleBimodal = SingleBimodal(512);
		cout << "Single Bimodal 512: " << singleBimodal.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		singleBimodal = SingleBimodal(1024);
		cout << "Single Bimodal 1024: " << singleBimodal.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		singleBimodal = SingleBimodal(2048);
		cout << "Single Bimodal 2048: " << singleBimodal.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		DoubleBimodal doubleBimodal = DoubleBimodal(16);
		cout << "Double Bimodal 16: " << doubleBimodal.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		doubleBimodal = DoubleBimodal(32);
		cout << "Double Bimodal 32: " << doubleBimodal.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		doubleBimodal = DoubleBimodal(128);
		cout << "Double Bimodal 128: " << doubleBimodal.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		doubleBimodal = DoubleBimodal(256);
		cout << "Double Bimodal 256: " << doubleBimodal.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		doubleBimodal = DoubleBimodal(512);
		cout << "Double Bimodal 512: " << doubleBimodal.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		doubleBimodal = DoubleBimodal(1024);
		cout << "Double Bimodal 1024: " << doubleBimodal.predict(&file) << "% Accurate" << endl;
		file.clear();
		file.seekg(0, ios_base::beg);
		
		doubleBimodal = DoubleBimodal(2048);
		cout << "Double Bimodal 2048: " << doubleBimodal.predict(&file) << "% Accurate" << endl;
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