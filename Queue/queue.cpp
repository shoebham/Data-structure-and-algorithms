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
			front = 0;
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
			if(rear == size-1)
			{
				cout<<"-------------------"<<endl;
				cout<<"queue is full!!!!!!"<<endl;
				cout<<"-------------------"<<endl;
			}	
			else{
				cout<<"Enter number "<<endl;
				cin>>n;
//				 if(front==-1&&rear==-1){
//					front=0;
//					rear=0;
////					cout<<"i am here in if of else"<<endl;
//				}
//				else{
//					cout<<"i am here"<<endl;
					rear++;
//					}
				arr[rear] = n;
			}
		}
		
		void dequeue()
		{
			if (front>rear)
			{
				cout<<"--------------------"<<endl;
				cout<<"queue is empty!!!!!!"<<endl;
				cout<<"--------------------"<<endl;
//				front=0;rear=0;
			}
			else{
				int n = arr[front];
				cout<<"----------"<<endl;
				cout<<n<<" removed."<<endl;
				cout<<"----------"<<endl;
				
//				if(front==rear){
//					front=-1;
//					rear=-1;
//				}
//				else
//				{
				front++;
//				}	
				
			}
		}
		
		void display()
		{
			if(front>rear)
			{
				cout<<"-------------------"<<endl;
				cout<<"queue is empty!!!!!!"<<endl;
				cout<<"-------------------"<<endl;
			}
			else
			{
				for(int i=front;i<=rear;i++)
			{
				 cout<<"|"<<arr[i]<<"|";
			}
		
			}
		}
};
	int main()
	{
		queue q;
		q.menu();
		return 0;
	}
