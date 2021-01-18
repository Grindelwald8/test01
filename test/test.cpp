//test.cpp
//16.01.2021
//�������� ������� v.1

#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <time.h>
#include <algorithm>
#include "functions.h"

using namespace::std;


int main(){
	setlocale( LC_ALL, "Russian" );
	//�������������
	vector <int> v;
	map <int, int> m;
	int v_size, m_size;

	//����
	cout << "������ ������� = ";
	cin >> v_size;
	cout << "������ ������� = ";
	cin >> m_size;

	//������������
	srand(time(NULL));
	
	//���������� ������� � �������
	vector_input(v, v_size);
	map_input(m, m_size);

	//����� ������� � �������
	vector_output(v, v_size);
	map_output(m, m_size);

	//����� ������� ������ ���������� ���������
	short count = count_del_in_function(v_size);
	cout<< count<< " - ���������� �������� � �������"<<endl;

	//����� ������� �������� ���������� ���������� ��������� � �������
	vector_del(v, v.size(), count);
	//����� ������� ������ �������
	vector_output(v, v.size());

	//����� ������� ������ ���������� ���������
	count = count_del_in_function(m_size);
	cout<< count<< " - ���������� �������� � �������"<<endl;
	//����� ������� �������� ���������� ���������� ��������� � �������
	map_del(m, m_size, count);
	//����� ������� ������ �������
	map_output(m, m.size());
	
	//����� ������� ������������� ������� � �������
	two(m, m.size(),v,v.size());
	//����� ������� ������ �������
	map_output(m, m.size());
	//����� ������� ������ �������
	vector_output(v, v.size());

	system("pause");
	return 0;
}