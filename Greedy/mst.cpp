#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class mst
{

	
	public:
		vector< vector<int> > arr;
		vector<char> v;
		int size;
		vector<int> tree;

		// result  < <node1,node2>, weight >;
		vector< pair< pair<char,char>, int > >  res;

		int min_cost=0;
		// list of edges with weight and connected vertices
		// vector<weight, <v1,v2>> 
		vector<pair< int, pair <int,int> > > edges;

		mst()
		{
			input_graph();
			display_matrix();
			minimum();
			display_result();
		}

		void input_graph()
		{
			int n;
			cout<<"Enter total number of Vertices"<<endl;
			cin>>n;
			size=n;
			init_vertex();
			arr.resize(n);
			
			char c='A';
			cout<<"Enter weight(Weight/0):\n";
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					
					arr[j].resize(n,-1);
					
					if(i==j)continue;
					if(arr[i][j]>=1||arr[i][j]==0)continue;
					cout<<v[i]<<"->"<<v[j]<<" ";

					int in;
					cin>>in;
					arr[i][j]=in;
					arr[j][i]=in;
					
					if(in!=0)
					edges.push_back({in,{i,j}});
				}
			}
		}
		void init_vertex()
		{
			v.resize(size);
			tree.resize(size);
			for(int i=0;i<size;i++)
				v[i]=(char)i+65;
			for(int i=0;i<size;i++)
				tree[i]=i;
		}
		
		void display_matrix()
		{
			cout<<"--------------------------------------\n";
			cout<<"  ";
			for(int i=0;i<size;i++)
			cout<<v[i]<<" ";
			
			cout<<endl;
			cout<<"--------------------------------------\n";
			
			for(int i=0;i<size;i++)
			{
				cout<<v[i]<<"|";
				for(int j=0;j<size;j++)
				{
					if(arr[i][j]==-1)
					cout<<0<<" ";
					else
					cout<<arr[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<"\n--------------------------------------\n";
			sort(edges.begin(),edges.end());
			cout<<"|First vertex -> Second vertex|-> Weight\n";
			for(int i=0;i<edges.size();i++)
			{
				
				cout<<"|"<<v[edges[i].second.first]<<"->"<<v[edges[i].second.second]<<"|->"<<edges[i].first<<endl;
			}
		}



		void minimum()
		{
			
			for(auto x: edges)
			{
				int v1=x.second.first;
				int v2=x.second.second;
//				cout<<"v1 "<<v1<<" v2 "<<v2<<endl; 
				if(tree[v1]!=tree[v2])
				{
					min_cost+=x.first;
					res.push_back( { {v[v1],v[v2]} , x.first } );

					int old_node= tree[v1];
					int new_node= tree[v2];

					for(int i=0;i<size;i++)
					{
						if(tree[i]==old_node)
						{
							tree[i]=new_node;
						}
					}
				}
			}
		}


		void display_result()
		{
			cout<<"\n--------------------------------------\n";
			cout<<"|Node1-> Node2| Weight\n";
			for(auto x:res)
			{
				cout<<"|"<<x.first.first<<"->"<<x.first.second<<"|->"<<x.second<<endl;
			}
			cout<<"Minmum cost of tree:- "<<min_cost<<endl;
			
		}
};

int main()
{
	// init_code();
	
//2
//0
//1
//4
//0
//3
//3
//0
//7
//5
//0
//8
//9
//0
//0

	
	mst m;
}
