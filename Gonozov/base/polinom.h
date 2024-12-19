#include <iostream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;


class Polinom
{
	struct Monom
	{
		int degrees;
		int coef;
		Monom* pNext;
	};
	Monom* pFirst = nullptr;
	size_t sz;     // ????????????? надо ли??? всё же добавить в конструкторы инициализацию

	void check(string e);
	vector<string> split(string e);
	Polinom() { }

public:
	Polinom(string expr);
	vector<pair<int, int>> get_information();

	~Polinom()
	{
		if (pFirst)
			return;
		for (Monom* p = pFirst->pNext; p != nullptr; p = p->pNext)
		{
			delete pFirst;
			pFirst = p;
		}
		delete pFirst;
	}
	double calculate_at_point(double x_, double y_, double z_);

	Polinom operator+(const Polinom& pol) const;
	Polinom operator-(const Polinom& pol) const;
	Polinom operator*(int value) const;

	Polinom& operator=(const Polinom& pol);
};