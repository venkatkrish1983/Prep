#include <DLL.h>

int main()
{
	DLL<int> dl;
	dl.addElement(19);
	dl.addElement(27);
	dl.addElement(12);
	dl.addElement(1);
	dl.addElement(51);
	dl.deleteElement(12);
	dl.display();
	cout<<dl.length()<<"\n";
	cout<<boolalpha<<dl.isEmpty()<<"\n";
	return 0;
}
