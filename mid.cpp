#include<iostream>
#include<queue>
using namespace std;

class midHeap{
	priority_queue<int, vector<int> > small;
	priority_queue<int, vector<int>, greater<int> > big;
public:
	void insert(int x)
	{
		if(small.empty() || x <= small.top())
			small.push(x);
		else
			big.push(x);
		if(small.size() > big.size() + 1)
		{
			big.push(small.top());
			small.pop();
		}
		if(big.size() > small.size() + 1)
		{
			small.push(big.top());
			big.pop();
		}
	}
	int find_mid()
	{
		if(big.size() > small.size())
			return big.top();
		else if(small.size() > big.size())
			return small.top();
		else
			return (small.top() + big.top()) / 2;
	}
};

int main()
{
	midHeap h;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		h.insert(x);
		cout << "mid = ";
		cout << h.find_mid() << endl;
	}

}
