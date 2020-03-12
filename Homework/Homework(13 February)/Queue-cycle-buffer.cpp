#include <iostream>
#include <stack> 
using namespace std;

class Queue
{
	int* arr;
	int SizeQueue;
	int LengthQueue;
	int tail;
	int head;

public:

	Queue(int n)
	{
		tail = 0;
		head = 0;
		LengthQueue = 0;
		SizeQueue = n;
		arr = new int[SizeQueue];
	}

	void push(int n)
	{
		if (SizeQueue == LengthQueue)
		{
			Resize();
		}
		else
		{
			arr[tail] = n;
			LengthQueue++;
			tail++;
		}
	}

	void Resize()
	{
		int* Arr = new int[SizeQueue];

		for (int i = 0; i < LengthQueue; i++)
		{
			Arr[i] = arr[i];
		}

		delete[] arr;
		SizeQueue *= 2;
		arr = new int[SizeQueue];
		
		for (int i = 0; i < LengthQueue; i++)
		{
			arr[i] = Arr[i];
		}

	}

	bool isFull()
	{
		return SizeQueue == LengthQueue ? true : false;
	}

	bool isEmpty()
	{
		return LengthQueue == 0 ? true : false;
	}

	void pop_front()
	{
		if (isEmpty())
		{
			cout << "Очередь пустая" << endl;
		}
		else 
		{
			if (head == SizeQueue)
			{
				head = 0;
			}

			head++;
		}
	}

	void get()
	{
		if (isEmpty())
		{
			cout << "Очередь пустая" << endl;
		}
		else
		{
			cout << arr[head] << endl;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");
	Queue q(4);
	q.push(1);
	q.push(2);
	q.get();
	q.pop_front();
	q.get();
	q.push(3);
	q.push(4);
	q.pop_front();
	q.pop_front();
	q.get();
}