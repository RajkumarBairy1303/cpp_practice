// Singlelinkedlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
public:
	int m_data;
	Node* m_next;

	Node()
	{
		m_data = 0;
		m_next = nullptr;
	}
};

class Singlelinkedlist
{
	Node* m_head;
public:
	Singlelinkedlist()
	{
		m_head = nullptr;
	}

	void add(int val)
	{
		Node* temp = new Node();
		temp->m_data = val;
		temp->m_next = nullptr;

		if (m_head == nullptr)
			m_head = temp;
		else
		{
			Node* temp1 = m_head;
			while (temp1->m_next != nullptr)
				temp1 = temp1->m_next;
			temp1->m_next = temp;
		}
	}

	void display()
	{
		Node* temp = m_head;
		while (temp != nullptr)
		{
			std::cout << temp->m_data << "->";
			temp = temp->m_next;
		}
		std::cout << std::endl;
	}
};
int main()
{
	Singlelinkedlist list;
	list.add(10);
	list.add(20);
	list.add(30);
	list.display();
	return 0;
}
