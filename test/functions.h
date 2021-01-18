//functions.h
//16.01.2021
//Тестовое задание v.1

#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <time.h>
#include <algorithm>

using namespace::std;

//функция заполнения вектора
void vector_input(vector<int> &v, int v_size) // ?
{
	for(int i = 0; i < v_size; i++){
		short k = rand()%9 + 1;
		v.push_back(k);
	}
}

//функция заполнения словоря
void map_input(map <int,int> &m, int m_size)
{
	for(int i = 0; i < m_size; i++){
		int k = rand()%9 + 1;
		m[i] = k;
	}
}

//функция вывода вектора
void vector_output(vector<int> &v, int v_size) // ?
{
	cout<< "Вектор:" << endl;
	for(int i = 0; i < v_size; i++){
		cout<<"vector["<<i<<"] = "<<v[i]<<endl;
	}
}

//функция вывода словоря
void map_output(map <int,int> &m, int m_size) // ?
{
	cout<<"Словарь:"<<endl;
	map <int, int>::iterator it1;
	for (it1 = m.begin(); it1 != m.end(); ++it1)
		cout << it1->first << "->" << it1->second << endl;
}

//функция выбора количества элементов до 15
int count_del_in_function(int v_size){
	short count_del;
	if (v_size <= 15){
		count_del = rand()%v_size;
	}
	if (v_size > 15){
		count_del = rand()%15;
	}
	return count_del;
}

//функция удаления случайных элементов в векторе
void vector_del(vector<int> &v, int v_size,int count)
{
	short r;
	for(int i = 0; i < v_size; i++){
		if (i < count){
			r = rand()%(v_size - i);
			v.erase(v.begin() + r);
		}
		else
			break;
	}	
}

//функция удаления случайных элементов в словаре
void map_del(map <int,int> &m, int m_size,int count) // ?
{
	map <int, int>::iterator it1;
	short r;
	vector <int> chet;
	for(int i = 0; i < m_size; i++){
		if (i < count){
			r = rand()%(m_size - i);
			if (find(chet.begin(),chet.end(),r) == chet.end()){
				chet.push_back(r);
				it1 = m.find(r);
				m.erase(it1);
			}
		}
		else{
			break;
		}
	}	
}

//функция синхронизации элементов в словаре и векторе
void two(map <int,int> &m, int m_size, vector<int> &v, int v_size){
	map <int, int>::iterator it;
	it = m.begin();
	while(it !=m.end()){
		if (find(v.begin(),v.end(), it->second) == v.end()){
			m.erase(it++);
		}
		else{
			it++;
		}

	}
	int proverka = 0;
		for(int i = 0; i < v.size(); i++){
			int proverka = 0;
			for (it = m.begin(); it!=m.end(); it++){
				if (v[i] == it->second){
					proverka++;
				}
			}
		if(proverka == 0){
			v.erase(std::remove(v.begin(), v.end(), v[i]), v.end());
			i--;
			}
		}
}