#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class radix_sort
{
	
	public:
	vector<string> arr;
	int size,total=0;
	vector<vector<string>> bucket;
	//constructor
	radix_sort()
	{
		input_arr();
		fill_arr();
//		display_bucket();
		sort();
		cout<<"\n----------------Sorted Array---------------\n";
		display();
	}
	void make_digit_equal(int max)
	{
		for(int i=0;i<size;i++)
		{
			stringstream ss(arr[i]);
			int temp;
			ss>>temp;
			if(count(temp)<max)
			{
				int diff=(max-count(temp));
				for(int j=0;j<diff;j++)
				{
					arr[i]="0"+arr[i];
				}				
			}
		}	
	}
	void sort()
	{

		int max=0,number_digits;
		for(int i=0;i<size;i++)
		{
			stringstream ss(arr[i]);
			int temp;
			ss>>temp;
			if(temp>max)
			{
				max=temp;
			}
		}
		
		number_digits=count(max);
		make_digit_equal(number_digits);
		display();
		for(int x=number_digits-1;x>=0;x--)
		{
		
			for(int i=0;i<size;i++)
			{
				string temp_string=arr[i];
				temp_string=temp_string[x];
//				cout<<"temp_string "<<temp_string<<" x is "<<x;
				stringstream ss(temp_string);
				int temp;
				ss>>temp;
				int pos=temp;
				int index=0;
	//			string temp;
	//			stringstream ss;
	//			ss<<arr[i];
	//			ss>>temp;
				while(bucket[index][pos]!="-")
				{
				index++;
				}
				bucket[index][pos]=arr[i];
			}
				display_bucket();
				fetch_values();
//				display_bucket();
			}
	}
	
	void fetch_values()
	{
//		empty_arr();
		arr.clear();
		vector<string> temp_arr;
		
		for(int i=0;i<10;i++)
		{
			int index=0;
			for(int j=0;j<size;j++)
			{
				if(bucket[j][i]!="-")
				{
					temp_arr.push_back(bucket[j][i]);
					bucket[j][i]="-";
					index++;
//					int temp;
//					stringstream ss;
//					ss<<bucket[i][j];
//					ss>>temp;
//					arr[index]= temp;
//					bucket[i][j]=" ";
//					index++;
				}
			}
		}
		arr=temp_arr;
		display();
	}
//	void empty_arr()
//	{
//		while(!arr.empty())
//		{
//			arr.pop_back();
//		}
//	}
	//takes input
	void input_arr()
	{
		cout<<"Enter size of array\n";
		cin>>size;
		cout<<"Enter elements\n";
		for(int i=0;i<size;i++)
		{
			string n;
			cin>>n;
			arr.push_back(n);
		}
	}	
	
	void swap(int &a,int &b)
	{
		int temp=b;
		b=a;
		a=temp;
	}
	void display_bucket()
	{
//		for(int i=0;i<10;i++)
//		cout<<"|"<<i<<"|";
		cout<<"\n----------------Bucket---------------";
		cout<<endl;
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<10;j++)
			{
				if(bucket[i][j]=="-")
				continue;
				cout<<bucket[i][j]<<"("<<j<<")";
				cout<<" ";
				
			}
			cout<<endl;
		}
	}
	void display()
	{
		
		for(int i=0;i<size;i++)
		{
			cout<<"|"<<arr[i]<<"|";
		}
	}
	
	int count(int n)
	{
		if(n==0)
			return 0;
		return 1+count(n/10);
	}
	
	void fill_arr()
		{	
		bucket.resize(size);
		for(int i=0;i<size;i++)
			{	
//				vector<string> v;
				bucket[i].resize(10);
				for(int j=0;j<10;j++)
				{
//						v.push_back(" ");
					bucket[i][j]="-";
				}
//				bucket.push_back(v);
			}		
		}
};


int main()
{
	radix_sort r;
	return 0;
}
