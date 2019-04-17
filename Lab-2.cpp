#include <iostream>
using namespace std;

class Student {
	static int count;
	int roll, t1, t2, t3;
	float average;
	char name[20];
public:
	void readData();
	void avgCalculate();
	void Display();
};

void Student::readData(){
	roll = ++count;
	cout<< "Enter name & 3 test marks\n";
	cin >> name >> t1 >> t2 >> t3;
}

void Student::avgCalculate(){
	if (t1<t2 && t1 < t3)
		average = (float(t2) + float(t3))/2;
	else if (t2 < t1 && t2 < t3)
		average = (float(t1) + float(t3))/2;
	else
		average = (float(t1) + float(t2))/2;
}

void Student::Display(){

	cout << "Name: "<< name<<endl;
	cout << "Roll no: "<<roll<<endl;
	cout << "Average mark: "<<average<<endl;

}

int Student::count;

int main(){
	Student users[10];
	int n;
	cout<<"Enter number of students\n";
	cin >> n;
	for (int i = 0; i<n; i++){
		users[i].readData();
		users[i].avgCalculate();
	}

	cout<<"Students details are: \n";
	for (int i = 0; i<n; i++)
		users[i].Display();
}


/*
======== OUTPUT ========

Enter number of students
4
Enter name & 3 test marks
Nishan
23 45 12
Enter name & 3 test marks
Ram
12 45 3
Enter name & 3 test marks
Pun
11 23 34
Enter name & 3 test marks
Pandey
22 33 45
Students details are:
Name: Nishan
Roll no: 1
Average mark: 34
Name: Ram
Roll no: 2
Average mark: 28.5
Name: Pun
Roll no: 3
Average mark: 28.5
Name: Pandey
Roll no: 4
Average mark: 39

*/
