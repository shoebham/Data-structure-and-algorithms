#include<iostream>
#include<vector>
using namespace std;
class queue
{
	public:
	int front,rear,size,n;
	vector<int> arr,prior;
	queue()
	{

			
			front = 0;
			rear = -1;
			size=1000;
	}
	
		
		void enqueue(int n,int dist)
		{
			if(rear == arr.size())
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
				prior[rear]= dist;
			}
			
			sort_asc();
		}
		
		
		int dequeue()
		{
//			if (front>rear)
//			{
//				front=0;rear=0;
//			}
//			else{
				int n = arr[front];
//				cout<<"----------"<<endl;
//				cout<<n<<" removed."<<endl;
//				cout<<"----------"<<endl;
				
				if(front==rear){
					front=0;
					rear=-1;
				}
				else
				{
				front++;
				}	
				return n;
//			}
		}
		
		bool present(int n)
		{
			for(int i=0;i<arr.size();i++)
			{
				if(arr[i]==n)
				return true;
			}
			return false;
		}
		bool empty()
		{
			if(front==0&&rear==-1)
			{
				return true;
			}
			return false;
		}
		void display()
		{
			if(front==-1&&rear==-1)
			{
				cout<<"Queue empty\n";
			}
			else
			{

			for(int i=front;i<=rear;i++)
			{
				cout<<"front= "<<front<<" rear = "<<rear<<endl;
				 cout<<"|"<<char(arr[i]+65)<<"|";
			}
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
		}
};
class dijkstra
{
	public:
		vector<vector<int>> adjMatrix;
		vector<bool> visited={false};
		vector<vector<int>> distMatrix;
		vector<int> res,prev={0},tempDist;
		int nodes,connected,choice,dist;
		queue q;
		
	dijkstra()
	{
//		menu();
		input_arr();
		input_nodes();
		display();
		dij();
	}
	
	void input_arr()
	{
		cout<<"Enter number of nodes"<<endl;
		cin>>nodes;
	}
	
	void input_nodes()
	{
		cout<<"enter if nodes are connected or not with Distance seperated by space\n1-Connected\n0-Not Connected\n";
		for(int i=1;i<=nodes;i++)
		{
			adjMatrix.resize(nodes);
			distMatrix.resize(nodes);
			visited.resize(nodes);
			for(int j=1;j<=nodes;j++)
			{
				adjMatrix[j-1].resize(nodes,-1);
				distMatrix[j-1].resize(nodes,-1);
//				visited[j-1].resize(nodes);
				
				if(i==j)
				continue;
				
				else if(adjMatrix[i-1][j-1]==1)
				continue;
				else if(adjMatrix[i-1][j-1]==0)
				continue;
				cout<<(char)(i+64)<<"->"<<(char)(j+64)<<endl;	
				cin>>connected;
				if(connected==1)
				{
					cin>>dist;
					input_adjMatrix(i-1,j-1,1);
					input_distMatrix(i-1,j-1,dist);
				}
				else
				input_adjMatrix(i-1,j-1,0);
			}
			
		}
	}
	
	void input_distMatrix(int i,int j,int dist)
	{
		distMatrix[i][j]=dist;
		distMatrix[j][i]=dist;
	}
	void input_adjMatrix(int i,int j,int connected)
	{
		adjMatrix[i][j]=connected;
		adjMatrix[j][i]=connected;
	}
	
	void dij()
	{
		q.arr.resize(nodes);
		q.prior.resize(nodes);
		prev.resize(nodes);
		tempDist.resize(nodes,INT_MAX);
		q.enqueue(0,0);
		tempDist[0]=0;
		while(!(q.empty()))
		{

			int u = q.dequeue();
			visited[u]=true;
//			cout<<"u is "<<u<<endl;
			
			for(int i=0;i<nodes;i++)
			{
				if(adjMatrix[u][i]==1&&visited[i]==false)
				{
//					cout<<"----------------\n";
//					cout<<"i is "<<i<<endl;
//					cout<<"current node is "<<(char)(u+65)<<endl;
//					cout<<"neigbor node is "<<(char)(i+65)<<endl;
					int currDist = tempDist[u]+distMatrix[u][i];
					
//					cout<<"tempDist "<<tempDist[i]<<endl;
					if(currDist<tempDist[i])
					{
//						cout<<"here\n";
//						cout<<"curr "<<currDist<<endl;
						tempDist[i]=currDist;
						prev[i]=u;
						if(!q.present(i))
						q.enqueue(i,currDist);
//						q.display();
					}	
				}
			}
		}
		cout<<"--------------\n";
		display_res();
//		for(int i=0;i<prev.size();i++)
//		{
//			cout<<"prev "<<prev[i];
//			cout<<"Temp dist"<<tempDist[i]<<" \n";
//		}
	}
//	
	void display_res()
	{
		cout<<"Shortest distance: "<<tempDist.back()<<endl;
		cout<<"Shortest Path: \n";
		for(int i=1;i<nodes;i++)
			{
				cout<<char(prev[i]+65)<<"->";
			}
			cout<<char(nodes+64)<<endl;
	}
	void display()
	{
		
		cout<<"-------Adjacency Matrix----------\n";
		cout<<"-----------------\n";
		cout<<"  ";
		for(int i=65;i<=nodes+64;i++)
		cout<<(char)i<<" ";
		cout<<endl;
		cout<<"-----------------\n";
		for(int i=0;i<nodes;i++)
		{
			cout<<char(i+1+64)<<"|";
			for(int j=0;j<nodes;j++)
			{
//				cout<<adj[i][j]<<" ";
				if(adjMatrix[i][j]==true)
				cout<<1<<" ";
				else
				cout<<0<<" ";
			}
			cout<<endl;
		}
		cout<<"\n-------Distance Matrix----------\n";
		cout<<"-----------------\n";
		cout<<"  ";
		for(int i=65;i<=nodes+64;i++)
		cout<<(char)i<<" ";
		cout<<endl;
		cout<<"-----------------\n";
		for(int i=0;i<nodes;i++)
		{
			cout<<char(i+1+64)<<"|";
			for(int j=0;j<nodes;j++)
			{
					if(distMatrix[i][j]!=-1)
					cout<<distMatrix[i][j]<<" ";
					else
					cout<<(char)236<<" ";
			}
			cout<<endl;
		}
	}
};

int main()
{
	dijkstra d;
	return 0;
}
	
	
