#include <iostream>
#include <queue>
using namespace std;

template <class T>
struct node
{
	T data;
	node* parent;
	node* leftchild;
	node* sibling;
	node(T elem):data(elem),parent(NULL),leftchild(NULL),sibling(NULL){}
};

template <class T>
class orgTree
{
	node<T>* root;
	public:
	orgTree():root(NULL){}
	~orgTree();
	bool isPeer(T a,T b);
	bool isManager(T a,T b);
	void addElement(T mgr,T elem);
	void deleteElement(T elem);
	node<T>* findElement(T elem);
};

template <class T>
bool orgTree<T>::isPeer(T a , T b)
{
	node<T>* p1 = findElement(a);
	node<T>* p2 = findElement(b);
	return p1->parent == p2->parent ? true:false;
}

template <class T>
bool orgTree<T>::isManager(T a, T b)
{
	node<T>* p1 = findElement(a);
	node<T>* p2 = findElement(b);
	while(p2 && p2->parent != p1)
	{
		p2 = p2->parent;
	}
	return p2 ? true: false;
}

template <class T>
orgTree<T>::~orgTree()
{
	queue<node<T>*> q;
	node<T>* ptr = root;
	q.push(ptr);
	while(!q.empty())
	{
		node<T>* p  = q.front();
		node<T>* ch = p->leftchild;
		while(ch)
		{
			q.push(ch);
			ch = ch->sibling;
		}
		q.pop();
		delete p;
		p = NULL;
	}
}

template <class T>
void orgTree<T>::addElement(T mgr,T elem)
{
	node<T>* ptr = findElement(mgr);
	node<T>* p = new node<T>(elem);
	p->parent = ptr;
	if(ptr)
	{
		p->sibling = ptr->leftchild;
		ptr->leftchild = p;
	}
	else
	{
		root = p;
	}
}

template <class T>
void orgTree<T>::deleteElement(T elem)
{
		

}

template <class T>
node<T>* orgTree<T>::findElement(T elem)
{
	//breadth first search traversal
	node<T>* ptr = root;
	queue<node<T>* > q;
	if(ptr)
	q.push(ptr);
	while(!q.empty() && q.front()->data != elem)
	{
		node<T>* p = q.front()->leftchild;
		while(p)
		{
			q.push(p);
			p = p->sibling;
		}
		q.pop();
	}
	return q.empty() ? NULL : q.front();
}
