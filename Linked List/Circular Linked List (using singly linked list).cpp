#include<iostream>
using namespace std;



struct node
{
	int data;
	struct node *next;

};
struct node *head,*list,*temp,*last,*fix;

class operations
{
public:
int input,choice,n;
int total=0;
void menu()
{
	do{
		cout<<"Enter your choice\n1. Insertion \n2. Deletion \n3. Search \n4. Sort \n5. Reverse \n6. Count \n7. Display \n8. Exit"<<endl;
		cin>>input;
		switch(input){
		case 1:
			insert();
			break;
		case 2:
			del();
			break;
		case 3:
			search();
			break;
		case 4:
			sort();
			break;
		case 5:
			reverse();
			break;
		case 6:
			count();
			break;
		case 7:
			display();
			break;
	}
	}while(input!=8);
}


void insert()
{
	cout<<"1. Insert from beginning \n2. Insert from end \n3. Insert after a element \n4. Insert before a element"<<endl;
	cin>>choice;
	if(choice==1)
	insertStarting();
	if(choice==2)
	insertEnd();
	if(choice==3)
	insertAfter();
	if(choice==4)
	insertBefore();
	
}
void insertStarting()
{	
	temp = (struct node*)malloc(sizeof(node));
	cout<<"Enter value you want to insert"<<endl;
	cin>>n;
	temp->data=n;
	if(head==NULL)
	{
		temp->next=temp;
		head=temp;
	}
	else
	{
		list=head;
		while(list->next!=head)
		{
			list=list->next;
		}		
		list->next=temp;
		temp->next=head;
		head=temp; 
		total++;
	}
}

void insertEnd()
{
		temp = (struct node*)malloc(sizeof(node));
		cout<<"Enter value you want to insert."<<endl;
		cin>>n;
		temp->data=n;
		temp->next=head;
		if(head==NULL)
		{
			head=temp;
			head->next=head;
		}
		else
		{
		list=head;
		while(list->next!=head)
		{
			list=list->next;
		}
		list->next=temp;
		total++;
		}
}

void insertAfter()
{
	if(head==NULL)
	{
		cout<<"--------------"<<endl;
		cout<<"List is Empty."<<endl;
		cout<<"--------------"<<endl;
	}
	else
	{
		list = (struct node*)malloc(sizeof(node));
		temp = (struct node*)malloc(sizeof(node));
		int n1;
		cout<<"Enter element you want to insert"<<endl;
		cin>>n;
		cout<<"Enter element after which you want to insert"<<endl;
		cin>>n1;
		if(search(n1))
		{
			temp->data=n;
			list=head;	
			while(list->data!=n1)
			{
				list=list->next;
			}
			temp->next=list->next;
			list->next=temp;
			total++;
		}
	}
}
void insertBefore()
{
	if(head==NULL)
	{
		cout<<"--------------"<<endl;
		cout<<"List is Empty."<<endl;
		cout<<"--------------"<<endl;
	}
	else
	{
		list = (struct node*)malloc(sizeof(node));
		temp = (struct node*)malloc(sizeof(node));
		int n1;
		cout<<"Enter element you want to insert"<<endl;
		cin>>n;
		cout<<"Enter element before which you want to insert"<<endl;
		cin>>n1;
		if(search(n1))
		{
			list=head;
			temp->data=n;
			if(head->data==n1)
			{
				last=head;
				while(last->next!=head)
				{
					last=last->next;
				}
				temp->next=list;
				last->next=temp;
				head=temp;
			}
			
			else
			{
				while(list->data!=n1)
				{
					last=list;
					list=list->next;
				}	
				temp->next=list;
				last->next=temp;
			}
			
			total++;
		}
	}
}
void del()
{
	cout<<"1. Delete from beginning \n2. Delete from end \n3. Delete a particular element."<<endl;
	cin>>choice;
	if(choice==1)
	deleteStarting();
	if(choice==2)
	deleteEnd();
	if(choice==3)
	deleteParticular();
}
void deleteStarting()
{
	if(head==NULL)
	{
		cout<<"List is empty."<<endl;
	}
	list = (struct node*)malloc(sizeof(node));
//	cout<<"Enter element you want to delete"<<endl;
//	cin>>n;
	n =  head->data;
	if(head->next==head)
	{
		free(head);
//		cout<<"here";
		head=NULL;
	}
	else
	{
		last=head;
		while(last->next!=head)
		{
			last=last->next;
		}
		last->next=head->next;
		free(head);
		head=last->next;
//		list = head->next;
//		free(head);
//		head= list;
	}
		cout<<"-----------"<<endl;
		cout<<n<<" Removed"<<endl;
		cout<<"-----------"<<endl;
		total--;
	
}

void deleteEnd()
{
	list = (struct node*)malloc(sizeof(node));
	list = head;
	if(head==NULL)
	{
		cout<<"List is empty."<<endl;
	}
	else
	{
		if(head->next==head)
		{
			n=head->data;
			free(head);
			head=NULL;
		}
		else
		{
			while(list->next!=head)
			{
				temp = list;
				list=list->next;
			}
			n=list->data;
			temp->next=head;
			free(list);
		}
		cout<<"-----------"<<endl;
		cout<<n<<" Removed"<<endl;
		cout<<"-----------"<<endl;
		total--;
	}
	
}

void deleteParticular()
{
	if(head==NULL)
	{
		cout<<"--------------"<<endl;
		cout<<"List is Empty."<<endl;
		cout<<"--------------"<<endl;
	}
	else
	{
		cout<<"Enter element you want to delete"<<endl;
		cin>>n;
		if(search(n))
		{
			if(head->next==head&&head->data==n)
			{
//				list=head;
//				list=list->next;
				free(head);
				head=NULL;
			}
			else if (head->data==n)
			{
				last=head;
				while(last->next!=head)
				{
					last=last->next;
				}
				last->next=head->next;
				free(head);
				head=last->next;
			}
			else
			{
				list = (struct node*)malloc(sizeof(node));
				list=head;
				last=list;
				while(list->data!=n)
				{
					last=list;
					list = list->next;
				}
				last->next=list->next;
				free(list);
			}	
			cout<<"-----------"<<endl;
			cout<<n<<" Removed"<<endl;
			cout<<"-----------"<<endl;
			total--;
		}
	}
		
}

void display()
{
	if(head==NULL)
	{
		cout<<"--------------"<<endl;
		cout<<"List is Empty."<<endl;
		cout<<"--------------"<<endl;
	}
	else
	{
	list = (struct node*)malloc(sizeof(node));
	list=head;
	while(list->next!=head)
	{
	cout<<"|"<<list->data<<"|--->"<<"|"<<list->next->data<<"|"<<endl;
	list=list->next;
	}
	cout<<"|"<<list->data<<"|"<<"--->"<<"|"<<list->next->data<<"|"<<endl;
	}
}

void sort()
{
	if(head==NULL)
	{
		cout<<"--------------"<<endl;
		cout<<"Can't sort, List is Empty."<<endl;
		cout<<"--------------"<<endl;
	}
	else
	{
	list=head;
	cout<<"list->data is "<<list->data<<" list->next->data is "<<list->next->data;
	for(int i=0;i<=total;i++)
	{
		for(int j =0;j<=total;j++)
		{
			if(list->data > list->next->data)
			{
				int temp_num;
				temp_num = list->data;
				list->data=list->next->data;
				list->next->data=temp_num;				
			}
			list=list->next;
			if(list->next==head)
				{
					list=head;
				}
		}
	}
	//	while(list->next!=NULL)
	//	{
	//		if(list->data > list->next->data)
	//		{
	//			int temp_num;
	//			temp_num = list->data;
	//			list->data=list->next->data;
	//			list->next->data=temp_num;
	//			list=list->next;
	//		}
	//	}
	}
}
void reverse()
{
	if(head==NULL)
	{
		cout<<"--------------"<<endl;
		cout<<"Can't sort, List is Empty."<<endl;
		cout<<"--------------"<<endl;
	}
	else
	{
	list=head;
	fix=head;
	last=NULL;
	temp=list->next;
	while(temp!=head)
	{
		last=list;
		list=temp;
		temp=temp->next;
		list->next=last;
	}
	head=list;
	fix->next=head;
	}
//	while(list->next!=null)
//	}
}

void count()
{
	
	if(head==NULL)
	{
		cout<<"--------------"<<endl;
		cout<<"List is Empty."<<endl;
		cout<<"--------------"<<endl;
	}
	else
	{
		cout<<"Count is "<<total+1<<endl;
	}
}
void search()
{
	if(head==NULL)
	{
		cout<<"--------------"<<endl;
		cout<<"List is Empty."<<endl;
		cout<<"--------------"<<endl;
	}
	else
	{
		cout<<"Enter element you want to search for "<<endl;
		cin>>n;
		int i=1;
		list=head;
		while(list->data!=n&&list->next!=head)
		{
			i++;
			list=list->next;
		}
		if(list->data!=n)
		{
			cout<<"No element found!!!"<<endl;
		}
		else
		{
		cout<<"Found element at position "<<i<<endl;
		}
	}
}
bool search(int n)
{
	if(head==NULL)
	{
		cout<<"--------------"<<endl;
		cout<<"List is Empty."<<endl;
		cout<<"--------------"<<endl;
		return false;
	}
	else
	{
//		cout<<"Enter element you want to search for "<<endl;
//		cin>>n;
		int i=1;
		list=head;
		while(list->data!=n&&list->next!=NULL)
		{
			i++;
			list=list->next;
		}
		if(list->data!=n)
		{
			cout<<"No element found!!!"<<endl;
			return false;
		}
		else
		{
		cout<<"Found element at position "<<i<<endl;
		return true;
		}
	}
}
};
int main()
{
	
	node n;
	operations o ; o.menu();
	return 0;
}
