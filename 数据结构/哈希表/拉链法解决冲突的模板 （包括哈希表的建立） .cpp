//��ϣ������������ͻ
//ѧϰ���ͣ�http://blog.csdn.net/liyuefeilong/article/details/48727637
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
const int maxn = 100 + 10;
const int Mod = 10;//H(key)=key % M//��ϣ����

typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node *next;
}Node,*pNode;

typedef struct HashNode{
	Node *first;
}HashNode,*HashTable; 

HashTable creat_HashTable(int n) {//��������Ϊn�Ĺ�ϣ��
	HashTable hashTable = (HashNode*)malloc(n * sizeof(HashNode));
	if (!hashTable) {
		printf("cannot malloc hashTable !");
		exit(-1);
	}
	for (int i = 0; i < n; i++)hashTable[i].first = NULL;//ÿ����ʼ��
	return hashTable;
}

pNode search_HashTable(HashTable hashTable, ElemType data) {//����
	if (!hashTable) {
		return NULL;
	}
	pNode pCur = hashTable[data % Mod].first;//���ҵ���ʼ�ĵ�
	while (pCur && pCur->data != data) {
		pCur = pCur->next;
	}
	return pCur;
}

bool insert_HashTable(HashTable hashTable, ElemType data) {//����
	if (search_HashTable(hashTable, data))return NULL;//����Ѿ����ڣ��򷵻�false
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

bool delete_HashTable(HashTable hashTable, ElemType data) {//ɾ����ϣ���е�ĳ��Ԫ��
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

void destroy_HashTable(HashTable hashTable, int n) {//���ٹ�ϣ��
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

void print_HashTable(HashTable hashTable, int n) {//��ӡ��ϣ��
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
	insert_HashTable(hashtable, 1);//����Ԫ��
	insert_HashTable(hashtable, 11);
	insert_HashTable(hashtable, 2);
	insert_HashTable(hashtable, 12);
	insert_HashTable(hashtable, 22);
	insert_HashTable(hashtable, 32);
	insert_HashTable(hashtable, 3);
	insert_HashTable(hashtable, 5);
	insert_HashTable(hashtable, 7);
	insert_HashTable(hashtable, 17);
	printf("��ϣ�����£�\n");
	print_HashTable(hashtable, len);
	printf("\n����һ��Ҫ���ҵ���:\n");
	ElemType temp;
	scanf("%d", &temp);
	if(pNode pFind= search_HashTable(hashtable, temp))printf("�ҵ���Ԫ�� %d\n", pFind->data);
	else printf("û���ҵ� %d\n", temp);
	printf("\n����һ��Ҫɾ������:\n");
	scanf("%d", &temp);
	if (delete_HashTable(hashtable, temp)) {
		printf("ɾ���ɹ�!");
		printf("\nɾ����Ĺ�ϣ�����£�\n");
		print_HashTable(hashtable, len);
	}
	else printf("%d ������!", temp);
	destroy_HashTable(hashtable, len);//���ٹ�ϣ��
	return 0;
}