#include <iostream>
using namespace std;

class electricityBill{
	char name[20];
	int units;
	float price, surcharge;
public:
    void input();
    void calculate();
    void display();
};

void electricityBill:: input(){
    cout << "\nEnter the username\n";
    cin >> name;
    cout<<"Enter the units consumed\n";
    cin >> units;
}

void electricityBill:: calculate(){
    if (units <= 100)
        price = (units * 1.5) + 50;
    else if (units<=200)
        price = 50+(100*1.5) + (units-100) * 1.8;
    else
        price = 50 + 100 * 1.5 + 100 * 1.8 + (units -200) * 2.5;
    if (price > 300)
        price *= 1.15;
}

void electricityBill:: display(){

    cout<<name<<"       "<<units<<"   "<<price<<endl;
}


int main(){
	electricityBill userList[10];
	int n,i;



	cout << "\nEnter the numbers of users\n";
	cin >> n;
	for (i=0 ; i<n; i++){
        userList[i].input();
        userList[i].calculate();

	}
	cout<<"Name"<<"      " <<"Units"<<"  "<<"price"<<endl;
	for(i=0;i<n;i++)
        userList[i].display();
}



/*
========== OUTPUT ========

Enter the numbers of users
3

Enter the username
Ram
Enter the units consumed
101

Enter the username
Pun
Enter the units consumed
55

Enter the username
Nat
Enter the units consumed
89
Name      Units  price
Ram       101   201.8
Pun       55   132.5
Nat       89   183.5

*/
