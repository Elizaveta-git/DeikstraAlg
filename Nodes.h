#pragma once
#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
	string vertex;
	int minDistTo;
	Node* next;
	Node(string vertex = "", int minDisTo = 0, Node* next=NULL)
	{
		this->vertex = vertex;
		this->minDistTo = minDisTo;
		this->next = next;
	}
};

class NodeList
{
	Node* head;
	Node* tail;
public:
	NodeList()
	{
		tail = head = NULL;
	}
	void push_back(string city, int min)
	{
		Node* current=new Node(city, min);
		if (head == NULL)
		{
			tail = head = current;
		}
		else
		{
			tail->next = current;
			tail = current;
		}
	}
	Node* ReturnHead()
	{
		return head;
	}
	Node* Find(string From)
	{
		Node* current = head;
		while (current->vertex != From)
		{
			current = current->next;
		}
		return current;
	}
	~NodeList()
	{
		Node* current = head;
		while (current != tail)
		{
			Node* sup = current->next;
			delete current;
			current = sup;
		}
		delete tail;
	}
};