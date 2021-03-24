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
			int input,choice;
			cout<<"Select which type of priority queue you want. \n1.Ascending order priority queue \n2.Descending order priority queue "<<endl;
			cin>>choice;
			do{
			
			cout<<"Enter your choice\n1.Enqueue \n2.Dequeue \n3.Display \n4.Bye"<<endl;
			cin>>input;
			switch(input){
				case 1:
					enqueue();
					if(choice == 1){sort_asc();
					}
					else if (choice==2){sort_desc();
					}
					break;
				case 2:
					dequeue();
					break;
				case 3:
					display();
					break;
//				case 4:
//					sort_asc();
//					break;
//				case 5:
//					sort_desc();
//					break;
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
				 if(front==-1&&rear==-1){
					front=0;
					rear=0;
//					cout<<"before i am here"<<endl;
				}
				else{
//					cout<<"i am here"<<endl;
					rear++;
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
				front=0;rear=0;
			}
			else{
				int n = arr[front];
				cout<<"----------"<<endl;
				cout<<n<<" removed."<<endl;
				cout<<"----------"<<endl;
				
				if(front==rear){
					front=-1;
					rear=-1;
				}
				else
				{
				front++;
				}	
				
			}
		}
		
		void display()
		{
			if(front==-1&&rear==-1)
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
			cout<<"front is "<<front<<" rear is "<<rear;
			cout<<endl;
			}
		}
		
		void sort_asc()
		{
//			cout<<"front is "<<front<<" rear is "<<rear<<endl;
			for(int i=front;i<=rear;i++)
			{
				for(int j=front;j<=rear-1;j++)
				{
					if(arr[j+1]<arr[j])
					{
						int temp=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temp;
					}		
				}
			}
//			display();	
		}
		void sort_desc()
		{
//			cout<<"front is "<<front<<" rear is "<<rear<<endl;
			for(int i=front;i<=rear;i++)
			{
				for(int j=front;j<=rear-1;j++)
				{
					if(arr[i]>arr[j])
					{
						int temp=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temp;
					}		
				}
			}
//			display();	
		}
	};
	
	
	int main()
	{
		queue q;
		q.menu();
		return 0;
	}
