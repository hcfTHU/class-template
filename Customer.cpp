#include"Customer.h"
//ע���˺ţ��ֻ��ţ�
void Customer::setId(std::string my_id) {
	Id = my_id;
}

/*�˿�ѡ������ţ����ò�������*/
void Customer::setTable(int my_table_number) {
	table.setNumber(my_table_number);
	table.setState(order);			//ѡ�ò����󣬸ò����������״̬
}


//������µ�
void Customer::orderDishes() {
	int dish_number;
	for (int i = 0;;i++) {
		cin >> dish_number;
		table.orderDishes(dish_number, i);
	}

}

//ѡ�����
void Customer::checkOut() {
	table.setCheckOut();
}

void Customer::evaluate() {
}