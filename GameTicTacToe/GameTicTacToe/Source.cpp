#include <iostream>
#include <cstdio>
#include <iomanip>
#define MAX 3
using namespace std;
char user1[100];
char user2[100];
int Array[MAX][MAX];
void WelcomeGame();
void InputUser();
void Draw();
void Player();
bool CheckRow();
bool CheckCol();
bool CheckDiagonal();
bool CheckDiagonal2();
int main() {
	int select;
	WelcomeGame();
	cin >> select;
	if (select == 1) {
		InputUser();
		Draw();
		Player();
		cout << "\n-------------------END_GAME-----------------------";
	}
	system("pause");
	return 0;

}
bool CheckDiagonal() {
	if (Array[0][0] == 0) {
		return false;
	}
	if (Array[0][0] != 0) {
		int temp = Array[0][0];
		for (int i = 1;i<MAX;i++) {
			if (temp != Array[i][i]) return false;
		}
	}

	return true;

}
bool CheckDiagonal2() {
	int r = 0, c = MAX - 1;
	int temp2 = Array[r][c];
	if (Array[r][c] == 0) {
		return false;
	}
	if (Array[r][c] != 0) {
		while (r<MAX && c >= 0) {
			if (temp2 != Array[r][c])
				return false;
			else {
				r++;
				c--;
			}
		}
	}
	return true;
}
bool CheckCol() {
	int temp;
	for (int i = 0;i<3;i++) {
		temp = Array[i][i];
		if (temp == 0) continue;
		for (int j = 0;j<3;j++) {
			if (temp != Array[j][i]) break;
			if (j == 2) {
				return true;
			}
		}
	}
	return false;

}
bool CheckRow() {
	for (int i = 0;i<3;i++) {
		int temp = Array[i][i];
		if (temp == 0) continue;
		for (int j = 0;j<3;j++) {
			if (temp != Array[i][j]) break;
			if (j == 2) {
				return true;
			}
		}
	}
	return false;
}

void Player() {
	int count=0;
	while (1) {
		int pl1, pl2;
	input1: cout << " Your turn " << user1 << "\t-O\t:";
		cin >> pl1;
		if (Array[pl1 / 10][pl1 % 10] == 0) {
			Array[pl1 / 10][pl1 % 10] = 1;
			count++;
		}
		else {
			cout << "Wrong, please Enter again!\n";
			goto input1;
		}
		Draw();
		if (CheckCol() == true || CheckDiagonal() == true || CheckDiagonal2() == true || CheckRow() == true) {
			cout << "Your win... : " << user1;
			break;
		}
		if (count == (MAX*MAX)) {

			break;
		}
	input2: cout << " Your turn " << user2 << "\t-X\t:";
		cin >> pl2;
		if (Array[pl2 / 10][pl2 % 10] == 0) {
			Array[pl2 / 10][pl2 % 10] = 2;
			count++;
		}
		else {
			cout << "Wrong, please Enter again!\n";
			goto input2;
		}
		Draw();
		if (CheckCol() == true || CheckDiagonal() == true || CheckDiagonal2() == true || CheckRow() == true) {
			cout << "Your win... : " << user2;
			break;
		}
		if (count == (MAX*MAX)) {
			cout << "----------Draw---------";
			break;
		}
	}
}
void Draw() {
	for (int row = 0; row < MAX; row++) {
		for (int col = 0; col<MAX; col++)
		{
			cout << setw(4);
			if (Array[row][col] == 1) cout << "O";
			else if (Array[row][col] == 2) cout << "X";
			else cout << " ";
			cout << setw(5) << " | ";

		}
		cout << endl;
		cout << "---------------------------";
		cout << endl;

	}
}
void InputUser() {
	cout << "Enter play 1:\t";
	cin >> user1;
	fflush(stdin);
	cout << "Enter play 2:\t";
	cin >> user2;
	fflush(stdin);
}
void WelcomeGame() {
	cout << "Welcome To tic tac toe game! Play with your way! \n";
	cout << "If you find any problem, please contact phancanhnhat97bk@gmail.com \n";
	cout << "********************************************************************* \n";
	cout << "SELECT YOUR MORE (1 - PLAY GAME, OTHERS - EXIT GAME): \n ";
}