#include<iostream>
using namespace std;
	
class queue
{
//	public:
	int front,rear,size,n,p,max=0;
	int arr[100];
	int prior[100];
	public:
	queue()
	{
			cout<<"Please Enter size of queue"<<endl;
			cin>>size;
//			arr[size]; 
//			prior[size];
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
					sort_desc();
					break;
				case 2:
					dequeue();
//					sort_desc();
					break;
				case 3:
					display();
					break;
				case 4:
					cout<<"Bye.";
					exit(0);
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
				cout<<"Enter priority where 1 is the lowest priority"<<endl;
				cin>>p;
//				if(p>max){max=p;}
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
				prior[rear] = p;
//				cout<<"n is "<<n<<" rear is "<<rear<<endl;			
//				cout<<"p is "<<p<<" rear is "<<rear<<endl;
//				cout<<"arr[rear] is "<<arr[rear];
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
//				int n = arr[max];
				cout<<"----------"<<endl;
				cout<<n<<" removed."<<endl;
				cout<<"----------"<<endl;
				front++;
//				if(front==rear){
//					front=-1;
//					rear=-1;
//				}
//				else
//				{
//				}	
				
			}
		}
		void sort_desc()
		{
//			cout<<"front is "<<front<<" rear is "<<rear<<endl;
			for(int i=front;i<=rear;i++)
			{
				for(int j=front;j<=rear-1;j++)
				{
					if(prior[i]<prior[j])
					{
						int temp=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temp;
						
						 temp=prior[j];
						prior[j]=prior[j+1];
						prior[j+1]=temp;
						
					}		
				}
			}
//			display();	
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
//				cout<<"-----arr[i]------"<<endl;
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
