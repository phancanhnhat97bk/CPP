#include "Patient.h"



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
void Patient::TakeMedicine() {
	int medicine_resistance = ReduceResistance();

}

int Patient::ReduceResistance() {
	return rand() % 60 + 1;
}