#include<iostream>
#include<vector>
using namespace std;

class quick_sort
{
	
	
	public:
	vector<int> arr;
	int size,total=0;
	
	//constructor
	quick_sort()
	{
		// input_arr();
		//arr.resize(6);
		arr.push_back(5);
		arr.push_back(8);
		arr.push_back(9);
		arr.push_back(3);
		arr.push_back(10);
		arr.push_back(1);

		sort();
			cout<<"++++++++++++++++++++++++++++++++++++++++\n";
		display();
	}
	
	void sort()
	{
		int low =0,high=6;
		
		quick(low,high);
	}
	void quick(int low,int high)
	{
		if(low<high)
		{
//			for(int i=low;i<high;i++)
//			{
//				cout<<"|"<<arr[i]<<"|";
//			}
//			cout<<" low = "<<low<<" high = "<<high;
			int j=partition(low,high);
			
			quick(low,j);
			quick(j+1,high);
		}
	}
	int partition(int low, int high)
	{
		
		int pivot = arr[low];
		int i=low,j=high;
		
//			for(int i=low;i<high;i++)
//			{
//				cout<<"|"<<arr[i]<<"|";
//			}
		cout<<" i = "<<i<<" j = "<<j<<" swapping "<<arr[low]<<" and "<<arr[j];
display();
//		cout<<"pivot = "<<pivot;
		while(i<j){
			do
			{
				i++;
			}while(arr[i]<=pivot);
			do
			{
				j--;
			}while(arr[j]>pivot);
			if(i<j)
			{
//				cout<<" swapping "<<arr[i]<<" and "<<arr[j]<<endl;
				swap(arr[i],arr[j]); 
			}
		}
		cout<<" i = "<<i<<" j = "<<j<<" swapping "<<arr[low]<<" and "<<arr[j];
		swap(arr[low],arr[j]);
//			cout<<"after putting the pivot in its right place "<<endl;
		cout<<endl;
			
		return j;
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
	
		for(int i=0;i<6;i++)
		{
			cout<<"|"<<arr[i]<<"|";
		}
	}
};


int main()
{
	quick_sort q;
	
	return 0;
}
