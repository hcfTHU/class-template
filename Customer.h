#ifndef CUSTOMER_H
#define CUSTOMER_H
#include"Table.h"
#include<iostream>
using namespace std;
class Customer {
public:
	void setId(string my_id);				//ע���˺�
	void setTable(int my_table_number);		//ѡ�����
	void orderDishes();			//������µ��������ĵ���б�
								//�˿Ͳ鿴�˵���ѡ���Ʒ��ӵ�����б�
	void checkOut();			//���ˣ��˿Ϳ���ѡ���Ƿ����
private:
	string Id;
	int Table_number;
	Table table;
};
#endif // !CUSTOMER_H

