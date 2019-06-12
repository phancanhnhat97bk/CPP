#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#define MAX 100
int count = 0;
using namespace std;

struct Student
{
	string name;
	int id;
	float score;
	
};
void PrintMenu();
void Input(Student *students, int n,int &count);
int CheckId(int i, Student *students);
float CheckScore();
void Display(Student * students, int count);
void SaveToFile(string FileName, Student *students, int count);
void LoadFromFile(string FileName);
void Replace(string &str, char to, char by);
int Process();



int main() {
	
	Process();
	
	system("pause");
}


int Process() {
	Student * students = new Student[MAX];
	int count = 0;
	while (1) {
		PrintMenu();
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1: 
			int n;
			cout << "Nhap so sinh vien :   ";
			cin >> n;
			Input(students, n,count);
			break;
		case 2:
			Display(students,count);
			break;
		case 3: 
			SaveToFile("save.dat",students,count);
			break;
		case 4:
			LoadFromFile("save.dat");
			break;
		case 0: 
			return 0;
		default:
			break;
		}
	}
}

void Replace(string &str, char to, char by)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == to)
		{
			str.at(i) = by;
		}
	}
}

void LoadFromFile(string FileName) {
	ifstream inFile;
	inFile.open(FileName);
	if (inFile.is_open()) {
		int num;
		inFile >> num;
		cout << endl << left << setw(10) << "ID";
		cout << left << setw(30) << "Name";
		cout << left << setw(10) << "Score" << endl;
		for (int i = 0;i < num;i++) {
			Student students;
			inFile >> students.id;
			inFile >> students.name;
			inFile >> students.score;
			Replace(students.name, '_', ' ');
			cout << left << setw(10) << students.id;
			cout << left << setw(30) << students.name;
			cout << left << setw(10) << students.score << endl;
		}
		inFile.close();
	}
	else
	{
		cout << "LOAD ERROR" << endl;
	}
}

void SaveToFile(string FileName, Student *students , int count) {
	ofstream outFile;
	outFile.open(FileName);
	if (outFile.is_open()) {
		outFile << count << endl;
		for (int i = 0;i < count;i++) {
			string name(students[i].name);
			Replace(name, ' ', '_');
			outFile << students[i].id << " " << name << " " << students[i].score << endl;
		}
		cout << "Save to " << FileName << endl;
		outFile.close();
	}
	else {
		cout << "ERROR" << endl;
	}
}

void Display(Student * students, int count) {
	cout << endl << left << setw(10) << "ID";
	cout << left << setw(30) << "Name";
	cout << left << setw(10) << "Score" << endl;
	for (int i = 0; i < count; i++) {
		cout << left << setw(10) << students[i].id;
		cout << left << setw(30) << students[i].name;
		cout << left << setw(10) << students[i].score << endl;
	}
}

int CheckId(int i,Student *students) {
	
	int id;
	bool check = true;
	while (check) {
		cout << "Id :   ";
		cin >> id;
		check = false;
		for (int k = 0; k < i;k++) {
			if (id == students[k].id) {
				check = true;
			}
		}
	}
	return id;
}
float CheckScore() {
	float score;
	while (1) {
		cout << "Score :   ";
		cin >> score;
		if (score <= 10.0 && score >= 0.0) {
			return score;
		}
	}
}
void Input(Student *students, int n,int &count) {
	for (int i = count;i < (n+count);i++) {
		students[i].id = CheckId(i,students);
		cout << "Name :   ";
		cin.ignore();
		getline(cin, students[i].name);
		students[i].score = CheckScore();
	}
	count += n;
}
void PrintMenu() {
	cout << "---------------MENU---------------" << endl;
	cout << "1. Input" << endl;
	cout << "2. Display" << endl;
	cout << "3. Save to file" << endl;
	cout << "4. Load from file" << endl;
	cout << "0. Exit" << endl;
	cout << "----------------------------------" << endl;

}