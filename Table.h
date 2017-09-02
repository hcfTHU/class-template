//������
#ifndef TABLE_H
#define TABLE_H
#include<vector>
#include<iostream>
using namespace std;
typedef vector<string> Dishes;
enum State {unoccupied,order,ready};//������״̬�����У�����У����µ�

class Table {
public:
	Table() {}
	Table(int my_number, State my_state);					//��ʼ��
	void setNumber(int my_number) { number = my_number; }	//���ò�����
	void setState(State my_state) { state = my_state; }		//���ò���״̬
	void setCheckOut();										//���ý���
private:
	int number;		    //������
	State state;		//����״̬
	Dishes dishes;		//����б�
	int checkOut=0;		//�Ƿ����
};
#endif

