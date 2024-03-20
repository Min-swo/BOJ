#include <iostream>
using namespace std;

#define K 6000

int queue[K];
int answer[K];
int front = 0;
int rear = 0;

int isEmpty()
{
	if(front == rear)
		return 1;
	return 0;
}

void enqueue(int a)
{
	rear = (rear + 1) % K;
	queue[rear] = a;
}

int dequeue()
{
	if(isEmpty())
		return -1;
	front = (front + 1) % K;
	return queue[front];
}

int main(void)
{
	int n, k;
	cin >> n >> k;
	
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		cnt++;
		if(cnt % k != 0)
		{
			enqueue(i);
			continue;
		}
		answer[cnt / k - 1] = i;
	}
	
	int tmp;
	while(!isEmpty())
	{
		cnt++;
		tmp = dequeue();
		if(cnt % k != 0)
		{
			enqueue(tmp);
			continue;
		}
		answer[cnt / k - 1] = tmp;
	}
	
	cout << "<";
	for(int i = 0; i < n-1; i++)
		cout << answer[i] << ", ";
	cout << answer[n-1] << ">\n";
}