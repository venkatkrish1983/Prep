//K’th largest element in a stream
//
//8 12 1 16 3 17 22 26 31 4 13 9 12 27 
//
//idea is to ceate a min heap of sie k with largest elements.Anything less than root (which is min) do not add to heap else remove root and add the value
//
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int KthLargestElement(priority_queue<int,vector<int>,greater<int>> & p ,int k,int val)
{
	if(p.size() <  k)
	{
		p.push(val);
	}
	else
	{
		if(p.top() < val)
		{
			p.pop();
			p.push(val);
		}
	}
	return p.top();
}

int main()
{
	vector<int> v {8,12,1,16};
	int k =3;
	priority_queue<int,vector<int>,greater<int>> p; //create min heap	
	for(int i=0;i<k;i++)	
	{
		p.push(v[i]);
	}
	cout<<KthLargestElement(p,k,16)<<"\n";
	cout<<KthLargestElement(p,k,3)<<"\n";
	cout<<KthLargestElement(p,k,17)<<"\n";
	cout<<KthLargestElement(p,k,22)<<"\n";
	cout<<KthLargestElement(p,k,26)<<"\n";
	return 0;
}
