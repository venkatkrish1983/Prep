#include <iostream>
using namespace std;

template <class T>
class DLLADT
{
	public:
		virtual	void addElement(T elem) = 0;
		virtual void deleteElement(T elem) = 0;
		virtual void display() const = 0;
		virtual int length() = 0;
		virtual bool isEmpty() const = 0;	
};

template <class T>
struct node
{
	T data;
	node* prev;
	node* next;
	node(T elem):data(elem),prev(NULL),next(NULL){}
};

template <class T>
class DLL:public DLLADT<T>
{
	node<T>* head;
	public:
	void addElement(T elem);
	void deleteElement(T elem);
	void display() const;
	int length() ;
	bool isEmpty() const;
	int length(node<T>* p);
};

template <class T>
void DLL<T>::addElement(T elem)
{
	node<T>* ptr = new node<T>(elem);
	ptr->next = head;
	head = ptr;
	if(head->next)
	head->next->prev = head;
}

template <class T>
void DLL<T>::deleteElement(T elem)
{
	node<T>* ptr = head;
	while(ptr && ptr->data != elem)
	{
		ptr = ptr->next;
	}
	if(ptr)
	{
		if(ptr->prev)
		ptr->prev->next = ptr->next;
		else
		{
			head = head->next;
			head->prev = NULL;
		}
		if(ptr->next)
		ptr->next->prev = ptr->prev;
		else
			ptr->prev->next = NULL;
		delete ptr;
		ptr = NULL;
	}
}

template <class T>
void DLL<T>::display() const
{
	node<T>* ptr = head;
	while(ptr )
	{
		cout<<ptr->data<<"\n";
		ptr = ptr->next;
	}
}

template <class T>
bool DLL<T>::isEmpty() const
{
	return head?false:true;
}

template <class T>
int DLL<T>::length() 
{
	//using recursion
	node<T>* ptr = head;
	return length(ptr);
}

template <class T>
int DLL<T>::length(node<T>* p)
{
	if(p)
	return 1+length(p->next);
	else
		return 0;
}


