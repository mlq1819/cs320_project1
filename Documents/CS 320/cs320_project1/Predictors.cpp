#include "Predictors.h"

using namespace std;

double AlwaysTaken::percent(){
	return ((double) this->correct)/this->total;
}

double AlwaysTaken::predict(ifstream file){
	file.open();
	string str;
	while(getline(file, str)){
		if(str[11]=='T')
			this->correct++;
		this->total++;
	}
	file.close();
	return this->percent();
}

double NeverTaken::percent(){
	return ((double) this->correct)/this->total;
}

double NeverTaken::predict(ifstream file){
	file.open();
	string str;
	while(getline(file, str)){
		if(str[11]=='N')
			this->correct++;
		this->total++;
	}
	file.close();
	return this->percent();
}

double singleBimodal::percent(){
	return ((double) this->correct)/this->total;
}

double singleBimodal::predict(ifstream file){
	file.open();
	string str;
	while(getline(file, str)){
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
	file.close();
	return this->percent();
}

double doubleBimodal::percent(){
	return ((double) this->correct)/this->total;
}

double doubleBimodal::predict(ifstream file){
	file.open();
	string str;
	while(getline(file, str)){
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
	file.close();
	return this->percent();
}