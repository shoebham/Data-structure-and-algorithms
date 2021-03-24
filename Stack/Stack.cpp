
#include<iostream>
using namespace std;


class stack
{
	public:
	int top,size,input;
	int arr[];	
	stack()
	{
		top = -1;
		cout <<"Please enter size of your stack."<<endl;
		cin>>size;
		arr[size];
	}
	
	void user_input()
	{
		
		
		do {	
		cout<<"Hello, What would you like to do?\n1.Push\n2.Pop\n3.Display Stack\n4.Exit."<<endl;
		cin>>input;
		
			switch(input)
			{
				case 1:
					push();
					break;
				case 2:
					pop();
					break;
				case 3:
					display();
					break;
				case 4:
					cout<<"Bye."<<endl;
					break;
				default:
					cout<<"Invalid choice"<<endl;
					break;
			}
			}while(input!=4);
	}
	
	void push()
	{
		if(top == size-1)
		{
			cout<<"Overflow, Stack is full!!"<<endl;
		}
		else {
			int num;
			cout<<"Enter number you want to insert"<<endl;
			cin>>num;
			top = top+1;
			arr[top] = num;
//			cout<<"Top is"<<top<<endl;
		}
	}
	
	void pop()
	{
		if(top==-1){
			cout <<"Underflow, Stack is empty!!"<<endl;
		}
		else 
		{
			int n = arr[top];
			top=top-1;
			cout<<n<<" removed."<<endl;
		}
	}
	void display()
	{
		if(top==-1){cout<<"Stack is empty!!"<<endl;
		}
		else{
			cout<<"Your stack looks like:"<<endl;
			cout <<"---"<<endl;
			for(int i=top;i>=0;i--){
				cout<<"|"<<arr[i]<<"|"<<endl;
				cout <<"---"<<endl;
			}
			
		}
	}
};

int main()
{
	stack s;
	s.user_input();
	return 0;
}
