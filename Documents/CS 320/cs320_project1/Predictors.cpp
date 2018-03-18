#include "Predictors.h"
#define MAX_SIZE 32
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
	if(OUTPUT){
		alwaysTaken.predict(&file);
		output << alwaysTaken.getCorrect() << "," << alwaysTaken.getTotal() << ";" << endl;
	} else
		cout << "Always Taken: \t\t" << alwaysTaken.predict(&file) << "% Accurate" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	
	
	NeverTaken neverTaken = NeverTaken();
	if(OUTPUT){
		neverTaken.predict(&file);
		output << neverTaken.getCorrect() << "," << neverTaken.getTotal() << ";" << endl;
	} else
		cout << "Never Taken: \t\t" << neverTaken.predict(&file) << "% Accurate" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	
	
	SingleBimodal singleBimodal = SingleBimodal(16);
	if(OUTPUT){
		singleBimodal.predict(&file);
		output << singleBimodal.getCorrect() << "," << singleBimodal.getTotal() << "; ";
	} else
		cout << "Single Bimodal 16: \t" << singleBimodal.predict(&file) << "% Accurate" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	singleBimodal = SingleBimodal(32);
	if(OUTPUT){
		singleBimodal.predict(&file);
		output << singleBimodal.getCorrect() << "," << singleBimodal.getTotal() << "; ";
	} else
		cout << "Single Bimodal 32: \t" << singleBimodal.predict(&file) << "% Accurate" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	singleBimodal = SingleBimodal(128);
	if(OUTPUT){
		singleBimodal.predict(&file);
		output << singleBimodal.getCorrect() << "," << singleBimodal.getTotal() << "; ";
	} else
		cout << "Single Bimodal 128: \t" << singleBimodal.predict(&file) << "% Accurate" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	singleBimodal = SingleBimodal(256);
	if(OUTPUT){
		singleBimodal.predict(&file);
		output << singleBimodal.getCorrect() << "," << singleBimodal.getTotal() << "; ";
	} else
		cout << "Single Bimodal 256: \t" << singleBimodal.predict(&file) << "% Accurate" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	singleBimodal = SingleBimodal(512);
	if(OUTPUT){
		singleBimodal.predict(&file);
		output << singleBimodal.getCorrect() << "," << singleBimodal.getTotal() << "; ";
	} else
		cout << "Single Bimodal 512: \t" << singleBimodal.predict(&file) << "% Accurate" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	singleBimodal = SingleBimodal(1024);
	if(OUTPUT){
		singleBimodal.predict(&file);
		output << singleBimodal.getCorrect() << "," << singleBimodal.getTotal() << "; ";
	} else
		cout << "Single Bimodal 1024: \t" << singleBimodal.predict(&file) << "% Accurate" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	singleBimodal = SingleBimodal(2048);
	if(OUTPUT){
		singleBimodal.predict(&file);
		output << singleBimodal.getCorrect() << "," << singleBimodal.getTotal() << ";" << endl;
	} else
		cout << "Single Bimodal 2048: \t" << singleBimodal.predict(&file) << "% Accurate" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	
	
	DoubleBimodal doubleBimodal = DoubleBimodal(16);
	if(OUTPUT){
		doubleBimodal.predict(&file);
		output << doubleBimodal.getCorrect() << "," << doubleBimodal.getTotal() << "; ";
	} else
		cout << "Double Bimodal 16: \t" << doubleBimodal.predict(&file) << "% Accurate" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	doubleBimodal = DoubleBimodal(32);
	if(OUTPUT){
		doubleBimodal.predict(&file);
		output << doubleBimodal.getCorrect() << "," << doubleBimodal.getTotal() << "; ";
	} else
		cout << "Double Bimodal 32: \t" << doubleBimodal.predict(&file) << "% Accurate" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	doubleBimodal = DoubleBimodal(128);
	if(OUTPUT){
		doubleBimodal.predict(&file);
		output << doubleBimodal.getCorrect() << "," << doubleBimodal.getTotal() << "; ";
	} else
		cout << "Double Bimodal 128: \t" << doubleBimodal.predict(&file) << "% Accurate" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	doubleBimodal = DoubleBimodal(256);
	if(OUTPUT){
		doubleBimodal.predict(&file);
		output << doubleBimodal.getCorrect() << "," << doubleBimodal.getTotal() << "; ";
	} else
		cout << "Double Bimodal 256: \t" << doubleBimodal.predict(&file) << "% Accurate" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	doubleBimodal = DoubleBimodal(512);
	if(OUTPUT){
		doubleBimodal.predict(&file);
		output << doubleBimodal.getCorrect() << "," << doubleBimodal.getTotal() << "; ";
	} else
		cout << "Double Bimodal 512: \t" << doubleBimodal.predict(&file) << "% Accurate" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	doubleBimodal = DoubleBimodal(1024);
	if(OUTPUT){
		doubleBimodal.predict(&file);
		output << doubleBimodal.getCorrect() << "," << doubleBimodal.getTotal() << "; ";
	} else
		cout << "Double Bimodal 1024: \t" << doubleBimodal.predict(&file) << "% Accurate" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	doubleBimodal = DoubleBimodal(2048);
	if(OUTPUT){
		doubleBimodal.predict(&file);
		output << doubleBimodal.getCorrect() << "," << doubleBimodal.getTotal() << ";" << endl;
	} else
		cout << "Double Bimodal 2048: \t" << doubleBimodal.predict(&file) << "% Accurate" << endl;
	file.clear();
	file.seekg(0, ios_base::beg);
	
	if(file.is_open())
		file.close();
	return 0;
}

