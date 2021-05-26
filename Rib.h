#pragma once
#include <iostream>
#include <string>
using namespace std;
class Rib
{
public:
	string from;
	string To;
	int weight;
	Rib* next;
	bool ToVertexProcessed;//if vertex pricessed - true, else -false
	Rib(string from = "", string To = "", int weight = 0, Rib* next = NULL, bool ToVerxetProcessed = false)
	{
		this->from = from;
		this->To = To;
		this->weight = weight;
		this->next = next;
		this->ToVertexProcessed = ToVertexProcessed;
	}
};

class RibList
{
	Rib* head;
	Rib* tail;
	int Size;
public:
	RibList()
	{
		tail = head = NULL;
		Size = 0;
	}
	void push_back(string from, string To, int weight)
	{
		Rib* current = new Rib(from, To, weight);
		if (head == NULL)
		{
			tail = head = current;
			current->next = NULL;
		}
		else
		{
			tail->next = current;
			tail = current;
		}
		Size++;
	}
	void VertexProcessed(string To)
	{
		Rib* current = head;
		for (int i = 0; i < Size; i++)
		{
			if (current->To == To)
			{
				current->ToVertexProcessed = true;
			}
			current = current->next;
		}
	}
	Rib* MinRibFromVertex(string from)
	{
		Rib* current = head;
		Rib* SearchMinTo = NULL;
		int min = INT_MAX;
		for (int i = 0; i < Size; i++)
		{
			if (current->from == from)
			{
				if (current->weight < min && current->ToVertexProcessed == false)
				{
					min = current->weight;
					SearchMinTo = current;
				}
			}
			current = current->next;
		}
		return SearchMinTo;
	}
	~RibList()
	{
		Rib* current = head;
		while (current != tail)
		{
			Rib* sup = current->next;
			delete current;
			current = sup;
		}
		delete tail;
		Size = 0;
	}
};
