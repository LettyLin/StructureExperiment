#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include "Queue.h"
template<class T>
struct BTNode
{
	BTNode(){ lChild = rChild = NULL; }
	BTNode(const T& x){ element = x; lChild = rChild = NULL; }
	BTNode(const T& x, BTNode<T>* l, BTNode<T>* r)
	{
		element = x;
		lChild = l;
		rChild = r;
	}
	T element;
	BTNode<T>* lChild;
	BTNode<T>* rChild;
};

template<class T>
class BinaryTree
{
public:
	BinaryTree(){ root = NULL; }
	~BinaryTree(){ Clear(); }
	bool IsEmpty() const;
	bool Root(T& x)const;
	void MakeTree(const T& x, BinaryTree<T>& left, BinaryTree<T>& right);
	void BreakTree(T& x, BinaryTree<T>& left, BinaryTree<T>& right);
	void PreOrder(void(*Visit)(T& x));
	void InOrder(void(*Visit)(T& x));
	void PostOrder(void(*Visit)(T& x));
	void Copy(BinaryTree<T>& a);
	void Clear();//删除
	int Size();
	int Leaves();//叶子结点数
	void Exchanges();//子树左右交换
	void Travelsal(void(*Visit)(T& x));//层次遍历
	int Height();//高度
protected:
	BTNode<T>* root;
private:
	int Height(BTNode<T>* t);
	void Exchanges(BTNode<T>* t);
	int Leaves(BTNode<T>* t);
	BTNode<T>* Copy(BTNode<T>* t);
	void Clear(BTNode<T>* t);
	int Size(BTNode<T>* t);
	void PreOrder(void(*Visit)(T& x), BTNode<T>* t);
	void InOrder(void(*Visit)(T& x), BTNode<T>* t);
	void PostOrder(void(*Visit)(T& x), BTNode<T>* t);
};

template<class T>
int BinaryTree<T>::Height()
{
	return Height(root);
}
template<class T>
int BinaryTree<T>::Height(BTNode<T>* t)
{
	if (t == NULL) return 0;
	int j = Height(t->lChild);
	int k = Height(t->rChild);
	return j > k ? j + 1 : k + 1;
}

template<class T>
void BinaryTree<T>::Exchanges()
{
	Exchanges(root);
}
template<class T>
void BinaryTree<T>::Exchanges(BTNode<T>* t)
{
	if (t)
	{
		Exchanges(t->lChild);
		Exchanges(t->rChild);
		BTNode<T>* q = t->lChild;
		t->lChild = t->rChild;
		t->rChild = q;
	}
}

template<class T>
int BinaryTree<T>::Leaves()
{
	return Leaves(root);
}
template<class T >
int BinaryTree<T>::Leaves(BTNode<T>* t)
{
	if (t != NULL)
	{
		if (t->lChild == NULL&&t->rChild == NULL)
		{
                  return 1;
		}
                else{
                  return Leaves(t->lChild) + Leaves(t->rChild);
                }
	}
	return 0;
}

template<class T>
bool BinaryTree<T>::IsEmpty() const
{
	return !root;
}

template<class T>
void BinaryTree<T>::Clear()
{
	Clear(root);
}
template<class T>
void BinaryTree<T>::Clear(BTNode<T>* t)
{
	if (t)
	{
		Clear(t->lChild);
		Clear(t->rChild);
		delete t;
	}
}

template<class T>
int BinaryTree<T>::Size()
{
	return Size(root);
}
template<class T>
int BinaryTree<T>::Size(BTNode<T>* t)
{
	int i = 0;
	if (t){
		i= Size(t->lChild) + Size(t->rChild) + 1;
	}
	return i;
}

template<class T>
bool BinaryTree<T>::Root(T& x)const
{
	x = root->element;
}

template<class T>
void BinaryTree<T>::MakeTree(const T& x, BinaryTree<T>& left, BinaryTree<T>& right)
{
	if (root || &left == &right) return;
	root = new BTNode<T>(x, left.root, right.root);
	left.root = NULL;
	right.root = NULL;
}

template<class T>
void BinaryTree<T>::BreakTree(T& X, BinaryTree<T>& left, BinaryTree<T>& right)
{
	if (!root || left.root || right.root || &left == &right) return;
	x = root->element;
	left->root = root->lChild;
	right->root = root->rChild;
	delete root;
	root = NULL;
}

template<class T>
void BinaryTree<T>::PreOrder(void(*Visit)(T& x))
{
	PreOrder(Visit, root);
}
template<class T>
void BinaryTree<T>::PreOrder(void(*Visit)(T& x),BTNode<T>* t)
{
	if (t)
	{
		Visit(t->element);
		PreOrder(Visit,t->lChild);
		PreOrder(Visit,t->rChild);
	}
}

template<class T>
void BinaryTree<T>::InOrder(void(*Visit)(T &x))
{
	InOrder(Visit, root);
}
template<class T>
void BinaryTree<T>::InOrder(void(*Visit)(T& x), BTNode<T>* t)
{
	if (t != NULL)
	{
		InOrder(Visit,t->lChild);
		Visit(t->element);
		InOrder(Visit,t->rChild);
	}
}

template<class T>
void BinaryTree<T>::PostOrder(void(*Visit)(T& x))
{
	PostOrder(Visit, root);
}
template<class T>
void BinaryTree<T>::PostOrder(void(*Visit)(T& x),BTNode<T>* t)
{
	if (t != NULL)
	{
		PostOrder(Visit, t->lChild);
		PostOrder(Visit, t->rChild);
		Visit(t->element);
	}
}

template<class T>
void BinaryTree<T>::Copy(BinaryTree<T>& a)
{
	root = Copy(a.root);
}
template<class T>
BTNode<T>* BinaryTree<T>::Copy(BTNode<T>* t)
{
	if (!root) return NULL;
	BTNode<T>* q = new BTNode<T>(t->element);
	q->lChild = Copy(t->lChild);
	q->rChild = Copy(t->rChild);
	return q;
}

template<class T>
void BinaryTree<T>::Travelsal(void(*Visit)(T& x))
{
	Travelsal(Visit, root);
}
template<class T>
void BinaryTree<T>::Travelsal(void(*Visit)(T& x), BTNode<T>*t)
{
	Queue<BTNode<T>*> q;
	BTNode<T>* b = root;
	q.Push(b);
	while (NULL != b)
	{
		Visit(b->element);
		q.Pop();
		if (NULL != b->lChild || NULL != b->rChild)
		{
			q.Push(b->lChild);
			q.Push(b->rChild);
		}
		b = q.Front();
	}
}

#endif
