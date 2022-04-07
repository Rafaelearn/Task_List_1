#include "list1.h"
void add(elem*& first, int data)
{
	elem* newel = new elem; 
	newel->a = data;
	if (first) 
	{
		elem* curr = first; 
		while (curr->next)
		{
			curr = curr->next;
		}
		curr->next = newel;
	}
	else
	{
		first = newel;
	}
}
void insert(elem*& first, int data, int pos)
{
	elem* newel = new elem;
	newel->a = data;
	if (first && pos > 0)
	{
		elem* curr = first;
		int p = 0;
		while (curr->next && p < pos - 1)
		{
			curr = curr->next;
			p++;
		}
		newel->next = curr->next;
		curr->next = newel;
	}
	else
	{
		newel->next = first;
		first = newel;
	}
}
const int* get(const elem* first, int pos)
{
	if (pos < 0 || !first) return nullptr;
	int p = 0;
	elem* curr = (elem*)first;
	while (curr && p < pos)
	{
		curr = curr->next;
		p++;
	}
	if (curr)
	{
		return &curr->a;
	}
	return nullptr;
}
int count(const elem* first)
{
	int cnt = 0;
	elem* curr = (elem*)first;
	while (curr)
	{
		cnt++;
		curr = curr->next;
	}
	return cnt;
}
bool remove(elem*& first, int pos) {
	if (pos < 0 || !first) return false;
	if (pos == 0) {
		elem* rem = first;
		first = first->next;
		delete rem;
		return true;
	}
	int p = 0;
	elem* curr = first;
	while (curr->next && p < pos - 1) {
		curr = curr->next;
		p++;
	}
	if (curr->next)
	{
		elem* rem = curr->next;
		curr->next = curr->next->next;
		delete rem;
		return true;
	}
	return false;
}
void clear(elem*& first)
{
	while (first)
	{
		elem* del = first;
		first = first->next;
		delete del;
	}
}
bool find(elem*& first, int data)
{
	elem* curr = first;
	while (curr)
	{
		if (curr->a == data)
		{
			return true;
		}
		curr = curr->next;
	}
	return false;
}