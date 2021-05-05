#include <vector>
#include <exception>
using namespace std;

class queueEmptyException; //forward declaration
template <class T>
class PriorityQueueADT
{
	//Even Priority queue can be implemented using LL but insert will be O(n) but delete and max element is O(1)
	public:
		virtual void enqueue(T elem) = 0;
		virtual T max() const throw (queueEmptyException)= 0;
		virtual void dequeue() throw (queueEmptyException) = 0;
		virtual bool isEmpty() const = 0;
		virtual int size() const = 0;	 
};

class queueEmptyException:public exception
{
	public:
		const char* what() const noexcept
		{
			return "queue empty";
		}
};

template <class T>
class PriorityQueue:public PriorityQueueADT<T>
{
	//try to implement using node?
	vector<T> v;
	public:
	//how does priority queue makesure highest element is always at top using heap
	// can use a vector to implement
	PriorityQueue(){}
	~PriorityQueue(){}
	void enqueue(T elem);
	void dequeue() throw (queueEmptyException);
	T max() const throw (queueEmptyException);
	int size() const;
	bool isEmpty() const;
  	void heapify_up();
	void heapify_down();	
};

template <class T>
int PriorityQueue<T>::size() const
{
	return v.size();
}

template <class T>
bool PriorityQueue<T>::isEmpty() const
{
	return v.empty()?true:false;
}

template <class T>
void PriorityQueue<T>::enqueue(T elem)
{
	v.push_back(elem);
	heapify_up(); //makesure that priority queue is maintained
}

template <class T>
void PriorityQueue<T>::heapify_up()
{
	int child = v.size() -1;
	int parent = (child -1)/2;
	while(parent >= 0 && v[child] > v[parent])
	{
		T t = v[child];
		v[child] = v[parent];
		v[parent] = t;
		child = parent;
		parent = (child-1 )/2;
	}

}

template <class T>
T PriorityQueue<T>::max() const throw (queueEmptyException)
{
	return v[0];
}

template <class T>
void PriorityQueue<T>::dequeue() throw (queueEmptyException)
{
	v[0] = v[v.size()-1];
	v.pop_back();
	heapify_down();

}

template <class T>
void PriorityQueue<T>::heapify_down()
{
	int parent = 0;
	int leftchild = parent*2+1;
	int rightchild = parent*2+2;
	leftchild = leftchild < v.size() ? leftchild:-1;
	rightchild = rightchild < v.size() ? rightchild:-1;
	int biggerchild = 0;
	if(rightchild > 0 && leftchild > 0)	
		biggerchild = v[rightchild] > v[leftchild] ? rightchild:leftchild;
	else  if(leftchild > 0)
		biggerchild = leftchild;
	else
		biggerchild = -1;
			while(biggerchild> 0 && v[parent] < v[biggerchild]) 
			{
				T t = v[parent];
				v[parent] = v[biggerchild];
				v[biggerchild] = t;
				leftchild = parent*2 +1;
				rightchild = parent*2 +2;
				leftchild = leftchild < v.size() ? leftchild:-1;
				rightchild = rightchild < v.size() ? rightchild:-1;
				if(rightchild > 0 && leftchild > 0)	
					biggerchild = v[rightchild] > v[leftchild] ? rightchild:leftchild;
				else  if(leftchild > 0)
					biggerchild = leftchild;
				else
					biggerchild = -1;
			}
}
