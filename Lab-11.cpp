#include <iostream>
#include <list>
#include <vector>

using namespace std;
void display(vector <int>&v2){
	cout<<"The contents of v2 is"<<endl;
	for(int i=0; i<v2.size(); i++){
		cout<<v2[i]<<endl;
	}
}

void displaylist (list <int> &l){
	list<int> :: iterator p;
	cout<<"The contents of List are "<<endl;
	for (p=l.begin();p != l.end(); p++)
		cout<<*p<<endl;
}

int main(){
	vector<int> v1;
	int x, i;
	cout<<"Enter 5 unsorted elements on Vector 1"<<endl;
	for(i=0; i<5; i++){
		cin >> x;
		v1.push_back(x);
	}
	list<int> l;
	cout<<"Enter n sorted from Vector 1 to List"<<endl;
	copy(v1.begin(), v1.end(), back_inserter(l));
	l.sort();
	displaylist(l);
	vector <int> v2;
	copy(l.begin(), l.end(), back_inserter(v2));
	display(v2);
	return 0;
}



/*
========== OUTPUT ========

Enter 5 unsorted elements on Vector 1
89
45
-9
0
56
Enter n sorted from Vector 1 to List
The contents of List are
-9
0
45
56
89
The contents of v2 is
-9
0
45
56
89

*/
