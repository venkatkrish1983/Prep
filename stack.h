//custom exception class for stack Empty exception
#include <exception>
#include <iostream>
using namespace std;

class stackEmptyException:public exception
{
	public:
		const char* what() const noexcept
		{
			return "stack empty";
		}

};

//interface class 
template <class T>
class stackADT
{
	public:
		virtual void push(T elem) = 0;
		virtual void pop() throw (stackEmptyException) = 0;	
		virtual T top() const throw (stackEmptyException) = 0;
		//helper functions
		virtual bool isEmpty() const = 0;
		virtual int size() const = 0;
};

template <class T>
struct node
{
	T data;
	node* next;
	node(T elem):data(elem),next(NULL){}	
};

// how to use allocator
// also check for memory deallocation if done properly using valgrind
template <class T>
class stack:public stackADT<T>
{
	node<T>* _top = NULL;
	int _size = 0; //how to use default values for variables 
	public:
	stack():_top(NULL),_size(0){}
	~stack();
	void push(T elem);
	void pop() throw (stackEmptyException);
	T top() const throw (stackEmptyException);
	bool isEmpty() const;
	int size() const;
};

template <class T>
void stack<T>::push(T elem)
{
	node<T>* ptr = new node<T>(elem);
	ptr->next = _top;
	_top = ptr;
	++_size; //use pre increment as post increment creates temp object
}

template <class T>
void stack<T>::pop() throw (stackEmptyException)
{
	if(!_top)
		throw stackEmptyException();//anonymous object
	node<T>* ptr = _top;
	_top = _top->next;
	delete ptr;
	--_size;
}
//Partial template specialisation
template <class T>
T stack<T>::top() const throw (stackEmptyException)
{
	if(!_top)
		throw stackEmptyException();
	return _top->data;
}

template <class T>
bool stack<T>::isEmpty() const
{
	return _top?false:true;
}

template <class T>
int stack<T>::size() const
{
	return _size;
}

template <class T>
stack<T>::~stack() //can we make destructor const??
{
	node<T>* ptr = _top;
	while(ptr)
	{
		_top = _top->next;
		delete ptr;
		ptr = _top;
	}
}
