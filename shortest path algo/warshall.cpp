#include<iostream>
#include<vector>
using namespace std;
class warshall
{
	public:
		vector<vector<int>> adjMatrix;
		vector<bool> visited={false};
		vector<vector<int>> distMatrix;
		vector<int> res,prev={0},tempDist;
		int nodes,connected,choice,dist;
		
		
	warshall()
	{
//		menu();
		input_arr();
		input_nodes();
//		display();
		warsh();
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
				distMatrix[j-1].resize(nodes,INT_MAX/2);
//				visited[j-1].resize(nodes);
				
				if(i==j)
				{
					input_distMatrix(i-1,j-1,0);
				continue;	
				}
				
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
	
	void warsh()
	{
		for(int i=0;i<nodes;i++)
		{
			for(int j=0;j<nodes;j++)
			{
				for(int k=0;k<nodes;k++)
				{
					
					int currDist = distMatrix[j][i]+distMatrix[i][k];
//					cout<<"\ni = "<<i<<" j = "<<j<<" k = "<<k<<endl;
//					cout<<"Currdist ="<<currDist<<endl;
					if(distMatrix[j][k]>currDist)
					{	
//						cout<<"here";
						distMatrix[j][k]=currDist;
						distMatrix[k][j]=currDist;
					}
				}
			}
		}
		display_res();
		
	}
	
	void display_res()
	{
		cout<<"---------------------\n";
		cout<<"Final Distance Matrix\n";
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
					if(distMatrix[i][j]!=INT_MAX/2)
					cout<<distMatrix[i][j]<<" ";
					else
					cout<<(char)236<<" ";
			}
			cout<<endl;
		}
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
					if(distMatrix[i][j]!=INT_MAX/2)
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
	
	warshall w;
	return 0;
}