template <class T>
void Node<T>::init(unsigned long address, T data, T def, long id){
	this->id=id;
	this->address = address;
	this->data = data;
	this->def = def;
	this->next=NULL;
}

template <class T>
Node<T>::Node(unsigned long address, T data, T def, long id){
	init(address, data, def, id);
}

template <class T>
Node<T>::Node(unsigned long address, T data, T def){
	init(address, data, def, 0);
	
}

template <class T>
Node<T>::Node(unsigned long address, T data){
	init(address, data, data, 0);
}

template <class T>
Node<T> * Node<T>::replaceRoot(){
	Node * newRoot = this->next;
	this->next=NULL;
	delete this;
	return newRoot;
}

template <class T>
bool Node<T>::add(unsigned long address){
	return this->add(address, this->def, this->def);
}

template <class T>
bool Node<T>::add(unsigned long address, T data){
	return this->add(address, data, this->def);
}

template <class T>
bool Node<T>::add(unsigned long address, T data, T def){
	this->id++;
	if(this->next!=NULL)
		return this->next->add(address, data, def);
	this->next=new Node(address, data, def, this->id-1);
	return true;
}

template <class T>
bool Node<T>::has(unsigned long address){
	if(this->address==address)
		return true;
	if(this->next!=NULL)
		return this->next->has(address);
	return false;
}

template <class T>
T Node<T>::get(unsigned long address){
	if(this->address==address)
		return this->data;
	if(this->next!=NULL)
		return this->next->get(address);
	return this->def;
}

template <class T>
bool Node<T>::set(unsigned long address, T data){
	if(this->address==address){
		this->data=data;
		return true;
	}
	if(this->next!=NULL)
		return this->next->set(address, data);
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
			this->history=new Node<bool>(address, false);
		if(!this->history->has(address)){
			this->history->add(address);
			if(this->history->getID()>=this->max_table_size)
				this->history=this->history->replaceRoot();
		}
		bool data = this->history->get(address);
		if(str[11]=='T' && data)
			this->correct++;
		else if(str[11]=='N' && !data)
			this->correct++;
		else
			this->history->set(address, !data);
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
		this->total++;
		unsigned long address = stol(str.substr(2,8), 0, 16);
		if(this->history==NULL)
			this->history=new Node<int>(address, 0);
		if(!this->history->has(address)){
			this->history->add(address);
			if(this->history->getID()>=this->max_table_size)
				this->history=this->history->replaceRoot();
		}
		int data = this->history->get(address);
		if(str[11]=='T'){
			if(data>1)
				this->correct++;
			if(data<3)
				this->history->set(address, data+1);
		}
		else if(str[11]=='N'){
			if(data>1)
				this->correct++;
			if(data>0)
				this->history->set(address, data-1);
		}
	}
	return this->percent();
}