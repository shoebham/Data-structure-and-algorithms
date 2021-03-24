#include <iostream>
using namespace std;

class stack
{
public:
	int top,currentSize;
	char arr[50];
	stack()
	{
		top=-1;
		currentSize=0;
	}
	void push(char c)
	{
		if(top>=49)
		{
			cout<<"Overflow"<<endl;
		}
		else 
		{
			top++;
			arr[top] = c;
			currentSize++;
		}
	}
	
	char pop()
	{
		if(top==-1){cout<<"Underflow"<<endl;
		}
		else{
			char c =arr[top];
			top--;
			currentSize--;
			return c;
		}
	}

	
	bool empty()
	{
		if(currentSize==0){return true;
		}
		else{return false;
		}
	}
	
	void display()
	{
			
			for(int i=0;i<=top;i++){
				cout<<arr[i];			
		}
		cout<<endl;
	}
};


int priority(char op)
{
	if (op=='^')
	{
		return 3;
	}
	else if (op=='*'||op=='/')
	{
		return 2;
	}
	else if(op=='+'||op=='-')
	{
		return 1;
	}
}
bool isOperand(char c)
{

	if((c>='a'&&c<='z'))
	{
		return true;
	}
	if((c >= 'A' &&c<='Z'))
	{
		return true;	
	}
	return false;
}

bool isOperator(char c)
{
	if(c=='*'||c=='-'||c=='+'||c=='/'||c=='^')
	{
		return true;
	}
	else{
	
	return false;
	}
}

int main()
{
	string p;
//	string str = "A+(B*C-(D/E^F)*G)*H";
	string str;
	cout<<"Enter a infix expression to convert to postfix expression"<<endl;
	cin>>str;
	stack stk;
	stk.push('(');
	str[str.length()] += ')';
	cout<<endl;
	if(str[0]==')')
	{
		cout<<"Invalid expression";
		return 0;
	}
	cout<<"string\tresult\tstack"<<endl;
	int i=0;
	char c;
	while(!stk.empty()&&i<=str.length())
	{
	
			switch(str[i])
			{
				case '*': case '/': case '-' : case '+': case '^':
					c = stk.pop();
					while((priority(c)>=priority(str[i]))&&c!='(')
					{
					p+=c;
					c=stk.pop();
					}					
					stk.push(c);
					stk.push(str[i]);

				break;
				case ')':
					c=stk.pop();
					while(c!='(')
					{
					p+=c;
					c=stk.pop();
					}
					break;
				case '(':
					stk.push(str[i]);
					break;
				default:
					if(isOperand(str[i]))
					{
						p+=str[i];
						break;
					}
					else
					{
						cout<<"Something is wrong,please check your expression"<<endl;
						break;
					}
					break;
			}	
			cout<<str[i]<<"\t"<<p<<"\t";
			stk.display();	
		i++;

	}
cout<<"\nresult is "<<p<<endl;
	return 0;
}







			
	

