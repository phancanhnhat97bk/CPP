#include "MyPonit.h"
#include <iostream>

using namespace std;

int main() {
	int x, y;
	MyPonit *p = new MyPonit();
	p->Display();
	cout << "Enter the first point: " << endl;
	cout << "Enter x:  ";
	cin >> x;
	cout << "Enter y:  ";
	cin >> y;
	p->SetX(x);
	p->SetY(y);
	p->Display();

	cout << "Enter the second point: " << endl;
	cout << "Enter x:  ";
	cin >> x;
	cout << "Enter y:  ";
	cin >> y;
	MyPonit *p2 = new MyPonit(x,y);
	cout <<"distance between two point:  " << p->Distance(*p2) << endl;
	system("pause");
}