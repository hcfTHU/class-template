#ifndef QUEUE_H
#define QUEUE_H
#include<cassert>
#include"node.h"

template<class T>
class Queue {
private:
	Node<T> *front, *rear;
	int count;
public:
	Queue();						//���캯������ʼ����ͷָ�룬��βָ�룬Ԫ�ظ���
	void insert(const T	&item);		//��Ԫ�����
	T remove();						//Ԫ�س���
	void clear();					//��ն���
	const T &getFront() const;		//���ʶ���Ԫ��

	int getLength() const;			//����г��ȣ�Ԫ�ظ�����
	bool isEmpty() const;			//�ж϶��пշ�
	bool isFull() const;			//�ж϶�������
};

template<class T>
Queue<T>::Queue() { front = rear = 0; count = 0; }

template<class T>
void Queue<T>::insert(const T &item) {
	assert(!isFull());
	Node<T> *p = new Node<T> (item);
	if (rear == 0) {
		front = p;
	}
	else {
		rear->insertAfter(p);
	}
	count++;
	rear = p;
}

template<class T>
T Queue<T>::remove() {		//һ�����⣺�����������ͷָ��
	assert(!isEmpty());
	Node<T> *p = front->nextNode();
	T item;
	item = front->data;
	delete front;
	front = p;
	count--;
	return item;

}

template<class T>
void Queue<T>::clear() {
	Node<T> *curr, *next;
	curr = front;
	while (curr != 0) {
		next = curr->nextNode();
		delete(curr);
		curr = next;
	}
	front = rear = 0;
	count = 0;
}

template<class T>
const T& Queue<T>::getFront() const {
	cassert(!isEmpty());
	return front->data;
}

template<class T>
int Queue<T>::getLength() const {
	return count;
}

template<class T>
bool Queue<T>::isEmpty() const {
	return count == 0;
}

template<class T>
bool Queue<T>::isFull() const {
	return count == 50;
}
#endif
