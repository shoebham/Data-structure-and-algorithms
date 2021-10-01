#include <iostream>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;

class fold_boundary
{
	public:
		int mem_size,num_of_digits,res=0,num=0,num_of_pairs=0,length_num,original_num;
		int arr[10000];string memory[10000];
		int rev_arr[10];
		string temp;
		
	//constructor
	fold_boundary()
	{
		cout<<"Enter size of memory\n";
		cin>>mem_size;
		num_of_digits=count(mem_size-1); // calculates of how many digits the pair will be
		fill_mem_arr();
//		cout<<"num of digits"<<num_of_digits<<endl;
		menu();
	}
	
	//menu
	void menu()
	{
		int choice;		
		do{
			cout<<"1.Enter data\n2.Display\n3.Exit\n";
			cin>>choice;		
			switch(choice)
			{
				case 1:
					input_data();
					fold();
					break;
				case 2:
					display();
					break;
				case 3:
					cout<<"Bye."<<endl;
					exit(0);
					break;	
			}			
		}while(choice!=3);
	}	
	
// power function 
//	int pow(int base,int exponent)
//	{
// 	if(exponent==0)
//  	 return 1;
//  
//  	return  base*pow(base,exponent-1);
//	}
		
		//initializes memory with -1
		void fill_mem_arr()
		{	
		for(int i=0;i<mem_size;i++)
			{
				memory[i]="-1";
			}		
		}
		
	// returns number of digits
	int count(int n)
	{
		if(n==0)
			return 0;
		return 1+count(n/10);
	}
	
	//reverses a string (reverses 1 to 10)
	int reverse(int n)
	{
		int res = 0;
		if(n<10&&n>0)
		{
//			cout<<"here";
			res=n*pow(10,num_of_digits-1);
		}
		else
		{
    		while (n > 0) 
			{
        		res = res * 10 + n % 10;
        		n = n / 10;
   			}
   		}
//   		if(count(res)<num_of_digits)
//		   res=res*pow(10,num_of_digits-count(res));
	return res;	
	}
	
	//asks for input from the user 
	void input_data()
	{
		cout<<"Enter data"<<endl;
		cin >> temp;
		stringstream ss(temp);	//converts string to integer
		ss>>arr[0]; 
		original_num=arr[0];
//		temp=arr[0];
		length_num= temp.length();
//		if(num_string[0]=='0')
//		{
//			cout<<"here";	
//			length_num+=1;	
//		}
//		cout<<"length_num"<<length_num<<endl;
		num_of_pairs=(length_num+1)/num_of_digits;  //calculates the number of pairs that will be made acc to memory size
//		cout<<"num pair"<<num_of_pairs<<"\n";
	}
	

	void fold()
	{

		int i=0;
		int sum=0;
		for(int i=0;i<=num_of_pairs;i++)
		{
//		
//			cout<<"num of digits"<<num_of_digits;
			num=arr[0]%(int)pow(10,num_of_digits);  // calculates last number acc to digits of pair;
//			cout<<"number "<<num<<" "<<endl;
//			cout<<"Number of digits of number"<<length_num<<endl;
//			if(i%2==1)
//			{
//				cout<<"i  is "<<i<<endl;
//				continue;
//			}
//			rev_arr[i]=reverse(num);
			
			// if there is no middle reverse only boundary
//			cout<<"numpairs "<<num_of_pairs<<endl;
			if(num_of_pairs%2==0)
			{
//				cout<<"num = "<<num<<endl;
				if(i==0||i==num_of_pairs-1)
				sum+=reverse(num);
				else
				sum+=num;
//				cout<<"reverse digit is "<<reverse(num)<<endl;
			}
			else
			{
//				if(i%2==0) // reverse alternate pairs
//				{
//					sum+=reverse(num);
//					cout<<"sum= "<<sum<<endl;
//					cout<<"reverse digit is "<<reverse(num)<<endl;
//				}
//				else 	//does not reverses middle alternatives
//					sum+=num;
//					cout<<"sum= "<<sum<<endl;
				int mid=num_of_pairs/2;
				if(i==mid)
				{
					sum+=num;
					cout<<"sum "<<num;
				}
				else
				{
				sum+=reverse(num);
			cout<<" s um "<<num;
				}
			}
//			cout<<"sum is "<<sum<<endl;
//			cout<<"arr[0] before division"<<arr[0]<<endl;
			arr[0]=arr[0]/pow(10,num_of_digits);  //calculates the remaining number after removing the first pair and so on
//			cout<<"arr[0] after division"<<arr[0]<<endl;
		}
		cout<<"sum is "<<sum<<endl;
		//if the digits of total sum is greater than digits of memory 
		if(count(sum)>num_of_digits)
		{
			sum=sum%(int)pow(10,num_of_digits); //calculates the number after removing starting digits 
//			cout<<"sum is "<<sum<<endl;
		}
		int j = sum%mem_size;	//calculates index to store location
		insert_into_mem(memory,temp,j); // inserts into memory
//		memory[j]=temp;
	}
	
	//insert into memory
	void insert_into_mem(string mem[],string n,int j)
	{
		
		if(mem[j] != "-1") //checks for collision
		{
			
			
			int starting_point=j; // initializes starting to point to check if memory is full
			while(memory[j]!="-1") //iterates while index is not equal to empty location
			{
				cout<<"Collision at "<<j<<"\n";
				j=(1+j)%mem_size; //increases index and resets to 0 when memory end is reached
				
				if(starting_point==j) //index reaches starting point and memory is full
				{
					display(); //display memory
					cout<<"Memory full"; 
					exit(0);
				}	
			}
//			cout<<"n is "<<n<<" j is "<<j<<" memory[j] "<<memory[j]<<endl; 
			memory[j]=(n);cout<<"Element inserted at "<<j<<endl; 
		}
		else //if there is no collision simply insert the element
		{
			memory[j]=temp;
			cout<<"Element inserted at "<<j<<endl;
		}
	}
	
	//display memory
	void display()
	{
		cout<<"-------------\n";
		cout<<"Memory"<<endl;
		cout<<"-------------\n";
		for(int i=0;i<mem_size;i++)
		{
			if(memory[i]=="-1")
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
	fold_boundary f;
	f.menu();	
	return 0;
}
