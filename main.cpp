#include <iostream>
#include <fstream>
#include "windows.h"
using namespace std;
#include "list1.h"
bool fill_list(elem*& list, const char* filename) {

	ifstream f(filename);
	if (f.is_open())
	{

		char* data = new char[31];
		while (!f.eof()) {
			f.getline(data, 31, '\n');
			if (f.fail()) {
				f.close(); 
				clear(list); 
				return false;
			}
			int v, p;
			int cnt = sscanf_s(data, "%d %d", &v, &p);
			switch (cnt)
			{
			case 1: {
				if (!find(list, v))
				{
					add(list, v);
				}
				break;
			}
			case 2:
			{
				if (!find(list, v))
				{
					insert(list, v, p);
				}
			}
			}
		}
		f.close();
		delete[] data;
		return true;
	}
	return false;
}
void show_list(elem* list)
{
	elem* curr = list;
	if (!curr) cout << "EMPTY LIST" << endl;
	else while (curr)
	{
		cout << curr->a << (curr->next ? " " : "\n");
		curr = curr->next;
	}
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	elem* list1 = nullptr;
	if (fill_list(list1, "data.txt")) {
		show_list(list1);
		clear(list1);
	}
	else {
		cout << "Не удалось прочитать данные из файла :(";
	}
	system("pause");
}