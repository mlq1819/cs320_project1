#ifndef MQ_PREDICTORS_H
#define MQ_PREDICTORS_H
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

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
		std::vector<bool> history;
		long correct;
		long total;
	public:
		SingleBimodal(){this->correct=this->total=0;};
		double percent(){return ((double) this->correct)/this->total;};
		double predict(std::ifstream*);
};

class DoubleBimodal{
	private:
		std::vector<int> history;
		long correct;
		long total;
	public:
		DoubleBimodal(){this->correct=this->total=0;};
		double percent(){return ((double) this->correct)/this->total;};
		double predict(std::ifstream*);
};

#endif