#include "Predictors.h"
#define OUTPUT true

using namespace std;

int main(int argc, char *argv[]){
	if((OUTPUT && argc<3) || argc<2){
		cout << "Not enough arguments" << endl;
		return 0;
	}
	ifstream file;
	file.open(argv[1]);
	if(!file || !file.good()){
		cout << "Bad input file" << endl;
		if(file.is_open())
			file.close();
		return 1;
	}
	
	ofstream output;
	if(OUTPUT){
		output.open(argv[2]);
		if(!output || !output.good()){
			cout << "Bad output file" << endl;
			if(output.is_open())
				output.close();
			return 1;
		}
	}
	
	cout << "Reading from" << argv[1] << endl;
	if(OUTPUT)
		cout << "Outputting to " << argv[2] << endl;
	AlwaysTaken alwaysTaken = AlwaysTaken();
	cout << "Always Taken: \t\t" << endl;
	cout << alwaysTaken.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << alwaysTaken.getCorrect() << "," << alwaysTaken.getTotal() << ";" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	
	
	NeverTaken neverTaken = NeverTaken();
	cout << "Never Taken: \t\t" << endl;
	cout << neverTaken.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << neverTaken.getCorrect() << "," << neverTaken.getTotal() << ";" << endl;	
	file.clear();
	file.seekg(0, ios_base::beg);
	
	
	
	SingleBimodal singleBimodal = SingleBimodal(16);
	cout << "Single Bimodal 16: \t" << endl;
	cout << singleBimodal.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << singleBimodal.getCorrect() << "," << singleBimodal.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	singleBimodal = SingleBimodal(32);
	cout << "Single Bimodal 32: \t" << endl;
	cout << singleBimodal.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << singleBimodal.getCorrect() << "," << singleBimodal.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	singleBimodal = SingleBimodal(128);
	cout << "Single Bimodal 128: \t" << endl;
	cout << singleBimodal.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << singleBimodal.getCorrect() << "," << singleBimodal.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	singleBimodal = SingleBimodal(256);
	cout << "Single Bimodal 256: \t" << endl;
	cout << singleBimodal.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << singleBimodal.getCorrect() << "," << singleBimodal.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	singleBimodal = SingleBimodal(512);
	cout << "Single Bimodal 512: \t" << endl;
	cout << singleBimodal.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << singleBimodal.getCorrect() << "," << singleBimodal.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	singleBimodal = SingleBimodal(1024);
	cout << "Single Bimodal 1024: \t" << endl;
	cout << singleBimodal.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << singleBimodal.getCorrect() << "," << singleBimodal.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	singleBimodal = SingleBimodal(2048);
	cout << "Single Bimodal 2048: \t" << endl;
	cout << singleBimodal.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << singleBimodal.getCorrect() << "," << singleBimodal.getTotal() << ";" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	
	
	DoubleBimodal doubleBimodal = DoubleBimodal(16);
	cout << "Double Bimodal 16: \t" << endl;
	cout << doubleBimodal.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << doubleBimodal.getCorrect() << "," << doubleBimodal.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	doubleBimodal = DoubleBimodal(32);
	cout << "Double Bimodal 32: \t" << endl;
	cout << doubleBimodal.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << doubleBimodal.getCorrect() << "," << doubleBimodal.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	doubleBimodal = DoubleBimodal(128);
	cout << "Double Bimodal 128: \t" << endl;
	cout << doubleBimodal.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << doubleBimodal.getCorrect() << "," << doubleBimodal.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	doubleBimodal = DoubleBimodal(256);
	cout << "Double Bimodal 256: \t" << endl;
	cout << doubleBimodal.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << doubleBimodal.getCorrect() << "," << doubleBimodal.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	doubleBimodal = DoubleBimodal(512);
	cout << "Double Bimodal 512: \t" << endl;
	cout << doubleBimodal.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << doubleBimodal.getCorrect() << "," << doubleBimodal.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	doubleBimodal = DoubleBimodal(1024);
	cout << "Double Bimodal 1024: \t" << endl;
	cout << doubleBimodal.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << doubleBimodal.getCorrect() << "," << doubleBimodal.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	doubleBimodal = DoubleBimodal(2048);
	cout << "Double Bimodal 2048: \t" << endl;
	cout << doubleBimodal.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << doubleBimodal.getCorrect() << "," << doubleBimodal.getTotal() << ";" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	
	
	GShare gshare = GShare(3);
	cout << "GShare 3: \t" << endl;
	cout << gshare.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << gshare.getCorrect() << "," << gshare.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	gshare = GShare(4);
	cout << "GShare 4: \t" << endl;
	cout << gshare.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << gshare.getCorrect() << "," << gshare.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	gshare = GShare(5);
	cout << "GShare 5: \t" << endl;
	cout << gshare.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << gshare.getCorrect() << "," << gshare.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	gshare = GShare(6);
	cout << "GShare 6: \t" << endl;
	cout << gshare.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << gshare.getCorrect() << "," << gshare.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	gshare = GShare(7);
	cout << "GShare 7: \t" << endl;
	cout << gshare.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << gshare.getCorrect() << "," << gshare.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	gshare = GShare(8);
	cout << "GShare 8: \t" << endl;
	cout << gshare.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << gshare.getCorrect() << "," << gshare.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	gshare = GShare(9);
	cout << "GShare 9: \t" << endl;
	cout << gshare.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << gshare.getCorrect() << "," << gshare.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	gshare = GShare(10);
	cout << "GShare 10: \t" << endl;
	cout << gshare.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << gshare.getCorrect() << "," << gshare.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	gshare = GShare(11);
	cout << "GShare 11: \t" << endl;
	cout << gshare.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << gshare.getCorrect() << "," << gshare.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	
	if(file.is_open())
		file.close();
	return 0;
}

