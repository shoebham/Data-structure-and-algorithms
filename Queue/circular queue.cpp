#include<iostream>
using namespace std;

class queue
{
	public:
	int front,rear,size,n;
	int arr[];
	queue()
	{
		cout<<"Please Enter size of queue"<<endl;
		cin>>size;
		arr[size];
		front = -1;
		rear = -1;
	}
	void menu()
	{
		int input;
		do{
		cout<<"Enter your choice\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit."<<endl;
		cin>>input;
		
		switch(input){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				cout<<"Bye.";
				break;
			}
		}while(input!=4);
	}
	
	void enqueue()
	{
		if((rear+1)%size==front)
		{
			cout<<"-------------------"<<endl;
			cout<<"queue is full!!!!!!"<<endl;
			cout<<"-------------------"<<endl;
		}	
		
		else
		{	
			cout<<"Enter number "<<endl;
			cin>>n;
			if(front==-1&&rear==-1)
			{
			front=0;
			rear=0;
			}	
			else{
				rear = (rear+1)%size;
			}
			arr[rear] = n;
		}
	}
	
	void dequeue()
	{
		if (front==-1&&rear==-1)
		{
			cout<<"--------------------"<<endl;
			cout<<"queue is empty!!!!!!"<<endl;
			cout<<"--------------------"<<endl;
		}
		else
		{
			n = arr[front];
			if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else{
			
				front  = (front+1)%size;
			}
		cout<<"----------"<<endl;
		cout<<n<<" removed."<<endl;
		cout<<"----------"<<endl;
	}	
	}
	
	void display()
	{
		int i;
		if(front==-1)
		{
			cout<<"--------------------"<<endl;
			cout<<"queue is empty!!!!!!"<<endl;
			cout<<"--------------------"<<endl;
		}
		else
		{
		for(i=front;i!=rear;i=(i+1)%size)
		{
			 cout<<"|"<<arr[i]<<"|";
		}
		cout<<"|"<<arr[i]<<"|";
		cout<<endl;
	}
	}
};


int main()
{
	queue q;
	q.menu();
	return 0;
}
