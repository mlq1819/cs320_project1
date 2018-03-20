#ifndef MQ_PREDICTORS_H
#define MQ_PREDICTORS_H
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

template <class T>
class Node{
	public:
		Node * parent;
		Node * next;
		unsigned long address; 
		T data;
		unsigned long id;
		Node(unsigned long, T);
		Node(unsigned long, T, Node *);
		~Node(){delete next; next=NULL;};
};

template <class T>
class List{
	private:
		Node<T> * root;
		T def;
		unsigned long address;
		unsigned long max_size;
		unsigned long current_size;
	public:
		List(unsigned long max_size, T def){this->max_size=max_size; this->def=def; this->current=this->root=NULL;};
		~List(){delete this->root; this->current=this->root=NULL;};
		bool add(unsigned long);
		bool has(unsigned long);
		T get(unsigned long);
		bool set(unsigned long, T);
		bool update(unsigned long);
		unsigned long getSize(){return this->current_size;};
};

class AlwaysTaken{
	private:
		long correct;
		long total;
	public:
		AlwaysTaken(){this->correct=this->total=0;};
		double percent(){return ((double) this->correct)/this->total * 100;};
		double predict(std::ifstream*);
		long getCorrect(){return this->correct;};
		long getTotal(){return this->total;};
};

class NeverTaken{
	private: 
		long correct;
		long total;
	public:
		NeverTaken(){this->correct=this->total=0;};
		double percent(){return ((double) this->correct)/this->total * 100;};
		double predict(std::ifstream*);
		long getCorrect(){return this->correct;};
		long getTotal(){return this->total;};
};

class SingleBimodal{
	private:
		List<bool>* history;
		long correct;
		long total;
	public:
		SingleBimodal(long);
		~SingleBimodal(){delete this->history; this->history=NULL;};
		double percent(){return ((double) this->correct)/this->total * 100;};
		double predict(std::ifstream*);
		long getCorrect(){return this->correct;};
		long getTotal(){return this->total;};
};

class DoubleBimodal{
	private:
		List<int>* history;
		long correct;
		long total;
	public:
		DoubleBimodal(long);
		~DoubleBimodal(){delete this->history; this->history=NULL;};
		double percent(){return ((double) this->correct)/this->total * 100;};
		double predict(std::ifstream*);
		bool predictOne(std::string);
		long getCorrect(){return this->correct;};
		long getTotal(){return this->total;};
};

class GShare{
	private:
		List<int>* history;
		long correct;
		long total;
		long max_table_size = 2048;
		int global_history_bits;
	public:
		GShare(int);
		~GShare(){delete this->history; this->history=NULL;};
		double percent(){return ((double) this->correct)/this->total * 100;};
		double predict(std::ifstream*);
		bool predictOne(std::string);
		long getCorrect(){return this->correct;};
		long getTotal(){return this->total;};
};

class Tournament{
	private:
		DoubleBimodal * bimodal;
		GShare * gshare;
		List<int>* history;
		long correct;
		long total;
	public:
		Tournament();
		~Tournament(){delete this->history; delete this->bimodal; delete this->gshare; this->history=NULL; this->bimodal=NULL; this->gshare=NULL;};
		double percent(){return ((double) this->correct)/this->total * 100;};
		double predict(std::ifstream*);
		long getCorrect(){return this->correct;};
		long getTotal(){return this->total;};
};

#endif