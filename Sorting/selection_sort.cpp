#include<iostream>
#include<vector>
using namespace std;

class selection_sort
{
	
	public:
	vector<int> arr;
	int size,total=0,comp=0;
	
	//constructor
	selection_sort()
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
	
	//sorts the array by comparing finding minimun on each iteration and swapping it with first element of array and so on...
	void sort()
	{
		cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		for(int i=0;i<size-1;i++)
		{
			int min = arr[i];
			int minIndex = i;
			for(int j=i+1;j<size;j++)
			{
				
//				cout<<" <-- "<<j<<" = j ";
				if(arr[j]<min) //checks for minimum element
				{
					min=arr[j];
					minIndex=j;
				}
			comp++;
			}
//			int temp = arr[i];
//			arr[i]=arr[minIndex];
//			arr[minIndex]=temp;

				cout<<"i = "<<i<<" --> ";
				for(int k=0;k<size;k++)
				{
					cout<<"|"<<arr[k]<<"|";
				
				}		cout<<"Minimum element: "<<min<<", Swapping "<<arr[i]<<" and "<<arr[minIndex];
				cout<<endl;
			swap(arr[i],arr[minIndex]);
			total++;
		}
		cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout<<"Total comparisions "<<comp<<" Total swaps "<< total <<endl;	
	}
	
	//display the sorted array
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
	selection_sort s;
	return 0;
}	
