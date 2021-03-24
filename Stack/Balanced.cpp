#include <iostream>
using namespace std;


class stack{
	public:
	int top;
	char arr[50];
	stack()
	{
		top = -1;	
	}
	
	void push(char c)
	{

		
		if(top==49)
		{
			cout<<"Overflow"<<endl;
		}
		else
		{
			top++;
			arr[top]=c;
		}
	}
	int pop()
	{
		if(top==-1)
		{
//			cout<<"Underflow"<<endl;
			return 1;
		}
		else
		{
			char c = arr[top];
			top--;
		}
	}
	void display()
	{
		if(top==-1){cout<<"Stack is empty!!"<<endl;
		}
		for(int i =0;i<top;i++){
			cout<<arr[i]<<endl;
		}
	}
};

int main()
{
	
	string s;
	cout<<"Enter a expression to check whether its brackets are balanced or not"<<endl;
	cin>>s;
	stack stk;
	bool balanced;
	for(int i=0;i<s.length();i++)
	{
		if(s[0] == ')')
		{
			cout<<"Expression invalid";
			break;
		}
		else if(s[i]=='(')
		{
			stk.push(s[i]);		
		}
		else if(s[i]==')')
		{
//			stk.pop();
			if(stk.pop()==1)
			{
				cout<<"Unbalanced Expression"<<endl;
				balanced = false;	
				break;
			}
			balanced = true;
		}	
	}	
		if(balanced && stk.top==-1)
		{
			cout<<"balanced expression";
		}
		else if (stk.top!=-1){
			cout<<"unbalanced expression";
		}
		
}
