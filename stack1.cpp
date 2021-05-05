//Given a stack S and another empty stack T and a variable v, write a function that returns S but with its elements reversed.
//
//
#include <stack>
#include <iostream>
using namespace std;

void reverseStack(stack<int> &st)
{
	//complexity is O(n2)
	stack<int> t;
	int v;
	for(int i=0;i<st.size()-1;i++)
	{
		v = st.top();
		st.pop();
		while(st.size()-i)
		{
			t.push(st.top());
			st.pop();
		}
		st.push(v);
		while(!t.empty())
		{
			st.push(t.top());
			t.pop();
		}
	}
}

int main()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	reverseStack(st);
	while(!st.empty())
	{
		cout<<st.top()<<"\n";
		st.pop();
	}
	return 0;
}
