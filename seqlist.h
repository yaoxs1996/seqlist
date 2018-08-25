//顺序表C++模板实现
#pragma once
#include<iostream>
using std::cout;
using std::endl;

const int defaultSize = 100;

template <typename T>
class SeqList
{
private:
	T *m_elements;
	const int m_nmaxsize;
	int m_ncurrentsize;

public:
	SeqList(int sz = defaultSize) :m_nmaxsize(sz), m_ncurrentsize(-1)
	{
		if (sz > 0)
		{
			m_elements = new T[m_nmaxsize];
		}
	}

	~SeqList()
	{
		delete[] m_elements;
	}

	int length() const		//表长
	{
		return m_ncurrentsize + 1;
	}

	int find(T x) const;		//按值查找，返回位置
	int isElement(T x) const;		//元素是否在表内
	int insert(T x, int i);		//按位置插入
	int remove(T x);		//按值删除
	int isEmpty()		//判空
	{
		return m_ncurrentsize == -1;
	}
	int isFull()		//判满
	{
		return m_ncurrentsize == m_nmaxsize - 1;
	}

	T get(int i)		//按位置查找元素
	{
		return i<0 || i>m_ncurrentsize ? (cout << "can't find the element " << endl, 0) : m_elements[i];
	}

	void print();
};

template<typename T>
int SeqList<T>::find(T x) const
{
	for (int i = 0; i < m_nmaxsize; i++)
		if (m_elements[i] == x)
			return i;

	cout << "can't find the element you want to find" << endl;
	return -1;
}

template<typename T>
int SeqList<T>::isElement(T x) const
{
	if (find(x) == -1)
		return 0;
	return 1;
}

template<typename T>
int SeqList<T>::insert(T x, int i)
{
	if (i<0 || i>m_ncurrentsize + 1 || m_ncurrentsize == m_nmaxsize - 1)
	{
		cout << "the operation is illegal" << endl;
		return 0;
	}
	m_ncurrentsize++;
	for (int j = m_ncurrentsize; j > i; j--)
	{
		m_elements[j] = m_elements[j - 1];
	}
	m_elements[i] = x;
	return 1;
}

template<typename T>
int SeqList<T>::remove(T x)
{
	int size = m_ncurrentsize;
	for (int i = 0; i < m_ncurrentsize;)
	{
		if (m_elements[i] == x)
		{
			for (int j = i; j < m_ncurrentsize; j++)
			{
				m_elements[j] = m_elements[j + 1];
			}
			m_ncurrentsize--;
			continue;
		}
		i++;
	}
	if (size == m_ncurrentsize)
	{
		cout << "can't find the element you want to remove" << endl;
		return 0;
	}
	return 1;
}

template<typename T>
void SeqList<T>::print()
{
	for (int i = 0; i <= m_ncurrentsize; i++)
		cout << i + 1 << ":\t" << m_elements[i] << endl;
	cout << endl << endl;
}