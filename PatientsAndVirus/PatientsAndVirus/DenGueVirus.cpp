#include "DenGueVirus.h"
#include <iostream>

using namespace std;

DenGueVirus::DenGueVirus()
{
	this->DoBorn();
}

DenGueVirus::DenGueVirus(const DenGueVirus* denGueVirus) : MyVirus(denGueVirus) {
	strcpy(this->protein, denGueVirus->protein);
}

DenGueVirus::~DenGueVirus()
{
}
void DenGueVirus::DoBorn() {
	LoadADNInformation();
	int random = rand() % 3 + 1;
	if (random == 1) {
		this->protein = "NS3";
		cout << this->protein;
		this->SetResistance(InitResistance(1, 10));
	}
	if (random == 2) {
		this->protein = "NS5";
		cout << this->protein;
		this->SetResistance(InitResistance(11, 20));
	}
	if (random == 3) {
		this->protein = "E";
		cout << this->protein;
		this->SetResistance(InitResistance(21, 30));
	}
	
}
void DenGueVirus::DoDie() {
	delete this;
}
list<MyVirus *> DenGueVirus::DoClone() {
	MyVirus * virus = new DenGueVirus();
	list<MyVirus *> CloneVirus;
	CloneVirus.push_back(virus);
	return CloneVirus;
}

int DenGueVirus::InitResistance(int blood_1, int blood_2) {
	return rand() % blood_2 + blood_1;
}