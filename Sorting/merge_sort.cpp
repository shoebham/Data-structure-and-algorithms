#include<iostream>
#include<vector>
using namespace std;


class merge_sort
{
	public:
	vector<int> arr,sorted_arr;
	int size,total=0;
	
	//constructor
	merge_sort()
	{
		input_arr();
		sort();
		cout<<"\n---------Sorted Array---------\n";
		display();
	}
	
	void sort()
	{
		int low=0,high=size-1;
		sorted_arr.resize(size);	
		mergesort(low,high);
	}
	void mergesort(int low,int high)
	{
		int mid;
		if(low<high)
		{
		mid=(low+high)/2;
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,mid,high);
		display();
		cout<<endl;
		}
	}
	void merge(int low,int mid,int high)
	{
		vector<int> copy1,copy2;
		
		int n = mid-low+1,n1=high-mid;
		copy1.resize(n);copy2.resize(n1);
//		cout<<"mid is "<<mid<<" low "<<low<<" high "<<high<<endl;
//		cout<<"element at mid "<<arr[mid]<<" ";
		for(int i=0;i<n;i++)
		{
//			cout<<"pushing in copy1 "<<arr[i+low]<<endl;
			copy1[i]=arr[i+low];
		}
		
		for(int j=0;j<n1;j++)
		{
//			cout<<"pushing in copy2 "<<arr[mid+j+1]<<endl;
			copy2[j]=arr[mid+j+1];
//			cout<<"here\n";
		}
	
		
		int i=0,j=0,k=low;
		while(i<n&&j<n1)
		{
			if(copy1[i]<=copy2[j])
			{
//				cout<<"here";
				arr[k++]=copy1[i++];
			}
			else
			{
//				cout<<"k "<<k;
				arr[k++]=copy2[j++];
				
			}
		}
		cout<<"sub array\n";
		for(auto x: copy1)
		cout<<"|"<<x<<"|";
		cout<<endl;
		
		for(auto x: copy2)
		cout<<"|"<<x<<"|";
		cout<<endl;
		cout<<"----------Merging----------\n";
//		for(;i<n;i++)
//		arr[k++]=copy1[i];
//		for(;j<n1;j++)
//		arr[k++]=copy2[j];
		while(i<n)
		arr[k++]=copy1[i++];
		while(j<n1)
		arr[k++]=copy2[j++];
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
	merge_sort m;
	
	return 0;
}