template <class T>
List<T>::List(unsigned int size, T def){
	this->addresses = new unsigned long[size];
	this->data = T[size];
	for(unsigned int i=0; i<size; i++)
		this->data[i]=def;
	this->size = size;
	this->def = def;
	this->soft_cur=this->hard_cur=0;
}

template <class T>
bool List<T>::add(unsigned long address){
	this->addresses[this->hard_cur]=address;
	this->data[this->hard_cur]=this->def;
	this->soft_cur=this->hard_cur=(this->hard_cur+1)%this->size;
	return true;
}

template <class T>
bool List<T>::has(unsigned long address){
	if(this->addresses[this->soft_cur]==address)
		return true;
	this->soft_cur=this->hard_cur;
	do{
		if(this->addresses[this->soft_cur]==address)
			return true;
		if(this->soft_cur==0)
			this->soft_cur+=this->size;
		this->soft_cur--;
	} while (this->soft_cur!=this->hard_cur);
	return false;
}

template <class T>
T List<T>::get(unsigned long address){
	if(this->addresses[this->soft_cur]==address)
		return this->data[this->soft_cur];
	this->soft_cur=this->hard_cur;
	do{
		if(this->addresses[this->soft_cur]==address)
			return this->data[this->soft_cur];
		if(this->soft_cur==0)
			this->soft_cur+=this->size;
		this->soft_cur--;
	} while (this->soft_cur!=this->hard_cur);
	return this->def;
}

template <class T>
bool List<T>::set(unsigned long address, T data){
	if(this->addresses[this->soft_cur]==address){
		this->data[this->soft_cur]=data;
		return true;
	}
	this->soft_cur=this->hard_cur;
	do{
		if(this->addresses[this->soft_cur]==address){
			this->data[this->soft_cur]=data;
			return true;
		}
		if(this->soft_cur==0)
			this->soft_cur+=this->size;
		this->soft_cur--;
	} while (this->soft_cur!=this->hard_cur);
	return false;
}

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

SingleBimodal::SingleBimodal(long max_table_size){
	this->correct=this->total=0;
	this->history=NULL;
	this->max_table_size=max_table_size;
}

