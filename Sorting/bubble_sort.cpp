#include<iostream>
#include<vector>
using namespace std;


class bubble_sort 
{
	public:
	vector<int> arr;
	int size,total=0;
	
	bubble_sort()
	{
		input_arr();
		sort();
		display();
	}
	
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
		
		cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		for(int i=0;i<size;i++)
		{
//			cout<<"Pass "<<i<<":\t|\n";
			for(int j=0;j<size-1;j++)
			{
				cout<<"i = "<<i<<" --> ";
				
				for(int k=0;k<size;k++)
				{
					cout<<"|"<<arr[k]<<"|";
				}	cout<<" <-- "<<j<<" = j ";
				
				if(arr[j]<arr[j+1])
				{
					cout<<"("<<arr[j+1]<<" > "<<arr[j]<<") No swap \t|";
				}
				
				if(arr[j]>arr[j+1])
				{
					cout<<"("<<arr[j]<<" > "<<arr[j+1]<<") swap \t|";
					int temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
					total++;
				}
				cout<<endl;
			}
		cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";	
		}
	}
	void display()
	{
		for(int i=0;i<size;i++)
		{
			cout<<"|"<<arr[i]<<"|";
		}
		cout<<"\nTotal passes: "<<size-1<<" Total comparisions: "<<size*(size-1)<<" Total swaps: "<<total<<endl;
	}
};
int main()
{
	
	bubble_sort b;
	return 0;
}

