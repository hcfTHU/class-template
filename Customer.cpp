#include"Customer.h"

//ע���˺ţ��ֻ��ţ�
void Customer::setId(string my_id) {
	Id = my_id;
}

/*�˿�ѡ������ţ����ò�������*/
void Customer::setTable(int my_table_number) {
	table.setNumber(my_table_number);
	table.setState(order);			//ѡ�ò����󣬸ò����������״̬
}


//������µ�
void Customer::orderDishes() {
	
}

//ѡ�����
void Customer::checkOut() {
	table.setCheckOut();
}