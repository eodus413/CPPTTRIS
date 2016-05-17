#pragma once
#include<iostream>
template<class T>
class Node
{
	template<class T>
	friend class LinkedList;
	template<class T>
	friend class CStack;
private:
	Node* next;
	Node* prev;
	T data;
public:
	Node(T p_data)
	{
		next = NULL;
		prev = NULL;
		data = p_data;
	}
	Node()
	{
		prev = NULL;
		next = NULL;
		data = 0;
	};
	Node(T p_data, Node* p_next, Node* p_prev)
	{
		prev = p_prev;
		next = p_next;
		data = p_data;
	}
	~Node() {};
};

