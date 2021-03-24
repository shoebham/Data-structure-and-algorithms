#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void displayStack(stack<int> s)
{
while (!s.empty()) 
    { 
        cout<<s.top()<<" "; 
        s.pop(); 
    } 
    cout << '\n'; 
}

int performCalc(int a,int b,string oper)
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
int main()
{
	stack<int> stk;
	int result;
	vector<string> str{"5","6","2","+","*","12","4","/","-"};
	str.push_back(")");
	int i=0;
		while(str[i]!=")")
		{
			displayStack(stk);
			if(isdigit(str[i][0]))
			{
				int x = stoi(str[i]);
				cout<<"i am in if"<<endl;
				cout<<"pushing "<<str[i]<<endl;
				stk.push(x);
				cout<<"-------------"<<endl;
				cout<<"stk top is "<<stk.top()<<endl;
			}
			else if (str[i] =="*"||str[i]=="+"||str[i]=="/"||str[i]=="-")
			{
				cout<<"i am in else if"<<endl;
				int a,b,res;
				a = stk.top();
				stk.pop();
				b=stk.top();
				stk.pop();
				res = performCalc(a,b,str[i]);
				cout<<"res is "<<res<<endl;
				stk.push(res);
				cout<<"-------------"<<endl;

				
			}
		i++;	
//		if(str[i]==")"){cout<<"str is ) here"<<endl;
//		}
	}
	
	return 0;
}
