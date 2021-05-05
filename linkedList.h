#include <iostream>
using namespace std;

template <class T>
class linkedListADT
{
	public:
	 virtual void addElement(T elem) = 0;
	 virtual void deleteElement(T elem) = 0;
	 virtual void display() const = 0;
	 virtual bool isEmpty() const  = 0;
	 virtual int size() const = 0;
};

template <class T>
struct node
{
	T data;
	node* next;
	node(T elem):data(elem),next(NULL){}
};

template <class T>
class linkedList:public linkedListADT<T>
{
	node<T>* head;
	int _size;
	public:
		linkedList():head(NULL),_size(0){}
		~linkedList();
		void addElement(T elem);
		void deleteElement( T elem);
		void display() const;
		bool isEmpty() const;
		int size() const;
		void reverse();
		node<T>* reverse(node<T>* ptr);
};

template <class T>
void linkedList<T>::addElement(T elem)
{
	node<T>* ptr = new node<T>(elem);
	node<T>* t = head;
	while(t && t->next)
	{
		t=t->next;
	}
	if(t)
	{
		t->next = ptr;
	}
	else
	{
		head = ptr;
	}
	++_size;
}

template <class T>
void linkedList<T>::deleteElement(T elem)
{
 node<T>* p = head;
 node<T>* q = NULL;
 while(p && p->data != elem)
 {
	 q = p;
	 p = p->next;
 }
 if(p)
 {
	if(q)
		q->next = p->next;
	else
		head = head->next;
	delete p;
	p = NULL;
 }
}

template <class T>
void linkedList<T>::display() const
{
	node<T>* ptr = head;
	while(ptr)
	{
		cout<<ptr->data << "\n";
		ptr = ptr->next;
	}
}

template <class T>
bool linkedList<T>::isEmpty() const
{
	return head?false:true;
}

template <class T>
int linkedList<T>::size() const
{
	return _size;
}

template <class T>
linkedList<T>::~linkedList()
{
	node<T>* ptr = head;
	while(ptr)
	{
		head = head->next;
		delete ptr;
		ptr = head;
	}
}

/*template <class T>
void linkedList<T>::reverse()
{
	node<T>* p ,*q ;
	p = q = head;
	node<T>* r = NULL;
	while(p)
	{
		p = p->next;
		q->next = r;
		r = q;
		q = p;
	}
	head = r;

}*/

//Reverse recursively
//
//reverse using 2 pointers alone
template <class T>
void linkedList<T>::reverse()
{
	reverse(head);
}

template <class T>
node<T>* linkedList<T>::reverse(node<T>* p)
{
	cout<<"calling reverse"<<"\n";

	if(p->next)
	{
		node<T>* ptr = reverse(p->next);
		ptr->next = p;
		p->next = NULL;
	}
	else
	{
		head = p;
		return p;
	}
}	

