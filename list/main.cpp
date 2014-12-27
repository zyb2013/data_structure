#include <iostream>

#include "List.h"

using namespace std;

int main()
{
	List<int> list;
	//list.push_front(100);
	//list.push_front(200);
	//list.push_front(300);
	//list.iterate();

	//list.insert(500);
	//list.iterate();

	//list.insert(400, 1);
	//list.iterate();

	//list.push_back(600);
	//list.iterate();

	for (int i = 100; i <= 1000; i += 100)
	{
		list.push_back(i);
	}

	list.iterate();
	return 0;
}