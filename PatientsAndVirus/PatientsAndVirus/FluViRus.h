#pragma once
#include "MyVirus.h"
class FluViRus : public MyVirus
{
private:
	int m_color;

public:
	FluViRus();
	FluViRus(FluViRus * fluVirus);
	~FluViRus();

	void DoBorn() override;
	/*void DoClone();
	void DoDie();*/
	int InitResistance(int m_resistance) override;
};

