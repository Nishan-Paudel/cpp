#include <iostream>
#include <string.h>
using namespace std;

typedef struct node{
	char data[20];
	struct node *left, *right;
} *Node;



class Customer{
	int count;
	Node first;
public:
	Customer(){first = NULL; count = 1;}
	void create();
	void del(int pos);
	void display();
};

void Customer :: create(){
	char item[20];
	cout<<"Enter the data"<<endl;
	cin>>item;
	Node temp;
	temp = new(struct node);
	temp->right = temp->left = NULL;
	strcpy(temp->data, item);

	if (first == NULL){
		first = temp;
	}
	else {
		temp->right = first;
		first->left = temp;
		first = temp;

	}
}

void Customer :: del (int pos){
	Node cur, prev, temp;
	if (first == NULL){
		cout<<"No element to delete\n";
		return;
	}

	if (pos == 1){
		cout<<"Deleted element: "<<first->data<<endl;
		cur= first;
		first = first->right;
		delete cur;
		return;
	}


	prev = NULL;
	cur = first;
	while(cur != NULL && count != pos){
		prev = cur;
		cur = cur->right;
		count++;
	}

	if (cur->right == NULL){
		cout<<cur->data<<endl;
		prev->right = NULL;
		delete cur;
		count=1;
		return;
	}


	count  = 1;
	temp = cur->right;
	prev->right = temp;
	temp->left = prev;
	cout<<"Deleted element: "<< cur->data <<endl;
	delete cur;
}


void Customer :: display(){
	Node temp;
	if (first == NULL){
		cout<<"List is empty"<<endl;
	}
	temp = first;
	while(temp != NULL){
		cout<<"->"<<temp->data;
		temp = temp->right;
	}
}

int main(){
	int pos, choice;
	char item[10];
	Customer d;
	while(1){
		cout<<endl<<"1.Insert 2:Delete 3.Print 4:Exit"<<endl;
		cin>>choice;

		switch(choice){
			case 1: d.create(); break;
			case 2: cout<<"Enter the position"<<endl;
				cin>>pos; d.del(pos); break;
			case 3: cout<<"Contents of the list are :"<<endl;
				d.display();
				break;
			default: return 0;
		}

	}
}



/*
======== OUTPUT ========


1.Insert 2:Delete 3.Print 4:Exit
1
Enter the data
aakash

1.Insert 2:Delete 3.Print 4:Exit
1
Enter the data
bir

1.Insert 2:Delete 3.Print 4:Exit
1
Enter the data
cing

1.Insert 2:Delete 3.Print 4:Exit
1
Enter the data
dash

1.Insert 2:Delete 3.Print 4:Exit
3
Contents of the list are :
->dash->cing->bir->aakash
1.Insert 2:Delete 3.Print 4:Exit
2
Enter the position
2
Deleted element: cing

1.Insert 2:Delete 3.Print 4:Exit
3
Contents of the list are :
->dash->bir->aakash
1.Insert 2:Delete 3.Print 4:Exit
2
Enter the position
1
Deleted element: dash

1.Insert 2:Delete 3.Print 4:Exit
3
Contents of the list are :
->bir->aakash
1.Insert 2:Delete 3.Print 4:Exit
2
Enter the position
1
Deleted element: bir

1.Insert 2:Delete 3.Print 4:Exit
3
Contents of the list are :
->aakash
1.Insert 2:Delete 3.Print 4:Exit
1
Enter the data
noone

1.Insert 2:Delete 3.Print 4:Exit
2
Enter the position
1
Deleted element: noone

1.Insert 2:Delete 3.Print 4:Exit
2
Enter the position
1
Deleted element: aakash

1.Insert 2:Delete 3.Print 4:Exit
3
Contents of the list are :
List is empty

1.Insert 2:Delete 3.Print 4:Exit

2
Enter the position
1
No element to delete

1.Insert 2:Delete 3.Print 4:Exit
4

*/













