#include <iostream>
template <class T>
class Table
{
private:
	T **mass;
	int x, y;
public:

	Table(const Table&) {}
	void Table::operator=(const Table&) {}
	

	Table(int a, int b): x(a), y(b) 
	{
		mass = new T * [a];
		for (int i = 0; i < a; i++)
			mass[i] = new T [b];
	}

	T* operator[](int a)
	{
		return mass[a];
	}

	const T* operator[](int a) const
	{
		return mass[a];
	}

	T* operator=(int a)
	{
		return mass = a;
	}


	~Table() 
	{
		for (int i = 0; i < x; i++)
			delete mass[i];
		delete[] mass;
	}
	
};

int main() {
	auto test = Table<int>(2, 3);
	test[0][0] = 4;
	std::cout << test[0][0]; // выводит 4

	Table<int> t1(2, 3);
	Table<int> t2(2, 3);

	t1 = t2;

	return 0;
}
