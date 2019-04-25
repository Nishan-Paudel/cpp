#include <iostream>
#include <iomanip>

using namespace std;

class Shape{
protected:
	int x,y;
public:
	virtual void read() =0;
	virtual void compute()= 0;
	virtual void display() =0;
};

class rectangle: public Shape{
	float area1;
public:
	void read(){
		cout<<"Enter x and y\n";
		cin>>x>>y;
	}
	void compute(){ area1 = x*y;}
	void display(){ cout<<"Area rectangle: "<<area1;}
};

class circle: public Shape{
	float area1;
public:
	void read(){
		cout<<"Enter radius\n";
		cin>>x;
	}
	void compute(){ area1 = 3.142*x*x;}
	void display(){ cout<<"Area of circle: "<<area1<<endl; }


};

class square : public Shape{
	float area;
public:
	void read(){
		cout<<"Enter the side"<<endl;
		cin>>x;
	}
	void compute(){ area = x*x;}
	void display(){
		cout<<"Area square: "<<area<<endl;
	}
};

int main(){
	Shape  *s[4];
	circle c;
	square sq;
	rectangle r;
	s[0] = NULL;
	s[1] = &c;
	s[2] = &r;
	s[3] = &sq;
	int ch;
	while (1){
		cout<<"\n1:Area of circle  2:Area of rectangle  3:Area of square\n";
		cin>>ch;
		s[ch]->read();
		s[ch]->compute();
		s[ch]->display();
	}
}


/*
======== OUTPUT ========


1:Area of circle  2:Area of rectangle  3:Area of square
1
Enter radius
12
Area of circle: 452.448

1:Area of circle  2:Area of rectangle  3:Area of square
2
Enter x and y
12 11
Area rectangle: 132
1:Area of circle  2:Area of rectangle  3:Area of square
3
Enter the side
5
Area square: 25

*/
