#include "Predictors.h"
#define MAX_SIZE 32

using namespace std;

bool readTheLine(ifstream file, char* str){
	int i=0;
	while(i<MAX_SIZE){
		char ch;
		file >> ch;
		if(ch!='\n')
			str[i++] = ch;
		else break;
	}
	if(i!=MAX_SIZE)
		return true;
	return false;
}

double AlwaysTaken::predict(ifstream * file){
	char str[MAX_SIZE];
	while(readTheLine(*file, str)){
		if(str[11]=='T')
			this->correct++;
		this->total++;
	}
	return this->percent();
}

double NeverTaken::predict(ifstream * file){
	char str[MAX_SIZE];
	while(readTheLine(*file, str)){
		if(str[11]=='N')
			this->correct++;
		this->total++;
	}
	return this->percent();
}

double SingleBimodal::predict(ifstream * file){
	char str[MAX_SIZE];
	while(readTheLine(*file, str)){
		unsigned long index = stoul(str.substr(2,8), nullptr, 16);
		bool num = this->history[index];
		if(str[11]=='T' && num)
			this->correct++;
		else if(str[11]=='N' && !num)
			this->correct++;
		else
			this->history[index]=!num;
		this->total++;
	}
	return this->percent();
}

double DoubleBimodal::predict(ifstream * file){
	char str[MAX_SIZE];
	while(readTheLine(*file, str)){
		unsigned long index = stoul(str.substr(2,8), nullptr, 16);
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
		this->total++;
	}
	return this->percent();
}