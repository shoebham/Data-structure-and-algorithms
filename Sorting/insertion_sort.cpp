 #include<iostream>
#include<vector>

using namespace std;

class insertion_sort
{
	public:
		vector<int> arr;
		int size;
	insertion_sort()
	{
		input_arr();
		sort();
		display();
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
	
	void sort()
	{
		//54321
		//45321
		//
		
		int min,minIndex;
		cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		for(int i=1;i<size;i++)
		{	
			min = arr[i];
			minIndex=i;
			
				cout<<"i = "<<i<<" --> ";
				for(int k=0;k<size;k++)
				{
					cout<<"|"<<arr[k]<<"|";
				
				}		
//				cout<<" Assumed Minimum element "<<arr[minIndex];
				int j;
				bool flag=false;
				for(j=i-1;j>=0&&min<arr[j];j--)
				{
					arr[j+1]=arr[j];
					flag=true;
					cout<<" ("<<arr[j]<<">"<<min<<") ";
					
				}
				if(flag)
				cout<<"shifting from element "<<arr[j+1];
				arr[j+1]=min;
				
//			while(minIndex>0&&arr[minIndex-1]>min)
//			{
//				cout<<" "<<arr[minIndex-1]<<">"<<min<<" ";
//				arr[minIndex]=arr[minIndex-1];
//				minIndex--;
//			}
//			
//			arr[minIndex]=min;
			cout<<endl;
		}
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";	
	}
	//displays the sorted array
	void display()
	{
		for(int i=0;i<size;i++)
		{
			cout<<"|"<<arr[i]<<"|";
		}
	}
	//swap function
	void swap(int &a,int &b)
	{
		int temp=b;
		b=a;
		a=temp;
	}

};

int main()
{
	insertion_sort i;
	return 0;
}
