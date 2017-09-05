#ifndef LINK_H
#define LINK_H
#include "node.h"
#include<cstdio>
#include<iostream>
using namespace std;
template<class T>
class Link {
private:
	//���ݳ�Ա
	Node<T> *front, *rear;		//��ͷ�ͱ�βָ��
	Node<T> *prevPtr, *currPtr;	//��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
	int size;					//����Ԫ�ظ���
	int position;				//��ǰԪ���ڱ��е�λ����ţ��к���resetʹ��

	//������Ա
	//�����½�㣬������Ϊitem��ָ����ΪptrNext
	Node<T> *newNode(const T &item, Node<T> *ptrNext = NULL);

	//�ͷŽ��
	void freeNode(Node<T> *p);

	//������L���Ƶ���ǰ�����赱ǰ��Ϊ�գ�
	//�����ƹ��캯���͡�operator=������
	void copy(const Link<T> &L);


public:
	Link();		//���캯��
	Link(const Link<T> &L);	//���ƹ��캯��
	~Link();		//��������
	Link<T>& operator= (const Link<T> &L);	//���ظ�ֵ�����

	int getSize() const;		//����������Ԫ�ظ���
	bool isEmpty() const;		//�����Ƿ�Ϊ��

	void reset(int pos = 0);	//��ʼ���α��λ��
	void next();				//ʹ�α��ƶ�����һ�����
	bool endOfList() const;		//�α��Ƿ�����β
	int currentPosition(void) const;	//�����α굱ǰ��λ��

	void insertFront(const T &item);	//�ڱ�ͷ������
	void insertRear(const T &item);		//�ڱ�β��ӽ��
	void insertAt(const T &item);		//�ڵ�ǰ���֮ǰ������
	void insertAfter(const T &item);	//�ڵ�ǰ���֮�������

	T deleteFront();		//ɾ��ͷ���
	void deleteCurrent();	//ɾ����ǰ���

	T& data();		//���ضԵ�ǰ����Ա���ݵ�����
	const T& data() const;	//���ضԵ�ǰ��Ա���ݵĳ�����

	//��������ͷ����н����ڴ�ռ䡣�����������͡�operator=������
	void clear();

};

//���ʵ�ֲ���
template<class T>
Node<T> * Link<T>::newNode(const T &item, Node<T> *ptrNext/*=NULL*/) {
	Node<T> *p;
	p = new Node<T>(item, ptrNext);
	if (p == NULL) {
		cout << "Memory allocation failure" << endl;
		exit(1);
	}
	return p;
}

template<class T>
void Link<T>::freeNode(Node<T> *p) {
	delete p;
}

template<class T>
void Link<T>::copy(const Link<T>& L) {
	Node<T> *p = L.front;		//p������������L
	int pos;
	while (p != NULL) {
		InsertRear(p->data);
		p = p->nextNode();
	}
	if (position == -1) 		//�������Ϊ��
		return;
	//������������������prevPtr,currPtr
	prevPtr = NULL;
	currPtr = front;
	for (pos = 0;pos != position;pos++) {
		prevPtr = currPtr;
		currPtr = currPtr->nextNode();
	}

}


template<class T>
Link<T> ::Link() {
	front = NULL;
	rear = NULL;
	currPtr = NULL;
	prevPtr = NULL;
	size = 0;
	position = -1;
}

template<class T>
Link<T>::Link(const Link<T>& L) {
	front = rear = NULL;
	prevPtr = currPtr = NULL;
	size = 0;
	position = -1;
	copy(L);
}

template<class T>
Link<T>::~Link() {
	clear();
}


template<class T>
Link<T>& Link<T>::operator=(const Link<T>&L) {
	if (this == &L)		//���ܽ�����ֵ��������
		return *this;
	clear();
	copy(L);
	return *this;
}

template<class T>
int Link<T>::getSize() const {
	return size;
}

template<class T>
bool Link<T>::isEmpty() const {
	return size == 0;
}


