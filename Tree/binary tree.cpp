#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int value)
	{
		data=value;
		left=right=NULL;
	}
}; struct Node *temp,*start,*temp1,*current,*parent,*root;

class stack
{
	public:
	int top=-1,size,input;
	int arr[100];
	
	void push(int num)
	{
		if(top == 99)
		{
			cout<<"Overflow, Stack is full!!"<<endl;
		}
		else {
			top = top+1;
			arr[top]=num;
		}
	}
	
	int pop()
	{
		if(top==-1){
			cout <<"Underflow, Stack is empty!!"<<endl;
		}
		else 
		{
			int n = arr[top];
			top=top-1;
//			cout<<n<<" removed."<<endl;
			return n;
		}
	}
	bool empty()
	{
		if(top==-1)
		return true;
		else
		return false;
	}
	void display()
	{
		if(top==-1){cout<<"Stack is empty!!"<<endl;
		}
		else{
			cout<<"Your stack looks like:"<<endl;
			cout <<"---"<<endl;
			for(int i=top;i>=0;i--){
				cout<<"|"<<arr[i]<<"|"<<endl;
				cout <<"---"<<endl;
			}
			
		}
	}
};
class tree
{
	public:
	vector<int> arr;
	int choice;
	
	int size;
	tree()
	{
		menu();
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
	
	void menu()
	{
		do 
		{
		cout<<"Enter what would you like to do\n1.Insert in tree\n2.Delete from tree\n3.Inorder Traversal\n4.Preorder Traversal\n5.Postorder Traversal\n6.Exit\n";
		cin>>choice;

		switch(choice)
		{
			case 1:
				insert_tree();
				break;
				
			case 2:
				delete_tree();
				break;
				
			case 3:
				inorder();
				break;
				
			case 4:
				preorder();
				break;
				
			case 5:
				postorder();
				break;
				
			case 6:
				cout<<"Bye.\n";
				break;

		}		}while(choice!=6);
	}
	void insert_tree()
	{
		int n;
		cout<<"Enter value to insert"<<endl;
		cin>>n;
		insert(n);
	}
	void delete_tree()
	{
		
		if(start==NULL)
		{
			cout<<"Tree is empty!!"<<endl;
		}
		else
		{
			int n;
			cout<<"Enter value to delete"<<endl;
			cin>>n;
			deleteNode(n);
		}
	}
	
	Node* find(int n)
	{
		temp=start;
		
		while(temp->data!=n)
		{
			if(temp->data>n)
			temp=temp->left;
			else
			temp=temp->right;
		}
		return temp;
	}
	void inorder()
	{
		if(start==NULL)
		{
			cout<<"Tree is empty!!"<<endl;
		}
		else
		{
			temp=start;
			parent=NULL;
			vector<int> res;
			stack stk;
			while(temp!=NULL||!stk.empty())
			{
				while(temp!=NULL)
				{
					parent =temp;
					stk.push(temp->data);
					temp=temp->left;	
				}
						int num=stk.pop();
						res.push_back(num);
						parent=find(num);
						temp=parent->right;
				}
			
			cout<<"Inorder: "<<endl;
			display_res(res);
		}
	}
	void preorder()
	{
		
		if(start==NULL)
		{
			cout<<"Tree is empty!!"<<endl;
		}
		else
		{
			stack stk;
			vector<int> res;
			temp=start;
			stk.push(temp->data);	
			while(!stk.empty())
			{
	//			stk.display();
				int num = stk.pop();
				res.push_back(num);
				temp=find(num);
				if(temp->right!=NULL)
				stk.push(temp->right->data);
				if (temp->left!=NULL)
				stk.push(temp->left->data);
			}
			cout<<"Preorder: "<<endl;
			display_res(res);
		}
	}
	void postorder()
	{
		
		if(start==NULL)
		{
			cout<<"Tree is empty!!"<<endl;
		}
		else
		{
			stack stk;
			vector<int> res;
			temp=start;
			temp1=NULL;
			while(!stk.empty()||temp!=NULL)
			{
				if(temp!=NULL)
				{
					stk.push(temp->data);
					temp=temp->left;
				}
				else
				{
					
					int top=stk.pop();
					stk.push(top);
					temp=find(top);
					if(temp->right!=NULL&&temp->right!=temp1)
					{
						temp=temp->right;
					}
					else
					{
						res.push_back(temp->data);
						temp1=find(stk.pop());	
						temp=NULL;			
					}
				}
			}
			cout<<"Postorder:"<<endl;
			display_res(res);
		}
	}
	void display_res(vector<int> res)
	{
		for(auto x:res)
		{
			cout<<x<<" "; 
		}
		cout<<endl;
	}
	void insert(int value)
	{

		
			if(start==NULL)
			{
				start=new Node(value);		
				temp=start;
				temp1=NULL;
			}
			else if(check_dup(value))
			{
				cout<<"Element already present. Try again\n";
			}
			else
			{
				temp=start;
				temp1=NULL;
				if(temp==NULL)	
				{
					
				temp->data=value;
				temp->left=NULL;
				temp->right=NULL;
				}
			while(temp!=NULL)
			{
				temp1=temp;
				if(value<temp->data)
				temp=temp->left;
				else
				temp=temp->right;
			}
	
			if(temp1->data>value)
			(temp1->left)= new Node(value);
			
			if(temp1->data<value)
			(temp1->right) = new Node(value);
		}
	}
	
	
	void deleteNode(int value)
	{
		
		temp=start;
		parent=NULL;
		while(temp->data!=value&&temp!=NULL)
		{
			cout<<"here";	
			parent =temp;
			if(temp->data>value)
			temp=temp->left;
			else if (temp->data<value)
			temp=temp->right;
		}
		if(temp==NULL)
		{
			cout<<"Element not found"<<endl;
		}
		
		//if leaf 
		else if(temp->right==NULL&&temp->left==NULL)
		{
			if(parent==NULL)
			{
//				cout<<"temp->data s" <<temp->data;
				delete temp;
				start=NULL;
				cout<<"Tree is empty now"<<endl;
				return;
			}
				
			else if(temp->data>parent->data)
				parent->right=NULL;
			else if (temp->data<parent->data)
				parent->left=NULL;
			delete temp;
		}
		//if 1 child
		else if (temp->right==NULL||temp->left==NULL)
		{
//			cout<<"parent"<<endl;
//			cout<<parent->data;
			if(parent==NULL)
			{
				if(temp->right!=NULL)
					start=temp->right;
				else if(temp->left!=NULL)
					start=temp->left;	
//				start=temp->right;
//				delete temp;
			}
			else if(temp->data>parent->data)
			{
				if(temp->left!=NULL)
				parent->right=temp->left;	
				else
				parent->right=temp->right;
			}
			else if (temp->data<parent->data)
			{
				if(temp->left!=NULL)
				parent->left=temp->left;	
				else
				parent->left=temp->right;
			}
			delete temp;
		}
		//if 2 child
		else
		{	cout<<"temp->data"<<temp->data;
			
			Node* parent_min=NULL;
			temp1=temp->right;
			while(temp1->left!=NULL)
			{
				parent_min=temp1;
				temp1=temp1->left;
			}
			
			if(parent_min!=NULL)
			parent_min->left=temp1->right;
			else
			temp->right=temp1->right;
			
			temp->data=temp1->data;
//			cout<<"temp1->data"<<temp1->data;
			delete temp1;
		}


	}
	



	bool check_dup(int n)
	{
		temp=start;
		while(temp->data!=n)
		{
			if(temp->data>n)
			temp=temp->left;
			else if(temp->data<n)
			temp=temp->right;
						
			if (temp==NULL)
			return false;
		}
		if(temp==NULL)
		return false;
		else
		return true;
	}

	
	
	

};

int main()
{
	tree t;
	return 0;
	
}
