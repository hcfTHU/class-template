#ifndef QUEUE_H
#define QUEUE_H
#include<cassert>

template<class T, int SIZE=50>
class Queue {
private:
	int front, rear, count;	//��ͷָ�룬��βָ�룬Ԫ�ظ���
	T list[SIZE];
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

template<class T,int SIZE>
Queue<T, SIZE>::Queue():front(0),rear(0),count(0){}

template<class T, int SIZE>
void Queue<T, SIZE>::insert(const T &item) {
	assert(count != SIZE);
	count++;
	list[rear] = item;
	rear = (rear + 1)&SIZE;
}

template<class T, int SIZE>
T Queue<T,SIZE>::remove(){
	assert(count != 0);
	int temp = front;
	count--;
	front = (front + 1) % SIZE;
	return list[temp];
}

template<class T, int SIZE>
const T &Queue<T, SIZE>::getFront() const {
	return list[front];
}

template<class T, int SIZE>
int Queue<T, SIZE>::getLength() const {
	return count;
}

template<class T, int SIZE>
bool Queue<T, SIZE>::isEmpty() const {
	return count == 0;
}

template<class T, int SIZE>
bool Queue<T, SIZE>::isFull() const {
	return count == SIZE;
}

template<class T, int SIZE>
void Queue<T, SIZE>::clear() {
	count = 0;
	front = 0;
	rear = 0;
}

#endif
