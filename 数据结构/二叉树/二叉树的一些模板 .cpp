//��������һЩģ��

#include <iostream>
#include<queue>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#define maxn 100010
using namespace std;

typedef char datatype;

typedef struct BinNode
{
	datatype data;
	struct BinNode* lchild;
	struct BinNode* rchild;
} BinNode;

typedef BinNode* bintree;


void createtree(bintree &t)///�������
{
	datatype c;
	if ((c = getchar()) == '#')
		t = NULL;
	else
	{
		t = (bintree)malloc(sizeof(BinNode));
		t->data = c;
		createtree(t->lchild);
		createtree(t->rchild);
	}
}

/* �������(�ǵݹ�)
˼·������T->data�󣬽�T��ջ������������������������������ʱ��ջ��Ԫ��ӦΪT����ջ�����������T����������
*/
void PreOrder2(bintree T)
{
	stack<bintree> s;//p�Ǳ���ָ��
	bintree p = T;
	while (p || !s.empty())
	{
		if (p != NULL)
		{

			s.push(p);
			printf("%c ", p->data); ///���ʸ��ڵ�
			p = p->lchild;
		}
		else
		{
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}


void InOrder2(bintree T)
{
	stack<bintree> s;
	bintree p = T;
	while (p || !s.empty())
	{
		if (p != NULL)
		{
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
			printf("%c ", p->data);
			s.pop();
			p = p->rchild;
		}
	}
}


/*void visit(bitree t)
{
    if(t->data != '#')
    {
        printf("%c ",t->data);
    }
}

void preorder(bitree t)
{
    if(t != null)
    {
        visit(t);
        preorder(t->rchild);
    }
}

void inorder(bitree t)
{
    if(t != null)
    {
        inorder(t->lchild);
        visit(t);
        inorder(t->rchild);
    }
}

void postorder(bitree t)
{
    if(t != null)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        visit(t);
    }
}

typedef struct bitnodepost
{
    bintree bintree;
    char tag;
} bitnodepost,*bintreepost;

void postorder2(bintree t)
{
    stack<bintreepost> s;
    bintree p = t;
    bintreepost bt;
    while(p != null || !s.empty())
    {
        while(p != null)
        {
            bt = (bintreepost)malloc(sizeof(bitnodepost));
            bt->bintree = p;
            bt->tag = 'l';///���ʹ�������
            s.push(bt);
            p = p->lchild;
        }
        ///��������������Ϸ��ʸ��ڵ�
        while(!s.empty() && (s.top())->tag == 'r')
        {
            bt = s.top();
            s.pop();
            bt->bintree;
            printf("%c ",bt->bintree->data);
        }
        if(!s.empty())
        {
            bt = s.top();
            bt->tag = 'r';
            p = bt->bintree;
            p = p->rchild;
        }
    }
}
*/

bintree search_tree(bintree t, datatype x)
{
	if (!t)
	{
		return NULL;
	}
	if (t->data == x)
	{
		return t;
	}
	else
	{
		if (!search_tree(t->lchild, x))
		{
			return search_tree(t->rchild, x);
		}
		return t;
	}
}

int count_tree(bintree t)
{
	if (t)
	{
		return (count_tree(t->lchild) + count_tree(t->rchild) + 1);
	}
	return 0;
}

int is_equal(bintree t1, bintree t2)
{
	if (!t1 && !t2)       //��Ϊ�վ����
	{
		return 1;
	}
	if (t1 && t2 && t1->data == t2->data)       //��һ��Ϊ�ջ����ݲ�ͬ�Ͳ��ж���
	{
		if (is_equal(t1->lchild, t2->lchild))
			if (is_equal(t1->rchild, t2->rchild))
			{
				return 1;
			}
	}
	return 0;
}


int hight_tree(bintree t)
{
	int h, left, right;
	if (!t)
	{
		return 0;
	}
	left = hight_tree(t->lchild);
	right = hight_tree(t->rchild);
	h = (left>right ? left : right) + 1;
	return h;
}

int main()
{
	bintree T;
	createtree(T);
	cout << "Preorder" << endl;
	PreOrder2(T);
	cout << endl;
	cout << "Inorder" << endl;
	InOrder2(T);
	cout << endl;
	int count = count_tree(T);
	cout << count << endl;
	int hight = hight_tree(T);
	cout << hight << endl;
	bintree t;
	t = search_tree(T, 'G');
	return 0;
}

