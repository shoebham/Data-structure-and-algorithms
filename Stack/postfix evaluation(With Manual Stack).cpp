#include<iostream>
#include<vector>
#include<sstream>
using namespace std;


class stack
{
public:
	int top,currentSize=0;
	float arr[100];
	stack()
	{
		top=-1;
		
		
	}
	void push(float n)
	{
		if(top==99)
		{
			cout<<"Overflow"<<endl;
		}
		else 
		{
			top++;
			arr[top] = n;
			currentSize++;
		}
	}
	void pop()
	{
		if(top==-1){cout<<"Underflow"<<endl;
		}
		else{
			top--;
			currentSize--;
		}
	}
	float getTop()
	{
		return arr[top];
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
				cout<<arr[i]<<" ";			
		}
		cout<<endl;
		
	}
};


float performCalc(float a,float b,string oper)
{
	switch(oper[0])
	{
		case '+':
			return a+b;
			break;
		case '-':
			return b-a;
			break;
		case '*':
			return a*b;
			break;
		case '/':
			return b/a;
			break;
		default:
			return 0;
			break;
	}
}

bool isNum(string s)
{
	
	if(s[0]=='1'||s[0]=='2'||s[0]=='3'||s[0]=='4'||s[0]=='5'||s[0]=='6'||s[0]=='7'||s[0]=='8'||s[0]=='9'||s[0]=='0'){

		return true;
	}
	return false;
}

bool isOperator(string s)
{
	if(s[0]=='*'||s[0]=='+'||s[0]=='-'||s[0]=='/')
	{
		return true;
	}
	return false;
}
int main()
{
	
//	string str = "5 6 2 + * 12 4 / -";
	string str;
	bool invalid;
	cout<<"Enter postfix expression seperated by spaces:- "<<endl;
	getline(cin,str);
	str +=" )";
	string arr_of_str[str.length()];

	stack stk;	
	for(int i=0,j=0;i<str.length();i++) 
	{
		if(str[i] == ' ')
		{
		j++;
		continue;
		}
		arr_of_str[j] += str[i];
	}
	int i=0;
	while(arr_of_str[i]!=")")
	{

		if(isNum(arr_of_str[i]))
		{
			string s = arr_of_str[i];
			stringstream ss(s);
			float x;
			ss>>x;
			stk.push(x);
		}
		else if(isOperator(arr_of_str[i])&&stk.top!=0)
		{
			float a,b;
			a=stk.getTop();
			stk.pop();
//			cout<<"a is "<<a<<endl;
			b=stk.getTop();
			stk.pop();
//			cout<<"b is "<<b<<endl;
			float res = performCalc(a,b,arr_of_str[i]);
			stk.push(res);
//			cout<<"stk size is "<<stk.top<<endl;
		}
		else {invalid=true;break;
		}
		i++;
		stk.display();
//		if(invalid){cout<<"Invalid Expression"<<endl;break;
//		}
	}
	if(stk.top==0&&arr_of_str[i]==")"){
		cout<<"Result is "<<stk.getTop()<<endl;
		stk.pop();
	}
	else
	{
		cout<<"Invalid expression"<<endl;
	}
	return 0;
}
//5 3 7 9 + +
//4 2 3 5 1 - + * + *
//4 2 + 3 5 1 - * +
