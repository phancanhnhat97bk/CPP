#pragma once
#include "MyVirus.h"
#include <string>
class DenGueVirus : public MyVirus
{

private:
	char * protein;
public:
	DenGueVirus();
	DenGueVirus(const DenGueVirus *denGueVirus);
	~DenGueVirus();

	void DoBorn() override;
	void DoDie() override;
	list<MyVirus *> DoClone() override;
	int InitResistance(int blood_1,int blood_2) override;
};

