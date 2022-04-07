#pragma once
struct elem
{
	int a;
	elem* next = nullptr; 
};
void add(elem*& list, int data);
void insert(elem*& list, int data, int position);
const int* get(const elem* list, int position);
int count(const elem* list);
bool remove(elem*& list, int position);
void clear(elem*& list);
bool find(elem*& first, int data);
