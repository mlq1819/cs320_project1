#include "Predictors.h"
#define MAX_SIZE 32

using namespace std;

double AlwaysTaken::predict(ifstream * file){
	string str;
	while(getline(*file, str)){
		this->total++;
		if(str[11]=='T')
			this->correct++;
	}
	return this->percent();
}

double NeverTaken::predict(ifstream * file){
	string str;
	while(getline(*file, str)){
		this->total++;
		if(str[11]=='N')
			this->correct++;
	}
	return this->percent();
}

double SingleBimodal::predict(ifstream * file){
	string str;
	while(getline(*file, str)){
		this->total++;
		unsigned long index = stoi(str.substr(2,8), 0, 16);
		bool num = this->history[index];
		if(str[11]=='T' && num)
			this->correct++;
		else if(str[11]=='N' && !num)
			this->correct++;
		else
			this->history[index]=!num;
	}
	return this->percent();
}

double DoubleBimodal::predict(ifstream * file){
	string str;
	while(getline(*file, str)){
		this->total++;
		unsigned long index = stoi(str.substr(2,8), 0, 16);
		int num = this->history[index];
		if(str[11]=='T'){
			if(num>1)
				this->correct++;
			if(num<3)
				this->history[index]++;
		}
		else if(str[11]=='N'){
			if(num>1)
				this->correct++;
			if(num>0)
				this->history[index]--;
		}
	}
	return this->percent();
}