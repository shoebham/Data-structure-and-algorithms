#include<bits/stdc++.h>
using namespace std;


class msort
{
public:
	msort(int* arr,int size)
	{

		size--;
		m_sort(arr,0,size);
	}

	void m_sort(int* arr, int start, int end)
	{
		if(start>=end)return;
		
		int mid = (start+end)/2;
		m_sort(arr,start,mid);
		m_sort(arr,mid+1,end);
		merge(arr,start,mid,end);

	}

	void merge(int* arr, int start, int mid, int end)
	{
		int l = (mid-start+1);
		int r = (end-mid);
		int newarr[l+r];
		int i=start;
		int j=mid+1;
		int x=0;
		while(i<=mid&&j<=end)
		{
			// cout<<i<<" "<<mid<<" "<<j<<" \n";
			// cout<<arr[i]<<" "<<arr[mid]<<" "<<arr[j]<<" \n";
			if(arr[i]<=arr[j])
				newarr[x++]=arr[i++];
			else if(arr[j]<=arr[i])
				newarr[x++]=arr[j++];
		}
		while(i<=mid)newarr[x++]=arr[i++];
		while(j<=end)newarr[x++]=arr[j++];

		int y=0;
		for(int i = start; i<=end;i++)
		{
			arr[i]=newarr[y++];
		}
	}

};

void fill_csv(int* arr,int n)
{

	srand(time(0));
	ofstream myfile;
	myfile.open("number.csv");

	for(int i=0;i<n;i++)
		myfile<<rand()<<endl;

	myfile.close();
	freopen("number.csv","r",stdin);

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}
int main()
{
	int size=10000;
	int arr[size];

	// // srand(time(0));
	// for(int i=0;i<size;i++)
	// {
	// 	int num = rand()%size;
	// 	arr[i]=(num);
	// }

	fill_csv(arr,size);
	// cout<<"\n--------Unsorted array----------\n";
	// for(int i=0;i<size;i++)
	// 	cout<<arr[i]<<" ";

	msort m(arr,size);
	cout<<"\n--------Sorted array----------\n";
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
	
	return 0;
}
