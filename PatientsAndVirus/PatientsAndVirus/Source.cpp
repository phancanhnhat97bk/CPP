#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Patient.h"

using namespace std;

int main()
{
	Patient p;
	int t = 0;
	srand(time(NULL));
	while (p.GetState() == 1)
	{
		cout <<"Take Medicine 0 = NO, 1 = YES" << endl;
		cin >> t;
		if (t == 1)
		{
			int min = 1;
			int max = 5;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			
				p.TakeMedicine(medicine_resistance);
				cout << "Medicine Resistance : " << medicine_resistance << endl;
		}
	}
	system("pause");
}