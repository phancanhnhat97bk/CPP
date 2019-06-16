#pragma once
class MyVirus
{
private:
	char * m_dna;
	int m_resistance;

public:
	MyVirus();
	MyVirus(MyVirus * myVirus);
	~MyVirus();
	void SetDNA(char* dna);
	char* GetDNA();
	void SetRes(int resistance);
	int GetRes();
	void LoadADNInformation();
	virtual void DoBorn() = 0;
	virtual void DoClone() = 0;
	virtual void DoDie() = 0;
	virtual int InitResistance(int m_resistance) = 0;
	
};



