//test.cpp
//16.01.2021
//Тестовое задание v.1

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
	//инициализация
	vector <int> v;
	map <int, int> m;
	int v_size, m_size;

	//Ввод
	cout << "Размер вектора = ";
	cin >> v_size;
	cout << "Размер словоря = ";
	cin >> m_size;

	//рандомизация
	srand(time(NULL));
	
	//заполнение вектора и словоря
	vector_input(v, v_size);
	map_input(m, m_size);

	//вывод вектора и словоря
	vector_output(v, v_size);
	map_output(m, m_size);

	//вызов функции выбора количества элементов
	short count = count_del_in_function(v_size);
	cout<< count<< " - количество удалений в векторе"<<endl;

	//вызов функции удаления случайного количества элементов в векторе
	vector_del(v, v.size(), count);
	//вызов функции вывода вектора
	vector_output(v, v.size());

	//вызов функции выбора количества элементов
	count = count_del_in_function(m_size);
	cout<< count<< " - количество удалений в словаре"<<endl;
	//вызов функции удаления случайного количества элементов в словаре
	map_del(m, m_size, count);
	//вызов функции вывода словоря
	map_output(m, m.size());
	
	//вызов функции синхронизации словоря и вектора
	two(m, m.size(),v,v.size());
	//вызов функции вывода словоря
	map_output(m, m.size());
	//вызов функции вывода вектора
	vector_output(v, v.size());

	system("pause");
	return 0;
}