#include <iostream>
#include <string>
using namespace std;

#define K 10000

int queue[K];
int front;
int rear;

void init()
{
	front = 0;
	rear = 0;
}

int isFull()
{
	if(rear < K)
		return 0;
	return 1;
}

int isEmpty()
{
	if(rear == front)
		return 1;
	return 0;
}

void enqueue(int data)
{
	if(isFull())
		return;
	queue[rear++] = data;
}

int dequeue()
{
	if(isEmpty())
		return -1;
	return queue[front++];
}

int size()
{
	return rear - front;
}

int peekFront()
{
	if(isEmpty())
		return -1;
	return queue[front];
}

int peekRear()
{
	if(isEmpty())
		return -1;
	return queue[rear-1];
}

int main(void)
{
	int n;
	cin >> n;
		
	string cmd; int data; int res;
	for(int i = 0; i < n; i++)
	{
		cin >> cmd;
		if(cmd == "push")
		{
			cin >> data;
			enqueue(data);
		}
		else if(cmd == "pop")
		{
			res = dequeue();
			cout << res << "\n";
		}
		else if(cmd == "size")
		{
			res = size();
			cout << res << "\n";
		}
		else if(cmd == "empty")
		{
			res = isEmpty();
			cout << res << "\n";
		}
		else if(cmd == "front")
		{
			res = peekFront();
			cout << res << "\n";
		}
		else if(cmd == "back")
		{
			res = peekRear();
			cout << res << "\n";
		}
		else
		{
			continue;
		}
	}
}