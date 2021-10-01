#include <iostream>
using namespace std;

class search
{
	public:
	int size,key,choice;
	int arr[];
	search()
	{
		
	}
	void menu()
	{
		cout<<"Enter search method"<<endl<<"1.Linear search (If you repeat numbers it will find all positions of the number)"<<endl
		<<"2.Binary search (If you repeat numbers it will find only the first position of the number)"
		<<endl<<"3.Interpolation search (If you repeat numbers it will find only the first position of the number)"<<endl;
		cin>>choice;
		cout<<"Enter array size"<<endl;
		cin>>size;
		input_arr();
	
		if(choice==1)
		{
		linear();	
		exit(0);
		}
		else if(choice==2)
		{
		binary();
		exit(0);	
		}
		else if (choice==3)
		{interpolation();
		exit(0);}
	}
	void input_arr()
	{
		cout<<"Enter array elements"<<endl;
		
		for(int i=0;i<size;i++)
		{
			int n;
			cin>>n;
			arr[i]=n;
		}
	}
	void linear()
	{
		
		cout<<"Enter element you want to find"<<endl;
		cin>>key;
		for(int i=0;i<size;i++)
		{
			if(arr[i]==key)
			{
				cout<<"Found element at:"<<i+1<<endl;
//				exit(0);
			}	
		}
//		cout<<"No element found!!"<<endl;
	}
	
	void binary()
	{
		sort(arr);
		cout<<"Enter element you want to find"<<endl;
		cin>>key;
		int low=0,mid,high=size-1,steps=0;
		while(low<=high)
		{
			mid = (high+low)/2;
			steps++;
			cout<<"mid is "<<mid<<" ";
			if(arr[mid]==key)
			{
				cout<<"Element found at: "<<mid+1<<endl;
				cout<<"Number of steps "<<steps<<endl;
				break;
			}
			if(arr[mid]>key)
			{
				high=mid-1;
			}
			if(arr[mid]<key)
			{
				low=mid+1;
			}
		}
		if(arr[mid]!=key) 
			{
				cout<<"No element found!!"<<endl;
			}
	}
	void interpolation()
	{
		sort(arr);
		cout<<"Enter element you want to find"<<endl;
		cin>>key;
		
		int low=0,high=size-1,mid=-1;
		while(low<=high&&key<=arr[high]&&key>=arr[low])
		{
			mid=low+((high-low)*(key-arr[low])/(arr[high]-arr[low]));
//			cout<<"mid is "<<mid<<" high is "<<high<<"low is "<<low <<endl;
			if(arr[mid]==key)
			{
			cout<<"Found element at: "<<mid+1;
			exit(0);
			}
			else if (arr[mid]<key)
			{
				low=mid+1;
			}
			else if(arr[mid]>key)
			{
				high=mid-1;
			}
		}
		if(arr[mid]!=key) 
			{
				cout<<"No element found!!"<<endl;
				
			}
//		cout<<"low is "<<low<<"high is "<<high;
//		cout<<"\narr[low]= "<<arr[low]<<" arr[high] = "<<arr[high];
//		cout<<"key-arr[low] = "<<key-arr[low]<<" arr[high]-arr[low] = "<<arr[high]-arr[low]<<"high-low"<<high-low;
//		int pos = low + (((key-arr[low])/(arr[high]-arr[low]))*(high-low));
//		cout<<"Found element at: "<<pos;
		
	}
	void sort(int array[])
	{
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size-i-1;j++)
			{
				if(arr[j]>arr[j+1])
				{
					int temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
		cout<<"Sorted array is: ";
		for(int i=0;i<size;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};


int main()
{
	search s;
	s.menu();
	return 0;
}
