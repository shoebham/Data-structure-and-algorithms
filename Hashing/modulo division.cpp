#include<iostream>
using namespace std;

class hashing
{
	public:
	int size,mem_size;
	
	int arr[100],memory[100];
		hashing()
		{
			cout<<"Enter size of memory "<<endl;
			cin>>mem_size;
			fill_mem_arr();	
			input_elements();
			modulo_division();
			display_memory();
		}
	void fill_mem_arr()
	{
		for(int i=0;i<mem_size;i++)
			{
				memory[i]=-1;
			}	
	}
	void input_elements()
	{
		cout<<"Enter size of array"<<endl;
		cin>>size;
		cout<<"Enter array elements "<<endl;
		for(int i=0;i<size;i++)
		{
			cin>>arr[i];
		}
	}
	void modulo_division()
	{
		for(int i=0;i<size;i++)
		{ 
			int j =arr[i]%(mem_size);
			if(memory[j]==-1)
			{
			memory[j]=arr[i];
//			cout<<"memory[j] "<<memory[j]<<" arr[i] "<<arr[i]<<" i "<<i<<" j "<<j<<endl;
			}
			else
			{
				cout<<"Collision"<<endl;
//							cout<<"memory[j] "<<memory[j]<<" arr[i] "<<arr[i]<<" i "<<i<<" j "<<j<<" memsize "<<mem_size<<endl;
				int starting_point=j;
				while(memory[j]!=-1)
				{
//					cout<<"memory[j] "<<memory[j]<<" arr[i] "<<arr[i]<<" i "<<i<<" j "<<j<<endl;
					j=(1+j)%mem_size;
//					cout<<"starting_point = "<<starting_point<<endl;
					if(starting_point==j)
					{
					display_memory();
					cout<<"Memory full";
					exit(0);
					}
				}
				memory[j]=arr[i];
//				continue;
			}
		}
	}

	void display_memory()
	{
		cout<<"-------------\n";
		cout<<"Memory"<<endl;
		cout<<"-------------\n";
		for(int i=0;i<mem_size;i++)
		{
			if(memory[i]==-1)
			{
				cout<<i<<" - |-|"<<endl;
			}
			else
			{
			cout<<i<<" - |"<<memory[i]<<"|"<<endl;	
			}
		}
		cout<<endl;
	}
};



int main()
{
	hashing h;
	return 0;
}
