#include "DenGueVirus.h"
#include <iostream>


using namespace std;

DenGueVirus::DenGueVirus()
{
	this->DoBorn();
}

DenGueVirus::DenGueVirus(const DenGueVirus* denGueVirus) : MyVirus(denGueVirus) {
	this->m_protein[4] = denGueVirus->m_protein[4];
}

DenGueVirus::~DenGueVirus()
{
}
void DenGueVirus::DoBorn() {
	this->LoadADNInformation();
	int random = rand() % 3 + 1;
	if (random == 1) {
		this->m_protein[random] = 'NS3' ;
		cout << "NS3" << endl;
		this->SetResistance(InitResistance(1, 10));
		cout << this->GetResistance() << endl;
	}
	if (random == 2) {
		this->m_protein[random] = 'NS5' ;
		cout << "NS5" << endl;
		this->SetResistance(InitResistance(11, 20));
		cout << this->GetResistance() << endl;
	}
	if (random == 3) {
		this->m_protein[random] = 'E';
		cout << "E" << endl;
		this->SetResistance(InitResistance(21, 30));
		cout << this->GetResistance() << endl;
	}
	
}
void DenGueVirus::DoDie() {
	delete this;
}
list<MyVirus *> DenGueVirus::DoClone() {
	MyVirus * virus = new DenGueVirus(this);
	list<MyVirus *> CloneVirus;
	CloneVirus.push_back(virus);
	CloneVirus.push_back(virus);
	return CloneVirus;
}

int DenGueVirus::InitResistance(int blood_1, int blood_2) {
	return (rand() % (blood_2-blood_1+1) + blood_1);
}