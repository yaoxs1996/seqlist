#include<iostream>
#include"seqlist.h"

int main()
{
	SeqList<int> test(15);
	int array[15] = { 2,5,8,1,9,9,7,6,4,3,2,9,7,7,9 };
	for (int i = 0; i < 15; i++)
	{
		test.insert(array[i], 0);
	}
	test.insert(1, 0);
	cout << (test.find(0) ? " can't be found " : " be found ") << 0 << endl << endl;

	test.remove(7);
	test.print();
	test.remove(9);
	test.print();
	test.remove(0);
	test.print();

	system("pause");
	return 0;
}
