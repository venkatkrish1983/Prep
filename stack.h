//Note : to implement userdefined exception override what() and destructor
//throw (exception type) in function param
#include <exception>
#include <iostream>

using namespace std;
class stackEmptyException:public exception
{
        public:
                const char* what() const throw()
                {
                        return "stack Full";
                }
                ~stackEmptyException()
                {
                }
};

template <class T>
class stackADT //interface class
{
        public:
                virtual void push(T val)=0;
                virtual void pop() throw (stackEmptyException) =0;
                virtual T Top() const throw (stackEmptyException) =0;
                virtual int Size() const =0;
                virtual bool empty() const =0;
};

template <class T>
struct Node
{
        T data;
        Node* next;
        Node(T val):data(val),next(NULL){}
};

template <class T>
class stack:public stackADT<T>
{
        Node<T>* top;
        int size;
        public:
        stack():top(NULL),size(0){}
        ~stack();
        void push(T val);
        void pop() throw (stackEmptyException);
        T Top() const throw (stackEmptyException);
        int Size() const;
        bool empty() const;
};

template <class T>
void stack<T>::push(T val)
{
        Node<T>* ptr = new Node<T>(val);
          ptr->next = top;
        top = ptr;
        size++;
}

template <class T>
void stack<T>::pop() throw (stackEmptyException)
{
        Node<T>* ptr = top;
        if( !ptr)
                throw stackEmptyException();
        top = top->next;
        delete ptr;
        ptr = NULL;
        size--;
}

template <class T>
T stack<T>::Top() const throw (stackEmptyException)
{
        if(!top)
                throw stackEmptyException();
        return top->data;
}

template <class T>
bool stack<T>::empty() const
{
        return top?false:true;
}

template <class T>
stack<T>::~stack()
{
        while(top)
        {
                Node<T>* ptr = top;
                top = top->next;
                delete ptr;
                ptr = NULL;
        }
        top = NULL;
        size =0;
}

template <class T>
int stack<T>::Size() const
{
        return size;
}
                                       
                                                   
