#include <bst.h>

int main()
{
	bst<int> bs;
	bs.insertKey(20);
	bs.insertKey(17);
	bs.insertKey(18);
	bs.insertKey(37);
	bs.deleteKey(18);
	bs.inOrder();
	return 0;
}
