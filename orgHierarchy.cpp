#include <orgHierarchy.h>

int main()
{
	orgTree<string> ot;
	ot.addElement("NULL","peter");
	ot.addElement("peter","sishir");
	ot.addElement("sishir","Raj");
	ot.addElement("sishir","Anitha");
	ot.addElement("Anitha","Dilip");
	cout<<boolalpha<< ot.isPeer("Raj","sishir") <<"\n";
	cout<<boolalpha<< ot.isManager("Raj","Dilip") <<"\n";
	return 0;
}
