#include <iostream>
using namespace std;

class Complex {
	int rp, ip;
public:
	Complex add(Complex x);
	Complex add(int );
	void read();
	void display();

};

Complex Complex :: add(Complex x){
	Complex c;
	c.rp = rp + x.rp;
	c.ip = ip + x.ip;
	return c;

}

Complex Complex :: add(int a){
	Complex c;
	c.rp = rp + a;
	c.ip = ip;
	return c;

}

void Complex::read(){
    cout << "Enter the real and imaginary part\n";
    cin>>rp>>ip;
}

void Complex::display(){
    cout<<rp<<"+j"<<ip<<endl;
}

int main(){
	Complex s1,s2,s3;
	int a;
	cout<<"Enter s1:"<<endl;
	s1.read();
	cout<<"Enter a: ";
	cin>>a;
	s2 = s1.add(a);
	s3 = s1.add(s2);

	cout<<"s1 is: ";
	s1.display();
	cout<<"s2 is: ";
	s2.display();
	cout<<"s3 is: ";
	s3.display();

}



/*
==== OUTPUT ====

Enter s1:
Enter the real and imaginary part
2 3
Enter a: 10
s1 is: 2+j3
s2 is: 12+j3
s3 is: 14+j6

*/