template<class T>
void Link<T> :: reset(int pos/*=0*/) {
	int startPos;
	if (front == NULL)
		return;
	if (pos<0 || pos>size - 1) {		//���ָ��λ�ò��Ϸ�������
		cerr << "Reset:Invalid list position:" << pos << endl;
		return;
	}
	if (pos == 0) {		//���posΪ0����ָ���������õ���ͷ
		prevPtr = NULL;
		currPtr = front;
		position = 0;
	}
	else {			//������������currPtr,prevPtr,position
		currPtr = front->nextNode();
		prevPtr = front;
		startPos = 1;
		for (position = startPos;position != pos;position++) {
			prevPtr = currPtr;
			currPtr = currPtr->nextNode();
		}
	}
}

template<class T>
void Link<T>::next() {
	if (currPtr != NULL) {
		prevPtr = currPtr;
		currPtr = currPtr->nextNode();
		position++;
	}
}

template<class T>
bool Link<T>::endOfList()const {
	return currPtr == NULL;
}

template<class T>
int Link<T>::currentPosition(void)const {
	return position;
}

template<class T>
void Link<T>::insertFront(const T &item) {
	if (front != NULL)
		reset();
	insertAt(item);
}

template<class T>
void Link<T>::insertRear(const T &item) {
	Node<T> *p;
	prevPtr = rear;
	p = newNode(item);
	if (rear == NULL)
		front = rear = p;
	else {
		rear->insertAfter(p);
		rear = p;
	}
	currPtr = rear;
	position = size;
	size++;
}

template<class T>
void Link<T>::insertAt(const T &item) {
	Node<T> *nNode;
	if (prevPtr == NULL) {		//����������ͷ�������������뵽�ձ���
		nNode = newNode(item, front);
		front = nNode;
	}
	else {					//���뵽����֮�У����������prevPtr֮��
		nNode = newNode(item);
		prevPtr->insertAfter(nNode);
	}	
	if (prevPtr == rear) {		//������ձ��в��룬�����ǲ��뵽�ǿձ�ı�β
		rear = nNode;
		position = size;
	}
	currPtr = nNode;
	size++;
}

template<class T>
void Link<T>::insertAfter(const T &item) {
	Node<T> *p;
	p = newNode(item);
	if (front == NULL) {		//���뵽��������
		front = rear = currPtr = p;
		position = 0;
	}
	else {
		if (currPtr == NULL)
			currPtr = prevPtr;
		currPtr->insertAfter(p);
		if (currPtr == rear) {
			rear = p;		//����βָ��
			position = size;		//����λ��
		}
		else
			position++;
		prevPtr = currPtr;
		currPtr = p;
	}
	size++;
}

template<class T>
T Link<T>::deleteFront() {
	T item;
	reset();
	if (front == NULL) {
		cerr << "Invalid deletion!" << endl;
		exit(1);
	}
	item = currPtr->data;
	deleteCurrent();
	return item;
}

template<class T>
void Link<T>::deleteCurrent() {
	Node<T> *p;
	if (currPtr == NULL) {		//����Ϊ�ջ��ߵ����β
		cerr << "Invalid deletion!" << endl;
		exit(1);
	}
	if (prevPtr == NULL) {		//ɾ�������ڱ�ͷ
		p = front;
		front = front->nextNode();
	}
	else {	//����prevPtr֮���һ����㣬�������ַ
		p = prevPtr->deleteAfter();
	}
	if (p == rear) {
		rear = prevPtr;
		position--;
	}
	currPtr = p->nextNode();		//ʹcurrPtrԽ����ɾ���Ľ��
	freeNode(p);
	size--;
}

template<class T>
T& Link<T>::data() {
	if (size == 0 || currPtr == NULL) {
		cerr << "Data:invalid reference!" << endl;
		exit(1);
	}
	return currPtr->data;
}

template<class T>
void Link<T>::clear() {
	Node<T> *currPosition, *nextPosition;
	currPosition = front;
	while (currPosition != NULL) {
		nextPosition = currPosition->nextNode();
		freeNode(currPosition);
		currPosition = nextPosition;
	}
	front = rear = NULL;
	prevPtr = currPtr = NULL;
	size = 0;
	position = -1;
}
#endif
