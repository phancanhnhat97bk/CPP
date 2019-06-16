#pragma once
#include "MyVirus.h"
class FluViRus : public MyVirus
{
private:
	int m_color;

public:
	FluViRus();
	FluViRus(const FluViRus * fluVirus);
	~FluViRus();

	void DoBorn() override;
	void DoDie() override;
	list<MyVirus *> DoClone() override;
	int InitResistance(int blood_1, int blood_2) override;
};

