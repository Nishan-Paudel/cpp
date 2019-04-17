#include <iostream>
using namespace std;

template <class X>
class queue {
	X a[20];
	int f, r, qs;
public:
	queue (int n) { r =-1; f =0; qs=n;}
	void insertRear();
	void deleteFront();
	void display();
};

template <class X>
void queue <X> :: insertRear(){
	if (r == qs- 1){
		cout<<"Queue is full\n";
		return;
	}
	X item;
	cout<<"Enter the item to insert\n";
	cin >> item;
	a[++r] = item;

}

template <class X>
void queue <X> :: deleteFront(){
	if (f>r){
		cout<<"Queue is empty\n";
		return;
	}
	X item;
	cout <<"Item deleted is "<<a[f++]<<endl;


}

template <class X>
void queue <X> :: display(){
	if (f>r){
		cout<<"Queue is empty\n";
		return;
	}
	for(int i = f; i<=r;i++)
		cout<<a[i]<<" ";

}


template <class T>
void interface (T obj, int n){
	int choice;
	for (;;){
		cout<<"\n1:InsertRear 2:DeleteFront 3:Display 4:Exit\n";
		cin >> choice;

		switch(choice){
			case 1: obj.insertRear(); break;
			case 2: obj.deleteFront(); break;
			case 3: obj.display(); break;
			default: return;
		}

	}
}

int main(){
	int n, choice;
	cout<<"Enter 1 for integer and 2 for double\n";
	cin >> choice;
	cout<< "Enter the size of the queue\n";
	cin>> n;

	queue <int> intObj(n);
	queue <double> doubleObj(n);

	if (choice == 1)
		interface(intObj, n);
	else
		interface(doubleObj, n);

	return 0;
}

/*
======== OUTPUT ========


Enter 1 for integer and 2 for double
1
Enter the size of the queue
3

1:InsertRear 2:DeleteFront 3:Display 4:Exit
1
Enter the item to insert
23

1:InsertRear 2:DeleteFront 3:Display 4:Exit
2
Item deleted is 23

1:InsertRear 2:DeleteFront 3:Display 4:Exit
2
Queue is empty

1:InsertRear 2:DeleteFront 3:Display 4:Exit
1
Enter the item to insert
34

1:InsertRear 2:DeleteFront 3:Display 4:Exit
1
Enter the item to insert
454

1:InsertRear 2:DeleteFront 3:Display 4:Exit
1
Queue is full

1:InsertRear 2:DeleteFront 3:Display 4:Exit
4


======== OUTPUT ========

Enter 1 for integer and 2 for double
2
Enter the size of the queue
4

1:InsertRear 2:DeleteFront 3:Display 4:Exit
1
Enter the item to insert
45.69

1:InsertRear 2:DeleteFront 3:Display 4:Exit
1
Enter the item to insert
445.96

1:InsertRear 2:DeleteFront 3:Display 4:Exit
1
Enter the item to insert
88.9

1:InsertRear 2:DeleteFront 3:Display 4:Exit
3
45.69 445.96 88.9
1:InsertRear 2:DeleteFront 3:Display 4:Exit
2
Item deleted is 45.69

1:InsertRear 2:DeleteFront 3:Display 4:Exit
2
Item deleted is 445.96

1:InsertRear 2:DeleteFront 3:Display 4:Exit
2
Item deleted is 88.9

1:InsertRear 2:DeleteFront 3:Display 4:Exit
2
Queue is empty

1:InsertRear 2:DeleteFront 3:Display 4:Exit
4


*/
