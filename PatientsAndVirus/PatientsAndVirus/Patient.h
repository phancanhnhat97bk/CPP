#pragma once
#include "MyVirus.h"
#include "FluViRus.h"
#include "DenGueVirus.h"
#include<list>

using namespace std;

class Patient
{
private:
	int m_resistance;
	list<MyVirus *> m_virusList;
	int m_state;
public:
	Patient();
	~Patient();
	int InitResistance(int blood_1, int blood_2);
	void DoStart();
	void TakeMedicine();
	int ReduceResistance();
	
};

