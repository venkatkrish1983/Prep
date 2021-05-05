#include <exception>
#include <iostream>
using namespace std;

class queueEmptyException:public exception
{
	public:
		const char* what() const noexcept
		{
			return "queue Empty";
		}
};


template <class T>
class queueADT
{
	public:
		virtual void enqueue(T elem) = 0;
		virtual void dequeue() throw (queueEmptyException) = 0;
		virtual T front() const throw (queueEmptyException) = 0;
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

template <class T>
class queue:public queueADT<T>
{
	node<T>* _front;
	node<T>* tail;
	int _size;
	public:
		queue():_front(NULL),tail(NULL),_size(0){}	
		~queue();
		void enqueue(T elem);
		void dequeue() throw(queueEmptyException);
		T front() const throw (queueEmptyException);
		int size() const;
		bool isEmpty() const;
};

template <class T>
void queue<T>::enqueue(T elem)
{
  node<T>* ptr = new node<T>(elem);
  if(tail)
  {
	  tail->next = ptr;
	  tail = ptr;
  }
  else
	  _front = tail = ptr;
	++_size;
}

template <class T>
void queue<T>::dequeue() throw (queueEmptyException)
{
	if(!_front)
		throw queueEmptyException();
	node<T>* ptr = _front;
	_front = _front->next;
	delete ptr;
	ptr = NULL;
	if(!_front)
		tail = NULL;
	--_size;
}

template <class T>
int queue<T>::size() const
{
	return _size;
}

template <class T>
bool queue<T>::isEmpty() const
{
	return _front?false:true;
}

template <class T>
T queue<T>::front() const throw (queueEmptyException)
{
	if(!_front)
		throw queueEmptyException();
	return _front->data;
}

template <class T>
queue<T>::~queue()
{
	node<T>* ptr = _front;
	while(ptr)
	{
		_front = _front->next;
		delete ptr;
		ptr = _front;
	}
}
