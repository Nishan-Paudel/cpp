#include <iostream>
#include <string.h>
using namespace std;

class date{
	int d,m,y;
public:
	int getdate();
	int leap(int);
	int days(int);
	int operator-(date);
	date operator+(int);
	friend ostream &operator<< (ostream &, date);

};

int date:: getdate(){
	cout<<"Enter the date as day month year\n";
	cin >> d >> m >>  y;
	return 0;
}

int date :: days(int i){
	if (i==2)
		return 28;
	if (i == 1 || i == 3 || i == 5 ||  i == 7|| i == 9|| i == 10|| i == 12 )
		return 31;
	return 30;
	}


int date :: leap(int y){
	if (y % 4 == 0)
		return 1;
	else return 0;
}

ostream& operator<< (ostream &out, date d){
	cout << d.d << "/" << d.m << "/" << d.y;
	return out;

}

int date :: operator- (date d2){
	int ly, count =0;
	while(m != d2.m || y != d2.y){
		d2.d ++;
		count ++;
		ly =0;
		if (d2.m == 2)
			ly = d2.leap(d2.y);
		if (d2.d > (days(d2.m)+ ly)){
			d2.d = 1;
			d2.m++;
		}
		if( d2.m > 12){
			d2.m = 1;
			d2.y++;
		}
	}
	count += (d-d2.d);
	return count;
}

date date :: operator+ (int ndays){
	int i, ly=0;
	for(i=1; i<=ndays; i++){
		d++;
		ly =0;
		if(m == 2)
			ly = leap(y);
		if (d>(days(m) + ly)){
			m++; d = 1;

		}
		if (m > 12){
			m = 1; y++;

		}
	}
	return *this;
}


int main(){
	date d1,d2;
	int choice, a, no_days;
	for(;;){
		cout<<"1.Subtract 2. Add no of days: ";
		cin >> choice;
		switch(choice){
			case 1: cout<<"Enter the date 1 greater than date 2\n";
				d1.getdate();
				d2.getdate();
				no_days = d1 -d2;
				cout<<no_days<<endl;
				break;
			case 2: cout<<"Enter the numbers of date to be added to date 1\n";
				cin>>a;
				d1.getdate();
				d2= d1 + a;
				cout << d2<<endl;
				break;
			default: return 0;
		}
	}
}



/*
======== OUTPUT ========

1.Subtract 2. Add no of days: 1
Enter the date 1 greater than date 2
Enter the date as day month year
1  1 2001
Enter the date as day month year
1 1 2000
366
1.Subtract 2. Add no of days: 2
Enter the numbers of date to be added to date 1
30
Enter the date as day month year
10 2 2004
11/3/2004
1.Subtract 2. Add no of days:


===== OUTPUT ======

1.Subtract 2. Add no of days: 1
Enter the date 1 greater than date 2
Enter the date as day month year
23 3 2017
Enter the date as day month year
1 3 2009
2944
1.Subtract 2. Add no of days: 2
Enter the numbers of date to be added to date 1
346
Enter the date as day month year
1 12 1876
12/11/1877
1.Subtract 2. Add no of days:

*/















