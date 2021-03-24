#include<iostream>
#include<stack>
using namespace std;

string displayStack(stack<char> s)
{
stack<char> temp;
string str;

	while(!s.empty()){
		temp.push(s.top());
		s.pop();
	}
	while(!temp.empty())
	{
		str+= temp.top();
		temp.pop();
	}
	return str;
}
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
char operand(char c)
{
	if(c>='a'&&c>='z')
	{
		return c;
	}
	if(c>='A'&&c>='Z'){
		return c;
	}
	if(c>='0'&&c>='9')
	{
		return c;
	}
}
int main()
{
	
				
	//	A+(B*C-(D/E^F)*G)*H
	stack<char> stk;
	string p;
//	string str = "A+(B*C-(D/E^F)*G)*H";
	string str;
	cout<<"Enter a infix expression to convert to postfix expression"<<endl;
	cin>>str;
	stk.push('(');
	str[str.length()] += ')';
	cout<<"str is "<<str<<endl;
//	cout<<"stk top is "<<stk.top()<<endl;
	cout<<"string\tstack\tresult"<<endl;
	while(!stk.empty())
	{
		for(int i=0;i<=str.length();i++)
		{
//			cout<<"p on ["<<i<<"] iteration "<<p<<endl;

			switch(str[i])
			{
				case '*': case '/': case '-' : case '+': case '^':
//					cout<<"i is "<<i<<endl;
//					cout<<"stk top is "<<stk.top()<<endl;
					char c;
					c = stk.top();
//					cout<<"c is "<<c<<endl;
					if((priority(c)>=priority(str[i]))&&c!='(')
					{
					p+=c;
					stk.pop();
					stk.push(str[i]);
//					cout<<p;
					}
					else if(priority(c)<priority(str[i])&&c!='('){
						stk.push(str[i]);
					}
					else if (c=='(')
					{
						stk.push(str[i]);
					}
				break;
				case ')':
//					cout<<"str["<<i<<"] "<<str[i]<<endl;
//					cout<<"c is "<<c<<endl;
					c=stk.top();
				
					while(c!='(')
					{
					
//					cout<<"c = "<<c<<endl;	
					p+=c;
					stk.pop();
					c= stk.top();
					if(c=='(')
					{
//						cout<<"i am in if";
						stk.pop();
					}
//					cout<<p;
					}
					break;
				case '(':
					stk.push(str[i]);
					break;
				default:
					p+=str[i];
//					cout<<str[i];
					break;
			}
			cout<<str[i]<<"\t"<<displayStack(stk)<<"\t"<<p<<endl;
		}
		
//		cout<<p;
	}

	return 0;
}
