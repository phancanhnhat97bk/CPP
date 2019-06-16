#include "FluViRus.h"
#include <cstdlib>
#include <iostream>



FluViRus::FluViRus() : MyVirus()
{
	this->DoBorn();
}

FluViRus::FluViRus(const FluViRus *fluVirus) : MyVirus(fluVirus)
{
	this->m_color = fluVirus->m_color;
}

FluViRus::~FluViRus()
{
}

void FluViRus::DoBorn(){
	LoadADNInformation();
	this->m_color = rand() % 2 + 1;
	if (this->m_color == 1) {
		std :: cout << "Red virus !";
		this->SetResistance(InitResistance(10,20));
	}
	if (this->m_color == 2) {
		std::cout << "Blue virus !";
		this->SetResistance(InitResistance(10,15));

	}
}

void FluViRus::DoDie() {
	delete this;
}

list<MyVirus *> FluViRus:: DoClone() {
	MyVirus *virus = new FluViRus();
	list<MyVirus *> CloneVirus;
	CloneVirus.push_back(virus);
	return CloneVirus;

}

int FluViRus::InitResistance(int blood_1,int blood_2) {
	
	return rand() % blood_2 + blood_1;
}

