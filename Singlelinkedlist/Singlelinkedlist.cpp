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
    void sortLinkedList()
	{		
		auto Merge = [&](Node* a, Node* b, auto&& Merge)->Node*
		{
			if (a == nullptr)
				return b;
			if (b == nullptr)
				return a;

			Node* c;
			if (a->m_data < b->m_data)
			{
				c = a;
				c->m_next = Merge(a->m_next, b,Merge);
			}
			else
			{
				c = b;
				c->m_next = Merge(a, b->m_next,Merge);
			}

			return c;
		};
		auto mid_point = [&](Node* head)
		{
			if (head == nullptr || head->m_next == nullptr)
				return head;

			Node* fast = head;
			Node* slow = head;

			while (fast != nullptr && fast->m_next != nullptr)
			{
				fast = fast->m_next;
				if (fast->m_next == nullptr)
					break;

				fast = fast->m_next;
				slow = slow->m_next;
			}
			return slow;
		};
		auto Merge_sort = [&](Node *head,auto&& Merge_sort)->Node*
		{

			if (head == nullptr || head->m_next == nullptr)
				return head;

			Node* temp = head;
			Node *mid = mid_point(temp);

			Node* a = head;
			Node* b = mid->m_next;

			mid->m_next = nullptr;

			a = Merge_sort(a, Merge_sort);
			b = Merge_sort(b, Merge_sort);

			Node *c = Merge(a, b, Merge);

			return c;

		};
		m_head = Merge_sort(m_head,Merge_sort);		
	}
	void reverseList()
	{
		if (m_head == nullptr)
			return;

		Node* reverse = nullptr;
		while (m_head != nullptr)
		{
			Node *node = m_head;
			m_head = m_head->m_next;
			node->m_next = reverse;
			reverse = node;
		}
		m_head = reverse;
	}
	void removeNode(int val)
	{
		Node* temp = m_head;
		Node *del = nullptr;
		if (m_head->m_data == val)
		{
			del = m_head;
			m_head = m_head->m_next;
		}
		else
		{
			while (temp->m_next != nullptr && temp->m_next->m_data != val)
				temp = temp->m_next;

			if (temp->m_next != nullptr)
			{
				del = temp->m_next;
				temp->m_next = temp->m_next->m_next;
			}			
		}

		if (del != nullptr)
		{
			del->m_next = nullptr;
			delete del;
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
	void reverseparticularlist(int start, int end)
	{
		Node* temp    = m_head;
		int count     = 0;
		Node* reverse = nullptr;
		Node* prev    = nullptr;

		while (temp != nullptr && count < start)
		{		
			prev = temp;
			temp = temp->m_next;
			count++;
		}

		while (temp != nullptr && count < end)
		{
			Node* rev = temp;
			temp = temp->m_next;
			rev->m_next = reverse;
			reverse = rev;
			count++;
		}

		if (prev == nullptr)
		{
			prev = reverse;
			m_head = prev;
		}
		else
		{
			prev->m_next = reverse;
		}
			

		while (reverse->m_next != nullptr)
			reverse = reverse->m_next;

		reverse->m_next = temp;		
	}
};
int main()
{
	Singlelinkedlist list;
	list.add(50);
	list.add(20);
	list.add(10);
	list.add(60);
	list.display();
	list.removeNode(10);
	list.display();
	list.reverseList();	
	list.display();
	list.add(15);
	list.add(25);
	list.add(30);
	list.add(80);
	list.add(5);
	list.display();
	list.sortLinkedList();
	list.display();
	list.reverseparticularlist(3, 7);
	list.display();
	return 0;
}
