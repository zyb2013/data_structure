#ifndef _LIST_H
#define _LIST_H

#include <cassert>

typedef unsigned int UINT;

/*
	µ¥Á´±í
	2014-12-27 16:26
*/
template<typename T>
class List
{
	struct Node
	{
		T data;
		Node *next;

		Node(const T &data) : data(data), next(NULL)
		{

		}
	};

	Node *head;

	Node *tail;

	size_t count;

	void insert_first(const T& data)
	{
		Node *pNode = new Node(data);
		assert(pNode != NULL);
		pNode->next = head;
		head = pNode;
		if (count == 0)
		{
			tail = pNode;
		}
		count++;
	}

	Node *find_node(UINT pos)
	{
		Node *pNode = head;
		for (UINT i = 0; i < pos; i++)
		{
			if (!pNode)
			{
				return NULL;
			}
			pNode = pNode->next;
		}
		return pNode;
	}

public:
	List() : head(NULL), tail(NULL), count(0)
	{

	}

	~List()
	{
		clearAll();
	}

	bool push_front(const T& data)
	{
		insert_first(data);
		return true;
	}

	bool push_back(const T& data)
	{
		Node *pNode = new Node(data);
		assert(pNode != NULL);
		if (tail == NULL)
		{
			head = pNode;
		}
		else
		{
			tail->next = pNode;
		}
		tail = pNode;
		count++;
		return true;
	}

	void clearAll()
	{
		while (head)
		{
			Node *pNode = head->next;
			delete head;
			head = pNode;
			count--;
		}
	}

	bool insert(const T& data, size_t pos = 0)
	{
		if (pos == 0)
		{
			insert_first(data);
			return true;
		}

		Node *pNode = find_node(pos);
		if (!pNode)
		{
			return false;
		}

		Node *pNewNode = new Node(data);
		pNewNode->next = pNode->next;
		pNode->next = pNewNode;
		count++;
		return true;
	}

	void iterate()
	{
		Node *pNode = head;
		while (pNode)
		{
			cout << pNode->data << " ";
			pNode = pNode->next;
		}
		cout << endl;
	}

	size_t size()
	{
		return count;
	}

};

#endif