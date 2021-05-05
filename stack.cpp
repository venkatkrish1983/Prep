#include <stack.h> // add the path in the include path
#include <string>
int main()
{
	stack<string> st;
	st.push("main");
	st.push("function1");
	st.push("function2");
	st.pop();
	st.pop();
	cout<<"Top function is " << st.top()<<"\n";
	return 0;
}
