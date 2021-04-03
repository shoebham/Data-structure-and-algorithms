#include<iostream>
using namespace std;

class modulo_division
{
	public:
	int size=0,mem_size,choice=0;
	int arr[100],memory[100];

		//constructor
		modulo_division()
		{
			cout<<"Enter size of memory "<<endl;
			cin>>mem_size;
			fill_mem_arr();	
			menu();
		}
		
		//menu
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
		
	//initializes memory array 
	void fill_mem_arr()
	{
		for(int i=0;i<mem_size;i++)
			{
				memory[i]=-1;
			}	
			
	}
	
	//asks for data from the user
	void input_data()
	{	
		cout<<"Enter data\n";
		cin>>arr[0];
	}


	//modulo division function
	void modulo()
	{
		
		int j=arr[0]%(mem_size); //calculates index 
		
		if(memory[j]==-1)	//if index is empty
		{
			memory[j]=arr[0];
			cout<<"Element inserted at "<<j<<endl;
		}
		else 	//there is collision
		{
			
			int starting_point=j; //starting point to check for memory full
			while(memory[j]!=-1)
			{
				cout<<"Collision at "<<j<<"\n";
				j=(1+j)%mem_size; // calcualtes index at each iteration 
				
				if(starting_point==j) //if starting point and current index is same then memory is full
				{
					display_memory();
					cout<<"Memory full";
					exit(0);
				}
			}
			memory[j]=arr[0];
			cout<<"Element inserted at "<<j<<endl;
		}
		
	}

	//displays memory
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
