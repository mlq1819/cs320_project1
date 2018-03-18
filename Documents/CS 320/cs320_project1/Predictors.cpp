#include "Predictors.h"

using namespace std;

double AlwaysTaken::predict(ifstream * file){
	string str="";
	while(file->getline(str.c_str(), 32)){
		if(str[11]=='T')
			this->correct++;
		this->total++;
	}
	return this->percent();
}

double NeverTaken::predict(ifstream * file){
	string str="";
	while(file->getline(str.c_str(), 32)){
		if(str[11]=='N')
			this->correct++;
		this->total++;
	}
	return this->percent();
}

double SingleBimodal::predict(ifstream * file){
	string str="";
	while(file->getline(str.c_str(), 32)){
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
	string str="";
	while(file->getline(str.c_str(), 32)){
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