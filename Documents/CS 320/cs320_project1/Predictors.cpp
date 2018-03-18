#include "Predictors.h"
#define MAX_SIZE 32

using namespace std;

Node<T>::Node(unsigned long address, T data){
	this->address = address;
	this->data = data;
}

bool Node<T>::add(unsigned long address, T data){
	if(address<this->address){
		if(this->left==NULL)
			this->left = new Node(address, data);
		else
			return this->left->add(address, data);
	} else if(address>this->address){
		if(this->right==NULL)
			this->right = new Node(address, data);
		else
			return this->right->add(address, data);
	}
	return false;
}

bool Node<T>::has(unsigned long address){
	if(this->address==address)
		return true;
	if(address<this->address && this-left!=NULL)
		return this->left->has(address);
	if(address>this->address && this->right!=NULL)
		return this->right->has(address);
	return false;
}

T Node<T>::get(unsigned long address){
	if(this->address=address)
		return this->data;
	if(address<this->address && this-left!=NULL)
		return this->left->get(address);
	if(address>this->address && this->right!=NULL)
		return this->right->get(address);
	return T;
}

bool Node<T>::set(unsigned long address, T data){
	if(this->address=address){
		this->data=data;
		return true;
	}
	if(address<this->address && this-left!=NULL)
		return this->left->set(address, data);
	if(address>this->address && this->right!=NULL)
		return this->right->set(address, data);
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

double SingleBimodal::predict(ifstream * file){
	string str;
	while(getline(*file, str)){
		this->total++;
		unsigned long address = stoi(str.substr(2,8), 0, 16);
		if(this->history==NULL)
			this->history=new Node<bool>(address, false);
		if(!this->history->has(address))
			this->history->add(address, false);
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

double DoubleBimodal::predict(ifstream * file){
	string str;
	while(getline(*file, str)){
		this->total++;
		unsigned long address = stoi(str.substr(2,8), 0, 16);
		if(this->history==NULL)
			this->history=new Node<int>(address, 0);
		if(!this->history->has(address))
			this->history->add(address, 0);
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