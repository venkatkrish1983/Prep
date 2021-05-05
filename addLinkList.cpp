
//Given two linked list with numbers ..Add them ..Donot reverese the LL
//
#include <linkedList.h>

linkedList<int> add(node<T>* h1,node<T>* h2)
{
	node<T>* p = h1;
	int len1 = 0;
	int len2 = 0;
	while(p)
	{
		++len1;
		p = p->next;
	}
	node<T>* q = h2;
	while(q)
	{
		++len2;
		q = q->next;
	}
	if( len1 == len2)
	{
		addNode(h1,h2);
	}
	else if(len1 > len2)
	{
		p = h1;
		for(int i=0;i<len1-len2;i++)
		{
			p=p->next;
		}
		addNode(p,h2);
	}
	else
	{
		q = h2;
		for(int i=0;i<len2-len1;i++)
		{
			q=q->next;
		}
		addNode(h1,q);
	}
}

int main()
{
	linkedList<int> l1;
	linkedList<int> l2;
	l1.addElement(1);
	l1.addElement(2);
	l1.addElement(3);
	l1.addElement(7);
	l2.addElement(2);
	l2.addElement(9);
	linkedList<int> l3 = add(l1.getHead(), l2.getHead());
	l3.display();

	return 0;
}

