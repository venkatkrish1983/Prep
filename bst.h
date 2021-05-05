#include <iostream>
#include <queue>
using namespace std;
 //this is a ordered map where two keys can be compared

template <class T>
class bstADT
{
	public:
		virtual void insertKey(T key) = 0;
		virtual void deleteKey(T key) = 0;
		virtual T findKey(T key) const = 0;	
};

template <class T>
struct node
{
	T data;
	node* left;
	node* right;
	node(T elem):data(elem),left(NULL),right(NULL) {}//can we use nullptr
};

template <class T>
class bst:public bstADT<T>
{
	node<T>* root;
	public:
	bst():root(NULL){}
	~bst();
	void insertKey(T key);
	void deleteKey(T key);
	T findKey(T key) const{}
	void inOrder() ;
	void inOrder(node<T>* p) ;
	node<T>* findParent(T val);
	node<T>* inorderSuccessor(T key);
};

template <class T>
void bst<T>::insertKey(T key)
{
	node<T>* ptr = new node<T>(key);
	node<T>* p = root;
	node<T>* q = NULL;
	while(p)
	{
		q = p;
		if(p->data > key) //Assume all keys are unique.how do we handle equal keys
			p = p->left;
		else
			p = p->right;
	}
	if(!q)
		root = ptr;
	else
	{
		if(q->data > key)
			q->left = ptr;
		else
			q->right = ptr;
	}
}

template <class T>
void bst<T>::inOrder() //can this function be made const
{
	node<T>* ptr = root;
	inOrder(ptr);
}

template <class T>
void bst<T>::inOrder(node<T>* p)
{
	if(p)
	{
		inOrder(p->left);
		cout<<p->data<<"\n";
		inOrder(p->right);
	}
}

template <class T>
bst<T>::~bst()
{
	node<T>* p = root;
	queue<node<T>*> q;
	q.push(p);
	node<T>* ptr;
	while(!q.empty())
	{
		ptr = q.front();
		if(ptr->left)
			q.push(ptr->left);
		if(ptr->right)
			q.push(ptr->right);
		q.pop();
		cout<<"freeing here \n";
		delete ptr;
		ptr = NULL;
	}
}

//handle all 3 cases
// leaf node ,single & 2 node
template <class T>
void  bst<T>::deleteKey(T key)
{
	node<T>* parent = findParent(key);
	if(parent)
	{
		node<T>* child = parent->data > key ? parent->left: parent->right;
		if(!child->left && !child->right )
		{
			if(child->data > parent->data)
				parent->right = NULL;
			else
				parent->left = NULL;
			delete child;
			child = NULL;
		}
		else if(!child->left)
		{
			if(parent->data > child->data)
				parent->left = child->right;
			else
				parent->right = child->right;
			delete child;
			child = NULL;
		}
		else if(!child->right)
		{
			if(parent->data > child->data)
				parent->left =child->left;
			else
				parent->right = child->left;
			delete child;
			child = NULL;

		}
		else
		{
			//find inorder successor
			node<T>* isucc = inorderSuccessor(child->data);
			T val = isucc->data;
			deleteKey(val);
			child->data = val;
		}
	}
}
template <class T>
node<T>* bst<T>::findParent(T key)
{
	node<T>* p = root;
	node<T>* parent = NULL;
	while(p && p->data != key)
	{
		parent = p;
		if(p->data > key)
			p = p->left;
		else
			p = p->right;

	}
	return p ? parent: NULL;
}

template <class T>
node<T>* bst<T>::inorderSuccessor(T key)
{
  return new node<T>(key);
}



//find Key

//Level order
//inorder successor
//inorder predecessor