double SingleBimodal::predict(ifstream * file){
	string str;
	while(getline(*file, str)){
		this->total++;
		unsigned long address = stol(str.substr(2,8), 0, 16);
		if(this->history==NULL)
			this->history=new List<bool>(address, true);
		if(!this->history->has(address))
			this->history->add(address);
		bool data = this->history->get(address);
		int i=0;
		while(str[i]!=' ')
			i++;
		bool taken = str[++i]=='T';
		if(taken==data)
			this->correct++;
		if(taken)
			this->history->set(address, true);
		else
			this->history->set(address, false);
	}
	return this->percent();
}

DoubleBimodal::DoubleBimodal(long max_table_size){
	this->correct=this->total=0;
	this->history=NULL;
	this->max_table_size=max_table_size;
}

double DoubleBimodal::predict(ifstream * file){
	string str;
	while(getline(*file, str)){
		this->predictOne(str);
	}
	return this->percent();
}

bool DoubleBimodal::predictOne(string str){
	this->total++;
	bool toReturn=false;
	unsigned long address = stol(str.substr(2,8), 0, 16);
	if(this->history==NULL)
		this->history=new List<int>(address, 3);
	if(!this->history->has(address))
		this->history->add(address);
	int num = this->history->get(address);
	bool data = num>1;
	int i=0;
	while(str[i]!=' ')
		i++;
	bool taken = str[++i]=='T';
	if(data==taken){
		this->correct++;
		toReturn=true;
	}
	if(taken && num<3)
		this->history->set(address, num+1);
	else if(!taken && num>0)
		this->history->set(address, num-1);
	return toReturn;
}

GShare::GShare(int global_history_bits){
	this->correct=this->total=0; 
	this->global_history_bits=global_history_bits; 
	this->history=NULL;
}

double GShare::predict(ifstream * file){
	string str;
	while(getline(*file, str)){
		this->predictOne(str);
	}
	return this->percent();
}

bool GShare::predictOne(string str){
	this->total++;
	bool toReturn = false;
	unsigned long address = stol(str.substr(2,8), 0, 16);
	address = address ^ this->global_history_bits;
	if(this->history==NULL)
		this->history=new List<int>(address, 3);
	if(!this->history->has(address))
		this->history->add(address);
	int num = this->history->get(address);
	bool data=num>1;
	int i=0;
	this->global_history_bits = this->global_history_bits << 1;
	while(str[i]!=' ')
		i++;
	bool taken=str[++i]=='T';
	if(taken==data){
		this->correct++;
		toReturn=true;
	}
	if(taken && num<3)
		this->history->set(address, num+1);
	else if(!taken && num>0)
		this->history->set(address, num-1);
	return toReturn;
}

Tournament::Tournament(){
	this->bimodal = new DoubleBimodal(2048);
	this->gshare = new GShare(11);
	this->history=NULL;
	this->correct=this->total=0;
}

double Tournament::predict(ifstream * file){
	string str;
	while(getline(*file, str)){
		this->total++;
		unsigned long address = stol(str.substr(2,8), 0, 16);
		if(this->history==NULL)
			this->history=new List<int>(address, 3);
		if(!this->history->has(address))
			this->history->add(address);
		int data = this->history->get(address);
		bool bimodal=this->bimodal->predictOne(str);
		bool gshare=this->gshare->predictOne(str);
		bool picked = true;
		bool not_picked = true;
		if(data>1){
			picked = gshare;
			not_picked = bimodal;
		}
		else{
			picked = bimodal;
			not_picked = gshare;
		}
		int i=0;
		while(str[i]!=' ')
			i++;
		bool taken=str[++i]=='T';
		if((taken && picked) || (!taken && !picked)){
			this->correct++;
			if(picked^not_picked){
				if(data<3 && data>1)
					this->history->set(address, data+1);
				else if(data>0 && data<2)
					this->history->set(address, data-1);
			}
		} else {
			if(picked^not_picked){
				if(data>1)
					this->history->set(address, data-1);
				else
					this->history->set(address, data+1);
			}
		}
		
	}
	return this->percent();
}