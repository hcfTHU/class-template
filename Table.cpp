#include"Table.h"

//��ʼ��
Table::Table(int my_number, State my_state) {
	number = my_number;
	state = my_state;

}

//���ý��ˣ���ʼ������
void Table::setCheckOut() {
	checkOut = 1;
	state = unoccupied;
}