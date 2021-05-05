#include <hash.h>
#include <iostream>

int main()
{
	Hash<int> h;
	h.insertKey(12);
	h.insertKey(74);
	cout<<h.findKey(75)<<"\n";
	return 0;
}
