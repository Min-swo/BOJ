#include <iostream>
#include <string>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
};

class Deque{
private:
	Node* head;
	Node* tail;
	int size;
public:
	Deque()
	{
		head = new Node;
		tail = new Node;
		
		head->next = tail;
		head->prev = NULL;
		
		tail->next = NULL;
		tail->prev = head;
		
		size = 0;
	}
	
	int isEmpty()
	{
		if(size)
			return 0;
		return 1;
	}
	
	void enqueueBack(int data)
	{
		Node* node = new Node;
		node->data = data;
		
		node->next = tail;
		tail->prev->next = node;
		node->prev = tail->prev;
		tail->prev = node;
		size++;
	}
	
	void enqueueFront(int data)
	{
		Node* node = new Node;
		node->data = data;
		
		node->prev = head;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
		size++;
	}
	
	int dequeueBack()
	{
		if(isEmpty())
			return -1;
		
		Node* tmp = tail->prev;
		tmp->prev->next = tail;
		tail->prev = tmp->prev;
		size--;
		int data = tmp->data;
		delete(tmp);
		
		return data;
	}
	
	int dequeueFront()
	{
		if(isEmpty())
			return -1;
		
		Node* tmp = head->next;
		head->next = tmp->next;
		tmp->next->prev = head;
		size--;
		int data = tmp->data;
		delete(tmp);
		
		return data;
	}
		
	int getSize()
	{
		return size;
	}
	
	
	
	int peekFront()
	{
		if(isEmpty())
			return -1;
		return head->next->data;
	}
	
	int peekBack()
	{
		if(isEmpty())
			return -1;
		return tail->prev->data;
	}
};

int main(void)
{
	Deque deque;
	
	int n;
	cin >> n;
	
	string cmd; int k;
	for(int i = 0; i < n; i++)
	{
		cin >> cmd;
		if(cmd == "push_back")
		{
			cin >> k;
			deque.enqueueBack(k);
		}
		else if(cmd == "push_front")
		{
			cin >> k;
			deque.enqueueFront(k);
		}
		else if(cmd == "pop_front")
		{
			cout << deque.dequeueFront() << "\n";
		}
		else if(cmd == "pop_back")
		{
			cout << deque.dequeueBack() << "\n";
		}
		else if(cmd == "size")
		{
			cout << deque.getSize() << "\n";
		}
		else if(cmd == "empty")
		{
			cout << deque.isEmpty() << "\n";
		}
		else if(cmd == "front")
		{
			cout << deque.peekFront() << "\n";
		}
		else if(cmd == "back")
		{
			cout << deque.peekBack() << "\n";
		}
		else
		{
			continue;
		}
	}
}