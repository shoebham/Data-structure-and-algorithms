#include<iostream>
using namespace std;

class modulo_division
{
	public:
	int size=0,mem_size,choice=0;
	
	int arr[100],memory[100];
		modulo_division()
		{
			cout<<"Enter size of memory "<<endl;
			cin>>mem_size;
			fill_mem_arr();	
			menu();
		}
		
		
		void menu()
		{
			do
			{
			cout<<"1.Enter data \n2.Display Memory\n3.Exit.\n";
			cin>>choice;
				switch(choice)
				{
					case 1:
						input_data();
						modulo();
					break;
					case 2:
						display_memory();
						break;
					case 4:
						cout<<"Bye."<<endl;
						exit(0);
						break;
				}
			}while(choice!=3);
		}
	void fill_mem_arr()
	{
		for(int i=0;i<mem_size;i++)
			{
				memory[i]=-1;
			}	
			
	}
	
	void input_data()
	{	
		cout<<"Enter data\n";
		cin>>arr[0];
	}


	void modulo()
	{
		int j=arr[0]%(mem_size);
		if(memory[j]==-1)
		{
			memory[j]=arr[0];
		}
		else
		{
			cout<<"Collision\n";
			int starting_point=j;
			while(memory[j]!=-1)
			{
				j=(1+j)%mem_size;
				if(starting_point==j)
				{
					display_memory();
					cout<<"Memory full";
					exit(0);
				}
			}
			memory[j]=arr[0];
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
	modulo_division m;
	m.menu();
	return 0;
}
