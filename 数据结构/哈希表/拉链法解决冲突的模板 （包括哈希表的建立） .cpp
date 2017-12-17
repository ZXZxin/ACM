//哈希表的拉链解决冲突
//学习博客：http://blog.csdn.net/liyuefeilong/article/details/48727637
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
const int maxn = 100 + 10;
const int Mod = 10;//H(key)=key % M//哈希函数

typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node *next;
}Node,*pNode;

typedef struct HashNode{
	Node *first;
}HashNode,*HashTable; 

HashTable creat_HashTable(int n) {//创建长度为n的哈希表
	HashTable hashTable = (HashNode*)malloc(n * sizeof(HashNode));
	if (!hashTable) {
		printf("cannot malloc hashTable !");
		exit(-1);
	}
	for (int i = 0; i < n; i++)hashTable[i].first = NULL;//每个初始化
	return hashTable;
}

pNode search_HashTable(HashTable hashTable, ElemType data) {//查找
	if (!hashTable) {
		return NULL;
	}
	pNode pCur = hashTable[data % Mod].first;//先找到起始的点
	while (pCur && pCur->data != data) {
		pCur = pCur->next;
	}
	return pCur;
}

bool insert_HashTable(HashTable hashTable, ElemType data) {//插入
	if (search_HashTable(hashTable, data))return NULL;//如果已经存在，则返回false
	pNode pCur = hashTable[data % Mod].first;
	pNode s = (Node*)malloc(sizeof(Node));
	s->data = data;
	if (!pCur){
		hashTable[data % Mod].first = s; 
		s->next = NULL;
		return true;
	}
	while (pCur->next != NULL) {
		pCur = pCur->next;
	}
	pCur->next = s;
	s->next = NULL;
	return true;
}

bool delete_HashTable(HashTable hashTable, ElemType data) {//删除哈希表中的某个元素
	if (!search_HashTable(hashTable, data))return false;
	pNode pCur = hashTable[data % Mod].first;
	if (pCur->data == data) {
		hashTable[data % Mod].first = pCur->next;
		free(pCur);
		return true;
	}
	while (pCur->next->data != data) {
		pCur = pCur->next;
	}
	pNode q = pCur->next;
	pCur->next = q->next;
	free(q);
	return true;
}

void destroy_HashTable(HashTable hashTable, int n) {//销毁哈希表
	for (int i = 0; i < n; i++) {
		pNode pCur = hashTable[i].first;
		pNode pDel = NULL;
		while (pCur) {
			pDel = pCur;
			pCur = pCur->next;
			free(pDel);
		}
	}
	free(hashTable);
}

void print_HashTable(HashTable hashTable, int n) {//打印哈希表
	for (int i = 0; i < n; i++) {
		pNode pCur = hashTable[i].first;
		while (pCur != NULL) {
			printf("%d ", pCur->data);
			pCur = pCur->next;
		}
		printf("\n");
	}
}

int main() {
	int len = 13;
	HashTable hashtable = creat_HashTable(len);
	insert_HashTable(hashtable, 1);//插入元素
	insert_HashTable(hashtable, 11);
	insert_HashTable(hashtable, 2);
	insert_HashTable(hashtable, 12);
	insert_HashTable(hashtable, 22);
	insert_HashTable(hashtable, 32);
	insert_HashTable(hashtable, 3);
	insert_HashTable(hashtable, 5);
	insert_HashTable(hashtable, 7);
	insert_HashTable(hashtable, 17);
	printf("哈希表如下：\n");
	print_HashTable(hashtable, len);
	printf("\n输入一个要查找的数:\n");
	ElemType temp;
	scanf("%d", &temp);
	if(pNode pFind= search_HashTable(hashtable, temp))printf("找到了元素 %d\n", pFind->data);
	else printf("没有找到 %d\n", temp);
	printf("\n输入一个要删除的数:\n");
	scanf("%d", &temp);
	if (delete_HashTable(hashtable, temp)) {
		printf("删除成功!");
		printf("\n删除后的哈希表如下：\n");
		print_HashTable(hashtable, len);
	}
	else printf("%d 不存在!", temp);
	destroy_HashTable(hashtable, len);//销毁哈希表
	return 0;
}