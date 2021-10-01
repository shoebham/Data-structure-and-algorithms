#include<iostream>
#include<vector>
using namespace std;


class heap_sort
{
	public:
	vector<int> arr,max_heap_arr,min_heap_arr;
	int size,heap_size,choice,sort_choice;
	
	//constructor
	heap_sort()
	{
		menu();
		input_arr();
//		display();	
		sort();
		display();
	}
	void menu()
	{
		cout<<"Enter your choice\n1.Max-Heap\n2.Min-Heap\n";
		cin>>choice;
		cout<<"Enter your choice\n1.Ascending Order\n2.Descending Order\n";
		cin>>sort_choice;
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
			if(choice==1)
			max_heap();
			else
			min_heap();
	//		display();	
			
			for(int i=size-1;i>=0;i--)
			{
				if(sort_choice==2||sort_choice==1)
				{
					if(choice==1)
					max_heap_arr.push_back(arr[0]);	
					if(choice==2)
					{
						min_heap_arr.push_back(arr[0]);
					
					}
				}
//					cout<<"arr[0] "<<arr[0]<<endl;
				swap(arr[0],arr[i]);
	//			cout<<"Swapped "<<arr[0]<<" "<<arr[i]<<endl;
	//				display();	
				heap_size=i;	
				if(choice==1)
				max_heapify(0);
				else
				min_heapify(0);
			}
			cout<<endl;
		
	}
	
	void max_heap()
	{
		heap_size= size;
		for(int i=size/2-1;i>=0;i--)
		max_heapify(i);
	}
	
	void max_heapify(int i)
	{
		
		int left=(2*i+1);
		int right=(2*i+2);
//		cout<<"left "<<left<<" right "<<right; 
		int largest=i;
//		cout<<"root is "<<arr[i]<<" left child = "<<arr[left]<<" right= "<<arr[right]<<endl;
		if(left<heap_size&&arr[left]>arr[largest])
		largest=left;
		
		
		if(right<heap_size&&arr[right]>arr[largest])
		largest=right;
		
		if (largest!=i){
//			cout<<"here";
		swap(arr[i],arr[largest]);
//		cout<<"Swapped "<<arr[i]<<" "<<arr[largest];
		max_heapify(largest);
		}
		
	}
	
	void min_heap()
	{
		heap_size= size;
		for(int i=size/2-1;i>=0;i--)
		min_heapify(i);
	}
	void min_heapify(int i)
	{
		int left=(2*i+1);
		int right=(2*i+2);

		int smallest=i;

		if(left<heap_size&&arr[left]<arr[smallest])
		smallest=left;
		
		
		if(right<heap_size&&arr[right]<arr[smallest])
		smallest=right;
		
		if (smallest!=i){
//			cout<<"here";
		swap(arr[i],arr[smallest]);
//		cout<<"Swapped "<<arr[i]<<" "<<arr[largest];
		min_heapify(smallest);
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
		if(sort_choice==2&&choice==1)
		{
			for(int i=0;i<size;i++)
			{
				cout<<"|"<<max_heap_arr[i]<<"|";
			}
			cout<<endl;	
		}
		else if(choice==2&&sort_choice==1)
		{
			for(int i=0;i<size;i++)
			{
				cout<<"|"<<min_heap_arr[i]<<"|";
			}
			cout<<endl;	
			}
		else
		{
			for(int i=0;i<size;i++)
			{
				cout<<"|"<<arr[i]<<"|";
			}
			cout<<endl;	
		}
		
	}
};

int main()
{
	heap_sort h;
	return 0;
}
