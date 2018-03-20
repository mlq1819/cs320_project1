#include "Predictors.h"
#define OUTPUT true
#define FORCE true

using namespace std;

int main(int argc, char *argv[]){
	if(!FORCE){
		if((OUTPUT && argc<3) || argc<2){
			cout << "Not enough arguments" << endl;
			return 0;
		}
	}
	ifstream file;
	if(FORCE)
		file.open("short_trace1.txt");
	else
		file.open(argv[1]);
	if(!file || !file.good()){
		cout << "Bad input file" << endl;
		if(file.is_open())
			file.close();
		return 1;
	}
	
	ofstream output;
	if(OUTPUT){
		if(FORCE)
			output.open("st1_output.txt");
		else
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
	
	
	
	Tournament tournament = Tournament();
	cout << "Tournament: \t" << endl;
	cout << tournament.predict(&file) << "% Accurate" << endl;
	if(OUTPUT)
		output << tournament.getCorrect() << "," << tournament.getTotal() << "; ";
	file.clear();
	file.seekg(0, ios_base::beg);
	
	if(file.is_open())
		file.close();
	return 0;
}

template <class T>
Node<T>::Node(unsigned long address, T data){
	this->next=this->parent=NULL;
	this->address=address;
	this->data=data;
	this->id=0;
}

template <class T>
Node<T>::Node(unsigned long address, T data, Node * parent){
	this->parent=parent;
	this->address=address;
	this->data=data;
	this->id=0;
}

template <class T>
Node<T>::~Node(){
	delete this->next;
	if(this->parent!=NULL)
		this->parent->next=NULL;
	this->next=this->parent=NULL;
}

template <class T>
bool List<T>::add(unsigned long address){
	if(this->has(address))
		return false;
	Node<T> * temp=this->root;
	this->root=new Node<T>(address, this->def);
	this->root->next=temp;
	if(temp==NULL)
		return true;
	temp->parent=this->root;
	while(temp!=NULL){
		temp->id++;
		if(temp->id>=this->max_size){
			delete temp;
			temp=NULL;
		} else
			temp=temp->next;
	}
	return true;
}

template <class T>
bool List<T>::has(unsigned long address){
	Node<T> * current = this->root;
	while(current!=NULL){
		if(current->address==address){
			current=NULL;
			return true;
		}
		current=current->next;
	}
	return false;
}

template <class T>
T List<T>::get(unsigned long address){
	Node<T> * current = this->root;
	while(current!=NULL){
		if(current->address==address){
			T data = current->data;
			current=NULL;
			return data;
		}
		current=current->next;
	}
	return this->def;
}

template <class T>
bool List<T>::set(unsigned long address, T data){
	Node<T> * current = this->root;
	while(current!=NULL){
		if(current->address==address)
			break;
		current=current->next;
	}
	if(current==NULL)
		return false;
	current->data=data;
	return this->update(address);
	
}

template <class T>
bool List<T>::update(unsigned long address){
	Node<T> * current = this->root;
	while(current!=NULL){
		if(current->address==address)
			break;
		current->id++;
		current=current->next;
	}
	if(current==NULL){
		current=this->root;
		while(current!=NULL){
			current->id--;
			current=current->next;
		}
		return false;
	}
	if(current!=this->root){
		this->root->parent;
		current->id=0;
		current->parent->next=current->next;
		if(current->next!=NULL)
			current->next->parent=current->parent;
		current->parent=NULL;
		current->next=this->root;
		this->root->parent=current;
		this->root=current;
	}
	return true;
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
	this->history=new List<bool>(max_table_size, true);
}

double SingleBimodal::predict(ifstream * file){
	string str;
	while(getline(*file, str)){
		this->total++;
		unsigned long address = stol(str.substr(2,8), 0, 16);
		this->history->add(address);
		bool data = this->history->get(address);
		bool taken = str[11]=='T';
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
	this->history=new List<int>(max_table_size, 3);
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
	this->history->add(address);
	int num = this->history->get(address);
	bool data = num>1;
	bool taken = str[11]=='T';
	if(data==taken){
		this->correct++;
		toReturn=true;
	}
	if(taken && num<3)
		this->history->set(address, num+1);
	else if(!taken && num>0)
		this->history->set(address, num-1);
	else
		this->history->update(address);
	return toReturn;
}

GShare::GShare(int global_history_bits){
	this->correct=this->total=0; 
	this->global_history_bits=global_history_bits; 
	this->history=new List<int>(2048, 3);
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
	this->history->add(address);
	int num = this->history->get(address);
	bool data=num>1;
	this->global_history_bits = this->global_history_bits << 1;
	bool taken=str[11]=='T';
	if(taken==data){
		this->correct++;
		toReturn=true;
	}
	if(taken && num<3)
		this->history->set(address, num+1);
	else if(!taken && num>0)
		this->history->set(address, num-1);
	else
		this->history->update(address);
	return toReturn;
}

Tournament::Tournament(){
	this->bimodal = new DoubleBimodal(2048);
	this->gshare = new GShare(11);
	this->history=new List<int>(2048, 3);
	this->correct=this->total=0;
}

double Tournament::predict(ifstream * file){
	string str;
	while(getline(*file, str)){
		this->total++;
		unsigned long address = stol(str.substr(2,8), 0, 16);
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
		bool taken=str[11]=='T';
		if((taken && picked) || (!taken && !picked)){
			this->correct++;
			if(picked^not_picked){
				if(data<3 && data>1)
					this->history->set(address, data+1);
				else if(data>0 && data<2)
					this->history->set(address, data-1);
				else
					this->history->update(address);
			}
		} else {
			if(picked^not_picked){
				if(data>1)
					this->history->set(address, data-1);
				else
					this->history->set(address, data+1);
			} else
				this->history->update(address);
		}
		
	}
	return this->percent();
}