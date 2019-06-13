#include "MyPonit.h"
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

MyPonit::MyPonit()
{
	this->mPosX = 0;
	this->mPosY = 0;
}

MyPonit::MyPonit(int x, int y) {
	this->mPosX = x;
	this->mPosY = y;
}

MyPonit::~MyPonit()
{
}

void MyPonit::Display() {
	cout << "coordinates x y :   " << endl;
	cout << this->mPosX << setw(10) << this->mPosY << endl;
}
void MyPonit::SetX(int x) {
	this->mPosX = x;
 }
int MyPonit::GetX() {
	return this->mPosX;
}
void MyPonit::SetY(int y) {
	this->mPosY = y;
 }
int MyPonit::GetY() {
	return this->mPosY;
}
float MyPonit::Distance(MyPonit p) {
	float a = this->mPosX - p.mPosX;
	float b = this->mPosY - p.mPosY;
	return sqrt(a*a + b*b);
}
