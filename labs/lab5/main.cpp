#include <iostream>
#include "doublyLL.h"
using namespace std;

int main()
{
	doublyLL dll;
	for(int i=0;i<10;i++)
	{
		dll.insertNodeAtEnd(i);
	}
	dll.print_list();
	cout << endl;
	return 0;
}
