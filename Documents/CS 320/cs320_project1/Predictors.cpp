#include "Predictors.h"
#define MAX_SIZE 32

using namespace std;

template <class T>
void Node<T>::init(unsigned long address, T data, T def, unsigned long id){
	this->id=id;
	this->address = address;
	this->data = data;
	this->def = def;
	this->next=NULL;
}

template <class T>
Node<T>::Node(unsigned long address, T data, T def, unsigned long id){
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
Node * Node<T>::replaceRoot(){
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