#include <queue.h>

int main()
{
	queue<int> q;
	q.enqueue(10);
	q.enqueue(5);
	q.enqueue(32);
	q.enqueue(16);
	q.dequeue();
	cout<<q.front()<<"\n";
	return 0;
}
