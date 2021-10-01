#include<iostream>
using namespace std;

class queue
{
	int front,rear,size,n;
	int arr[];
	public:
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
			cout<<"Enter your choice\n1.insert from front \n2.insert from rear \n3.delete from front \n4.delete from rear \n5.display \n6.exit"<<endl;
			cin>>input;
			
			switch(input){
				case 1:
					insertFront();
					break;
				case 2:
					insertRear();
					break;
				case 3:
					deleteFront();
					break;
				case 4:
					deleteRear();
					break;
				case 5:
					display();
					break;
				case 6:
					cout<<"Bye"<<endl;
					break;
				}
			}while(input!=6);
		}
	

		void insertFront()
		{
			if((front==0&&rear==size-1)||(front==rear+1))
			{
				cout<<"-------------------"<<endl;
				cout<<"queue is full!!!!!!"<<endl;
				cout<<"-------------------"<<endl;
			}
			else 
			{
				cout<<"Enter number"<<endl;
				cin>>n;
				
				if(front==-1&&rear==-1)
				{		
					front=0;
					rear=0;
				}
				else if(front==0)
				{
				front=size-1;
				}	 
				else 
				{
					front--;
				}
				arr[front] = n;
			}
		}
		
		void insertRear()
		{
			if((front==0&&rear==size-1)||(front==rear+1))
			{
				cout<<"-------------------"<<endl;
				cout<<"queue is full!!!!!!"<<endl;
				cout<<"-------------------"<<endl;
			}	
			else
			{	cout<<"Enter number"<<endl;
				cin>>n;
				if(rear==size-1)
				{
					rear=0;
				}
				else if(front==-1&&rear==-1)
				{
					front=0;
					rear=0;
				}
				else
				{
					rear++;
				}
				arr[rear] = n;
			}
		}
		
		void deleteFront()
		{
			if(front==-1&&rear==-1)
			{
				cout<<"--------------------"<<endl;
				cout<<"queue is empty!!!!!!"<<endl;
				cout<<"--------------------"<<endl;
				cout<<"rear is "<<rear<<" front is "<<front<<endl;
			}
			else 
			{
				if(front==rear)
				{
				n=arr[front];
				front=-1;
				rear=-1;
				}
				else if(front==size-1)
				{
					n=arr[front];
					front=0;
				}
				else{
					n=arr[front];
					front++;
				}
				cout<<"----------"<<endl;
				cout<<n<<" removed."<<endl;
				cout<<"----------"<<endl;
//				cout<<"rear after removing "<<rear<<" front after removing "<<front<<endl;
			}
		}
		void deleteRear()
		{
			if (front==-1&&rear==-1)
			{
				cout<<"--------------------"<<endl;
				cout<<"queue is empty!!!!!!"<<endl;
				cout<<"--------------------"<<endl;
//				front=0;rear=0;
			}
			else{
				if(front==rear){				
					n = arr[rear];
					front=-1;
					rear=-1;				
				}
				else if(rear==0)
				{
					n = arr[rear];
					rear=size-1;
				}
				else
				{
				n = arr[rear];
				rear--;
				}	
				cout<<"----------"<<endl;
				cout<<n<<" removed."<<endl;
				cout<<"----------"<<endl;
//				cout<<"rear after removing "<<rear<<" front after removing "<<front<<endl;
			}
		}
		void display()
		{
			if(front==-1&&rear==-1)
			{
				cout<<"--------------------"<<endl;
				cout<<"queue is empty!!!!!!"<<endl;
				cout<<"--------------------"<<endl;
			}
			else
			{
//				cout<<"front is "<<front<<" rear is "<<rear<<endl;
				cout<<"arr[front] = "<<arr[front]<<" arr[rear] = "<<arr[rear]<<endl;
				int i;
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
