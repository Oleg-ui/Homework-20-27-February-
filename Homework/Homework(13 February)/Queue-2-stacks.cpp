#include <iostream>
#include <stack> 
using namespace std;

class Queue
{
	stack<int> LeftStack;
	stack<int> RightStack;

public:

	void push(int n)
	{
		LeftStack.push(n);
	}

	void pop_front()
	{
		while (!LeftStack.empty())
		{
			RightStack.push(LeftStack.top());
			LeftStack.pop();
		}

		RightStack.pop();

		while (!RightStack.empty())
		{
			LeftStack.push(RightStack.top());
			RightStack.pop();
		}
	}

	void print()
	{
		while (!LeftStack.empty())
		{
			RightStack.push(LeftStack.top());
			LeftStack.pop();
		}

		while (!RightStack.empty())
		{
			cout << RightStack.top() << " ";
			LeftStack.push(RightStack.top());
			RightStack.pop();
		}
	}
};

/*int main()
{
	Queue q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	q.pop_front();
	q.print();
}*/