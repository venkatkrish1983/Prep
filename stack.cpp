#include "stack.h"

int main()
{
        stack<int> s;
        s.push(12);
        s.push(17);
        s.push(39);
        s.pop();
        cout<<"Top element is " << s.Top()<<"\n";
        cout<<"Size of stack is " <<s.Size()<<"\n";
        cout<<"stack is " <<s.empty()<<"\n";
        return 0;
}
