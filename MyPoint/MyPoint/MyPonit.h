#pragma once
class MyPonit
{
private:
	int mPosX;
	int mPosY;
public:
	MyPonit();
	MyPonit(int, int);
	~MyPonit();

	void Display();
	void SetX(int);
	int GetX();
	void SetY(int);
	int GetY();
	float Distance(MyPonit p);
};

