#include <iostream>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;

class fold_boundary
{
	public:
		int mem_size,num_of_digits,res=0,num=0,num_of_pairs=0,length_num,original_num;
		int arr[100];string memory[1000];
		int rev_arr[10];
		string temp;
	fold_boundary()
	{
		cout<<"Enter size of memory\n";
		cin>>mem_size;
		num_of_digits=count(mem_size-1);
		fill_mem_arr();
//		cout<<"num of digits"<<num_of_digits<<endl;
		menu();
	}
	
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
	
	
		void fill_mem_arr()
		{	
		for(int i=0;i<mem_size;i++)
			{
				memory[i]="-1";
			}		
		}
		
	int count(int n)
	{
		if(n==0)
			return 0;
		return 1+count(n/10);
	}
	
	int reverse(int n)
	{
		int res = 0;
		if(n<10&&n>0)
		{
//			cout<<"here";
			res=n*pow(10,num_of_digits-1);
		}
		else{
    	while (n > 0) 
		{
			//1 = 1%10=1 1/10=0
//			121 = 1 2 1 
//			123456 = 1 2 3 4 5 6
//			012345 = 54+23+10
        res = res * 10 + n % 10;
        n = n / 10;
   		}
   		}
//   		if(count(res)<num_of_digits)
//		   res=res*pow(10,num_of_digits-count(res));
	return res;	
	}
	
	void input_data()
	{
		cout<<"Enter data"<<endl;
		cin >> temp;
		stringstream ss(temp);
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
		num_of_pairs=(length_num+1)/num_of_digits;
//		cout<<"num pair"<<num_of_pairs<<"\n";
	}
	void fold()
	{
//		20
//		12345
//		12345%100=45
//		12345/100=123;
//		123%100=23;
//		123/100=1;
//		54+23
//		10+23+54=87;
		int i=0;
		int sum=0;
		for(int i=0;i<=num_of_pairs;i++)
		{
//		
//			cout<<"num of digits"<<num_of_digits;
			num=arr[0]%(int)pow(10,num_of_digits);
//			cout<<"number "<<num<<" "<<endl;
//			cout<<"Number of digits of number"<<length_num<<endl;
//			if(i%2==1)
//			{
//				cout<<"i  is "<<i<<endl;
//				continue;
//			}
//			rev_arr[i]=reverse(num);
			if(num_of_pairs%2==0)
			{
				sum+=reverse(num);
//				cout<<"reverse digit is "<<reverse(num)<<endl;
			}
			else
			{
			if(i%2==0)
			{
			sum+=reverse(num);
//			cout<<"reverse digit is "<<reverse(num)<<endl;
			}
			else
			sum+=num;
			}
//			cout<<"sum is "<<sum<<endl;
//			cout<<"arr[0] before division"<<arr[0]<<endl;
			arr[0]=arr[0]/pow(10,num_of_digits);
//			cout<<"arr[0] after division"<<arr[0]<<endl;
		}
		if(count(sum)>num_of_digits)
		{
//			198%100=98
			sum=sum%(int)pow(10,num_of_digits);
//			cout<<"sum is "<<sum<<endl;
		}
		int j = sum%mem_size;
		insert_into_mem(memory,temp,j);
//		memory[j]=temp;
	}
	void insert_into_mem(string mem[],string n,int j)
	{
		
		if(mem[j] != "-1")
		{
			cout<<"Collision"<<endl;
			int starting_point=j;
			while(memory[j]!="-1")
			{
				j=(1+j)%mem_size;
				if(starting_point==j)
				{
					display();
					cout<<"Memory full";
					exit(0);
				}	
			}
//			cout<<"n is "<<n<<" j is "<<j<<" memory[j] "<<memory[j]<<endl; 
			memory[j]=(n);cout<<"Element inserted at "<<j<<endl;
		}
		else
		{
			memory[j]=temp;
			cout<<"Element inserted at "<<j<<endl;
		}
	}
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
