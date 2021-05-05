#include <priorityqueue.h>
#include <iostream>
int main()
{
	PriorityQueue<int> pq;
	pq.enqueue(16);
	pq.enqueue(18);
	pq.enqueue(1);
	pq.enqueue(19);
	pq.dequeue();
	cout<<pq.max()<<"\n";

	return 0;
}
