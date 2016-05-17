#pragma once
#include"Node.h"
#include <iostream>	
using namespace std;

template<class T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* tempPoint;


public:
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	};
	void AddFirst(T p_data)
	{
		Node<T>* tempNode = new Node<T>();

		tempNode->data = p_data;
		tempNode->next = head;
		tempNode->prev = NULL;
		if (head == NULL)
		{
			tail = tempNode;
		}
		else
			head->prev = tempNode;

		head = tempNode;
	}
	void Delete(int delNum)
	{
		Node<T>* delNode = head;
		Node<T>* preNode = head;

		if (delNum == 0)
		{
			head = delNode->next;
			delNode->prev = NULL;

		}
		else
		{
			while (delNum)
			{
				delNode = delNode->next;
				delNum--;
			}

			preNode = delNode->prev;
			preNode->next = delNode->next;
			delNode->next->prev = preNode;
		}
		delete delNode;
	}
	void DeleteAll()
	{
		Node<T>* delNode = head;
		while (delNode->next != NULL)
		{
			delete delNode;
			delNode = delNode->next;
		}
	}
	void Add(T p_data)
	{
		Node<T>* tempNode = new Node<T>();

		tempNode->data = p_data;
		tempNode->next = NULL;
		tempNode->prev = tail;
		if (tail == NULL)
			head = tempNode;
		else
			tail->next = tempNode;

		tail = tempNode;
	}

	void PrintAll()
	{
		tempPoint = head;

		while (tempPoint->next != NULL)
		{
			cout << tempPoint->data << endl;

			tempPoint = tempPoint->next;

		}
		cout << tempPoint->data << endl;
	}

	T GetData(int p_num)
	{
		Node<T>* getData = head;

		for (int i = 0; i < p_num; i++)
		{
			if (getData->next != NULL)
				getData = getData->next;
			else
				return getData->prev->data;
		}

		return getData->data;
	}
	int GetSize()
	{
		Node<T>* temp = head;
		int size = 1;
		while (temp->next != NULL)
		{
			size++;
			temp = temp->next;
		}
		return size;
	}


	~LinkedList() {};
};