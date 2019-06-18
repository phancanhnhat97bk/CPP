#include "Patient.h"
#include <iostream>
#include <ctime>
#include <Windows.h>


using namespace std;



Patient::Patient()
{
	this->m_resistance = InitResistance(1000, 4000);
	DoStart();
}


Patient::~Patient()
{

}



int Patient::InitResistance(int blood_1, int blood_2) {
	srand(time(0));
	return rand() % (blood_2 - blood_1 + 1) + blood_1;
}

void Patient::DoStart() {
	this->m_state = 1;
	srand(time(0));
	int rand_amount = rand() % (20 - 10 + 1) + 10;
	for (int i = 0;i < rand_amount;i++) {
		Sleep(500);
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
	cout << "Total virus : " << this->m_virusList.size() << endl;
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
					MyVirus *p = *it;
					it = m_virusList.erase(it);
					if (p != nullptr) {
						delete p;
						p = nullptr;
					}
				}
			}
		}
		else {
			
			cout << "Patient die!" << endl;
			for (list<MyVirus *>::iterator it = m_virusList.begin();it != m_virusList.end();it++) {
				delete *it;
			}
			this->DoDie();
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
