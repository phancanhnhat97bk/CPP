#include "Patient.h"
#include <iostream>

using namespace std;



Patient::Patient()
{
	this->m_resistance = InitResistance(1000, 9000);
	DoStart();
}


Patient::~Patient()
{
}



int Patient::InitResistance(int blood_1, int blood_2) {
	return rand() % (blood_2 - blood_1 + 1) + blood_1;
}

void Patient::DoStart() {
	this->m_state = 1;
	int rand_amount = rand() % (20 - 10 + 1) + 10;
	for (int i = 0;i < rand_amount;i++) {
		int rand_species = rand() % 2 + 1;
		if (rand_species == 1) {
			MyVirus * fluVirut = new FluViRus();
			this->m_virusList.push_back(fluVirut);
		}
		if (rand_species == 2) {
			MyVirus * denGueVirus = new DenGueVirus();
			this->m_virusList.push_back(denGueVirus);
		}
	}
}
void Patient::TakeMedicine(int  medicine_resistance) {
	cout << "Resistance Patient : " << this->m_resistance << endl;
	cout << "Total Resistance Virus : " << this->Total_Resistance_Virus() << endl;
	if (this->m_virusList.empty() == true) {
		cout << "Clear virus in patient!" << endl;
		this->m_state = 0;
	}
	else
	{
		if (this->Total_Resistance_Virus() < this->m_resistance) {
			for (list<MyVirus *>::iterator it = m_virusList.begin();it != m_virusList.end();) {
				if((*it)->ReduceResistance(medicine_resistance) > 0) {
					list<MyVirus *> list = (*it)->DoClone();
					m_virusList.insert(m_virusList.begin(), list.begin(), list.end());
					it++;
				}
				else
				{
					it = m_virusList.erase(it);
			
				}
			}
		}
		else {
			this->DoDie();
			cout << "Patient die!" << endl;
		}
	}
}
int Patient::Total_Resistance_Virus() {
	int total = 0;
	for (list<MyVirus *> ::iterator it = m_virusList.begin();it != m_virusList.end();it++) {
		total += (*it)->GetResistance();
	}
	return total;
}
void Patient :: DoDie() {
	this->m_resistance = 0;
	this->m_state = 0;
	this->m_virusList.clear();
}

int Patient::GetState() {
	return m_state;
}