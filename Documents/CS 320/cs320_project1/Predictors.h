#ifndef MQ_PREDICTORS_H
#define MQ_PREDICTORS_H
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

template <class T>
class Node{
	private:
		Node * left;
		Node * right;
		unsigned long address;
		T def;
		T data;
	public:
		Node(unsigned long, T, T);
		Node(unsigned long, T);
		~Node(){delete left; delete right; left=right=NULL;};
		bool add(unsigned long);
		bool add(unsigned long, T);
		bool add(unsigned long, T, T);
		bool has(unsigned long);
		T get(unsigned long);
		bool set(unsigned long, T);
};

class AlwaysTaken{
	private:
		long correct;
		long total;
	public:
		AlwaysTaken(){this->correct=this->total=0;};
		double percent(){return ((double) this->correct)/this->total;};
		double predict(std::ifstream*);
};

class NeverTaken{
	private: 
		long correct;
		long total;
	public:
		NeverTaken(){this->correct=this->total=0;};
		double percent(){return ((double) this->correct)/this->total;};
		double predict(std::ifstream*);
};

class SingleBimodal{
	private:
		Node<bool>* history;
		long correct;
		long total;
	public:
		SingleBimodal(){this->correct=this->total=0;this->history=NULL;};
		double percent(){return ((double) this->correct)/this->total;};
		double predict(std::ifstream*);
};

class DoubleBimodal{
	private:
		Node<int>* history;
		long correct;
		long total;
	public:
		DoubleBimodal(){this->correct=this->total=0;this->history=NULL;};
		double percent(){return ((double) this->correct)/this->total;};
		double predict(std::ifstream*);
};

#endif