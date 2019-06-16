#include "FluViRus.h"
#include <cstdlib>



FluViRus::FluViRus() : MyVirus()
{
	this->m_color = 0;
}

FluViRus::FluViRus(FluViRus *fluVirus) : MyVirus(fluVirus)
{
	this->m_color = fluVirus->m_color;
}
void FluViRus::DoBorn(){
	LoadADNInformation();
	int r = rand() % 2 + 1;
	if (r == 1) {
		this->m_color = 0x0000ff;
	}
	if (r == 2) {
		this->m_color = 0xff0000;
	}
}
int FluViRus::InitResistance(int m_resistance) {
	if (m_color == 0x0000ff) {
		m_resistance = rand() % 15 + 10;
	}
	if (m_color == 0xff0000) {
		m_resistance = rand() % 20 + 10;
	}
	return m_resistance;
}
FluViRus::~FluViRus()
{
}
