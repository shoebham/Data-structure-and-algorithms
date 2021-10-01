#include<iostream>
#include<vector>
using namespace std;

class stack
{
	public:
	int top,size,input;
	vector<int> arr;	
	stack()
	{
		top = -1;
	}
		
	void push(int n)
	{
		if(top == size-1)
		{
		}
		else {

			top = top+1;
			arr[top] = n;
//			cout<<"Top is"<<top<<endl;
		}
	}
	
	int pop()
	{
		if(top==-1){
		}
		else 
		{
			int n = arr[top];
			top=top-1;
			return n;
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
	bool empty()
	{
		if(top==-1)
		return true;
		else
		return false;
	}
};
class queue
{
	public:
	int front,rear,size,n;
	vector<int> arr;
	queue()
	{
//			cout<<"Please Enter size of queue"<<endl;
//			cin>>size;
//			arr[size];	
			
			front = 0;
			rear = -1;
			
	}
	
		
		void enqueue(int n)
		{
			if(rear == size-1)
			{
			}	
			else{
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
		
		int dequeue()
		{
			if (front>rear)
			{
//				front=0;rear=0;
			}
			else{
				int n = arr[front];
//				cout<<"----------"<<endl;
//				cout<<n<<" removed."<<endl;
//				cout<<"----------"<<endl;
				
//				if(front==rear){
//					front=-1;
//					rear=-1;
//				}
//				else
//				{
				front++;
//				}	
				return n;
			}
		}
		
		void display()
		{
			if(front>rear)
			{
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

class graph
{
	public:
		vector<vector<int>> adj;
		vector<bool> visited={false};
		vector<int> res,neighbor;
		int nodes,connected,choice;
	graph()
	{
//		menu();
		input_arr();
		input_nodes();
		
		display();
		cout<<"Enter your choice \n1.Breadth First Search\n2.Depth First Search\n";
		cin>>choice;
		if(choice==1)
		bfs();
		else if(choice==2)
		dfs();
		display_res();
	}
	
	void input_arr()
	{
		cout<<"Enter number of nodes"<<endl;
		cin>>nodes;
		
	}
	
	void input_nodes()
	{
		cout<<"enter 1 if nodes are connected else 0 (anything other than 0 or 1 will be considered as 0)\n";
		for(int i=1;i<=nodes;i++)
		{
			adj.resize(nodes);
			visited.resize(nodes);
			for(int j=1;j<=nodes;j++)
			{
				adj[j-1].resize(nodes,-1);
//				visited[j-1].resize(nodes);
				
				if(i==j)
				continue;
				
				else if(adj[i-1][j-1]==1)
				continue;
				else if(adj[i-1][j-1]==0)
				continue;
				cout<<i<<"->"<<j<<endl;	
				cin>>connected;
				if(connected==1)
				adjMatrix(i-1,j-1,1);
				else
				adjMatrix(i-1,j-1,0);
			}
			
		}
	}
	void adjMatrix(int i,int j,int connected)
	{
		adj[i][j]=connected;
		adj[j][i]=connected;
	}
	
	void display()
	{
		cout<<"-----------------\n";
		cout<<"  ";
		for(int i=1;i<=nodes;i++)
		cout<<i<<" ";
		cout<<endl;
		cout<<"-----------------\n";
		for(int i=0;i<nodes;i++)
		{
			cout<<i+1<<"|";
			for(int j=0;j<nodes;j++)
			{
//				cout<<adj[i][j]<<" ";
				if(adj[i][j]==true)
				cout<<1<<" ";
				else
				cout<<0<<" ";
			}
			cout<<endl;
		}
		}
	
	
	void bfs()
	{
		
		queue q;
		q.arr.resize(nodes);
		q.enqueue(1);
		visited[0]=true;
		res.push_back(1);
		while(!(q.front>q.rear))
		{
			
			
			int n=q.dequeue();
//			cout<<"n is "<<n<<endl;
			for(int i=0;i<nodes;i++)
			{	
//			cout<<"------in for loop------\n";
				if(adj[n-1][i]==1&&visited[i]==false)
				{
					visited[i]=true;
					q.enqueue(i+1);	
					res.push_back(i+1);
				}
//				neighbor.push_back(i+1);
//				cout<<"----------------\n";
//				q.display();
//				cout<<endl;
//				cout<<"-------visited matrix---------\n";
//				print_visited();
//				cout<<"-----------------\n";
			}
		}	
	}
			
		
	void dfs()
	{
		res.clear();
		stack stk;
		stk.size=nodes;
		stk.arr.resize(nodes);
		stk.push(1);
		while(!stk.empty())
		{
			int n=stk.pop();
			visited[n-1]=true;
			res.push_back(n);
			for(int i=0;i<nodes;i++)
			{
			
				if(adj[n-1][i]==1&&visited[i]==false)
				{
					stk.push(i+1);
					visited[i]=true;
				}
			}
//			stk.display();
		}
		
	}
	void print_visited()
	{
		cout<<"-----------------\n";
		cout<<"  ";
		for(int i=1;i<=nodes;i++)
		cout<<i<<" ";
		cout<<endl;
		cout<<"-----------------\n";
		for(int i=0;i<nodes;i++)
		{
			cout<<i+1<<"|";
//			for(int j=0;j<nodes;j++)
//			{
//				cout<<adj[i][j]<<" ";
				if(visited[i]==true)
				cout<<1<<" ";
				else
				cout<<0<<" ";
//			}
			cout<<endl;
		}
	}

	void display_res()
	{
		cout<<"\nResult:-\n";
		for(auto x:res)
		cout<<x<<" ";
	}
};



int main()
{
	graph g;
	
	return 0;	
}
