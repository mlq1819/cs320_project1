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
		Node * next;
		unsigned long id;
		unsigned long address;
		T def;
		T data;
		void init(unsigned long, T, T, unsigned long);
		Node(unsigned long, T, T, unsigned long);
	public:
		Node(unsigned long, T, T);
		Node(unsigned long, T);
		~Node(){delete left; delete right; left=right=NULL;};
		Node * replaceRoot();
		bool add(unsigned long);
		bool add(unsigned long, T);
		bool add(unsigned long, T, T);
		bool has(unsigned long);
		T get(unsigned long);
		bool set(unsigned long, T);
		unsigned long getID(){return this->id;};
};

class AlwaysTaken{
	private:
		long correct;
		long total;
	public:
		AlwaysTaken(){this->correct=this->total=0;};
		double percent(){return ((double) this->correct)/this->total * 100;};
		double predict(std::ifstream*);
};

class NeverTaken{
	private: 
		long correct;
		long total;
	public:
		NeverTaken(){this->correct=this->total=0;};
		double percent(){return ((double) this->correct)/this->total * 100;};
		double predict(std::ifstream*);
};

class SingleBimodal{
	private:
		Node<bool>* history;
		long correct;
		long total;
		long max_table_size;
	public:
		SingleBimodal(long);
		~SingleBimodal(){delete this->history; this->history=NULL;};
		double percent(){return ((double) this->correct)/this->total * 100;};
		double predict(std::ifstream*);
};

class DoubleBimodal{
	private:
		Node<int>* history;
		long correct;
		long total;
		long max_table_size;
	public:
		DoubleBimodal(long);
		~DoubleBimodal(){delete this->history; this->history=NULL;};
		double percent(){return ((double) this->correct)/this->total * 100;};
		double predict(std::ifstream*);
};

#endif