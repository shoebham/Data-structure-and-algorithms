#include<iostream>
#include<vector>
using namespace std;


class bubble_sort 
{
	public:
	vector<int> arr;
	int size,total=0,passes=0,comp=0;
	
	//constructor
	bubble_sort()
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
	
	//sorts the array by comparing each element with its adjacent element
	void sort()
	{
//		for(int i=0;i<size;i++)
//		cout<<"|"<<i<<"|";
//		cout<<endl;
		cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	
		for(int i=0;i<size-1;i++)
		{	bool flag =false;
			passes++;
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
					cout<<"("<<arr[j+1]<<" > "<<arr[j]<<") No swap \t";
//					flag=false;
				
				}
				if(arr[j]>arr[j+1])
				{
					cout<<"("<<arr[j+1]<<" < "<<arr[j]<<") swap \t";
					int temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
					total++;
					flag=true;
				}
				comp++;
				cout<<endl;
			}
		cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";	
//		if(!flag)
//		break;
		}
	}
	//displays the sorted array
	void display()
	{
		for(int i=0;i<size;i++)
		{
			cout<<"|"<<arr[i]<<"|";
		}
		cout<<"\nTotal passes: "<<passes<<" Total comparisions: "<<comp<<" Total swaps: "<<total<<endl;
	}
};
int main()
{
	
	bubble_sort b;
	return 0;
}

