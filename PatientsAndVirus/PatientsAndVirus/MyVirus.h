#pragma once
#include <list>

using namespace std;

class MyVirus
{
protected:
	char * m_dna;
	int m_resistance;

public:
	MyVirus();
	MyVirus(const MyVirus * myVirus);
	~MyVirus();
	void SetDNA(char* dna);
	char* GetDNA();
	void SetResistance(int resistance);
	int GetResistance();
	void LoadADNInformation();
	int ReduceResistance(int medicine_resistance);
	virtual void DoBorn() = 0;
	virtual list<MyVirus *> DoClone() = 0;
	virtual void DoDie() = 0;
	virtual int InitResistance(int blood_1,int blood_2) = 0;
	
};



