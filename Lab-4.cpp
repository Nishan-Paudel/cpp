#include <iostream>
#include <string.h>
using namespace std;

class string1 {
	char *name;
	int len;

public:
	string1(){
	    len = 0;
        name = new char [len+1];
	}
	string1(char s[]){
		len = strlen(s);
		name = new char [len + 1];
		strcpy(name, s);
	}
	friend string1 operator+(string1 , string1);
	friend ostream &operator<< (ostream &out, string1 s);
};

string1 operator+ (string1 s1, string1 s2){
	string1 c;
	c.len = s1.len + s2.len;
	delete c.name;
	c.name = new char[c.len + 1];
	strcpy(c.name, s1.name);
	strcat(c.name, s2.name);
	return c;
}

ostream &operator<< (ostream &out, string1 s){
	out<< s.name<<endl;
	return out;
}


int main(){
	string1 s1;
	string1 name1("Dr AIT"), name2("Bangalore");
	s1 =  name1 + name2;

	cout<<name1<<name2<<s1;
	return 0;
}



/*

==== OUTPUT ======

Dr AIT
Bangalore
Dr AITBangalore

*/
