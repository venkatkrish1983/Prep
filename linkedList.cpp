#include <linkedList.h>

int main()
{
	linkedList<int> ll;
	ll.addElement(2);
	ll.addElement(18);
	ll.addElement(33);
	ll.addElement(7);
	ll.addElement(12);
	ll.deleteElement(11);
	ll.display();
        cout<<ll.size()<<"\n";
	cout<<boolalpha<<ll.isEmpty()<<"\n";
	ll.reverse();
	ll.display();

	return 0;
}
