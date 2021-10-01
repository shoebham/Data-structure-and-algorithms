#include<iostream>
#include<vector>
using namespace std;

class shell_sort
{
	
	public:
	vector<int> arr;
	int size,total=0;
	
	//constructor
	shell_sort()
	{
		input_arr();
		sort();
		display();
	}

	void sort()
	{
		int interval,temp;
		interval=size;
		cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		
//		
//		for(int i=0;i<size;i++)
//		{
//			interval/=2;
//			
//			for(int j=interval;j<size;j++)
//			{
//				for(int k=j-interval;k<size-interval;k++)
//				{
//					for(int k=0;k<size;k++)
//					{
//						cout<<"|"<<arr[k]<<"|";
//					}	cout<<"interval= "<<interval<<" ";
//					if(arr[k]<=arr[k+interval])
//					break;
//					else
//					{
//						cout<<arr[k]<<" > "<<arr[k+interval]<<" ";	
//						swap(arr[k],arr[k+interval]);
//					}			cout<<endl;			
//				}
//				
//			
//			}
//			cout<<endl;
//		}

			for(int i=interval/2;i>0;i/=2)
			{
				for(int j=i;j<size;j++)
				{
					
					for(int k=0;k<size;k++)
					{
						cout<<"|"<<arr[k]<<"|";
					}	cout<<"interval= "<<i<<" ";
					int k;
					temp=arr[j];
					
					for(k=j-i;k>=0&&temp<arr[k];k=k-i)
					{
//						cout<<"k = "<<k<<" i= "<<i<<" j ="<<j<<" ";
						cout<<" "<<arr[k]<<" > "<<temp;
						arr[k+i]=arr[k];
						
					}	
					arr[k+i]=temp;
					cout<<endl;			
				}
			}	cout<<endl;
			cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		
	}
	//takes input
	void input_arr()
	{
		cout<<"Enter size of array\n";
		cin>>size;
		cout<<"Enter elements\n";
		for(int i=0;i<size;i++)
		{
			int n;
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
	
	void display()
	{
		for(int i=0;i<size;i++)
		{
			cout<<"|"<<arr[i]<<"|";
		}
	}
	
};


int main()
{
	shell_sort s;
	return 0;
}
