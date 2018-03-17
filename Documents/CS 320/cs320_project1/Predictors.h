#ifndef MQ_PREDICTORS_H
#define MQ_PREDICTORS_H
#include <stdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

class Predictors{
	public:
		virtual double percent()=0;
		virtual double predict(ifstream)=0;
};

class AlwaysTaken : public Predictors{
	private:
		long correct;
		long total;
	public:
		AlwaysTaken(){this->correct=this->total=0;};
};

class NeverTaken : public Predictors{
	private:
		long correct;
		long total;
	public:
		NeverTaken(){this->correct=this->total=0;};
};

class singleBimodal : public Predictors{
	private:
		std::vector<bool> history;
		long correct;
		long total;
	public:
		singleBimodal(){this->correct=this->total=0;};
}

class doubleBimodal : public Predictors{
	private:
		std::vector<int> history;
		long correct;
		long total;
	public:
		doubleBimodal(){this->correct=this->total=0;};
}