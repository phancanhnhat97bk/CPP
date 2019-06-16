#include "MyVirus.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

MyVirus::MyVirus()
{
	this->m_dna = "";
	this->m_resistance = 0;
}
MyVirus::MyVirus(MyVirus*p) {
	this->m_dna = p->m_dna;
	this->m_resistance = p->m_resistance;
 }

MyVirus::~MyVirus()
{
}

void MyVirus::SetDNA(char* dna) {
	this->m_dna = dna;
}

char* MyVirus::GetDNA() {
	return this-> m_dna;
}

void MyVirus::SetRes(int resistance) {
	this->m_resistance = resistance;
}
int MyVirus::GetRes() {
	return this->m_resistance;
}

void MyVirus :: LoadADNInformation()  {
	ifstream fileinput;
	fileinput.open("ATGX.bin");
	if (fileinput.is_open()) {
		char a[100];
		fileinput >> a;
		m_dna = (char *)a;
		cout << m_dna << endl;
	}
	else
	{
		cout << "read file error!";
	}
}