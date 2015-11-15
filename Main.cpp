#include <iostream>
#include "BinaryTree.h"
using std::cout;
using std::endl;

template<class T>
void Visit(T& x)
{
	cout << x << " ";
}

void main()
{
	BinaryTree<char> a, b, x, y, z,m,n,j,k;
	x.MakeTree('A', a, b);
	y.MakeTree('B', a, b);
	z.MakeTree('C', x, y);
	m.MakeTree('D', a, b);
	n.MakeTree('E', a, b);
	j.MakeTree('F', m, n);
	k.MakeTree('G', z, j);
	cout << k.Size() << endl;
	cout << k.Leaves() << endl;
	k.PreOrder(Visit);
	cout << endl;
	k.Travelsal(Visit);
	cout << endl << "------------------" << endl;
	k.Exchanges();
	k.PreOrder(Visit);
	cout << endl;
	cout << k.Height() << endl;
}