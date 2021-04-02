#include<iostream>
using namespace std;

int main()
{
	int arr[] = {5,4,3,2,1};
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<"i = "<<i<<" --> ";
			for(int k=0;k<5;k++)
			{
				cout<<"|"<<arr[k]<<"|";
			}	cout<<" <-- "<<j<<" = j ";
			if(arr[j]<arr[j+1])
			{
				cout<<"("<<arr[j+1]<<" > "<<arr[j]<<") No swap";
			}
			if(arr[j]>arr[j+1])
			{
				cout<<"("<<arr[j]<<" > "<<arr[j+1]<<") swap";
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
			
							cout<<endl;
		}
		cout<<"\n+++++++++++++++++++++++++++++++++++++\n";
	}
	return 0;
}

