#include <iostream>
using namespace std;
const int hashSize = 13; //factors to consider while setting hash table size
//implement a C++ unordered map
//
//how to convert object to int and string to int uniquely
//linear probing/double hashing 
//When to go for rehashing ..what is the ideal load factor in a hash table

template <class T>
class hashADT
{
        public:
                virtual void insertKey(T key) = 0;
                virtual void deleteKey(T key) = 0;
                //when to do rehashing
                virtual int findKey(T key) = 0; //chek what functions does unordered map in C++ STL
};

//3 strategies 1. Sep chaining
//             2. linear Probing
//             3. double hashing
//
//When to go for rehashing and handle non integer keys
//

template <class T>
struct node
{
        T data;
        node* next;
        node(T elem):data(elem),next(NULL){}
};

template <class T>
class Hash:public hashADT<T>
{
        node<T>* arr[hashSize];
        public:
        void insertKey(T key);
        void deleteKey(T key);
        int findKey( T key) ;
        int hashFunction(T key);
};

template <class T>
void Hash<T>::insertKey(T key)
{
        int index = hashFunction(key);
        node<T>* ptr = new node<T>(key);
        ptr->next = arr[index];
        arr[index] = ptr;
}

template <class T>
int Hash<T>::hashFunction(T key)
{
	//choose a good hash function
	int val = (int) key; //implement type cast in corresponding class
	return val % 13; //use good hash fn
}

template <class T>
void Hash<T>::deleteKey(T key)
{
        int index = hashFunction(key);
        node<T>* p = arr[index];
        node<T>* q = NULL; //use null ptr
        while(p && p->data != key)
        {
                q = p;
                p = p->next;
        }
        if(p) //if element is found
        {
                if(q)
                        q->next = p->next;
                else
                        arr[index] = p->next;

                delete p;
                p = NULL;
        }
}

template <class T>
int Hash<T>::findKey(T key) 
{
        int index = hashFunction(key);
        node<T>* p = arr[index];
        while(p && p->data != key)
        p = p->next;
        return  p ? index:-1;
}
