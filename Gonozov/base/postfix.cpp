#include "polinom.h"



void Polinom::check(string e)
{
	if (e.size() == 0)
		throw "empty string";
	string c = "xyz+-0123456789";
	if (e.find_first_not_of(c) != std::string::npos)
		throw "invalid character in the string";

	int type_last = -1; // тип предыдущего элемента  1 - число, 2 - переменная, 3 - -операция
	for (int i = 0; i < e.length(); i++)
	{

		if (e[i] == 'x' || e[i] == 'y' || e[i] == 'z')
		{
			if (type_last == 2)
				throw "the degree of the variable is not entered";
			type_last = 2;
		}
		else if (e[i] == '+' || e[i] == '-')
		{
			if (type_last == 3)
				throw "two operations have been introduced in a row";
			type_last = 3;
		}
		else
		{
			if (type_last == 1)
				throw "two numbers go in a row";
			type_last = 1;
		}

	}
}

vector<string> Polinom::split(string e)
{
	vector<string> inf_monom;
	int startInd = 0, endInd = 0;
	for (int i = 0; i <= e.size(); i++)
	{
		if (e[i] == '+' || e[i] == '-' || i == e.size())
		{
			endInd = i;
			string help;
			help.append(e, startInd, endInd - startInd);
			inf_monom.push_back(help);
			startInd = endInd;
		}

	}
	return inf_monom;
}

Polinom::Polinom(string expr)
{
	{
		check(expr);
		vector<string> inf_monom;
		inf_monom = split(expr);
		Monom* p = nullptr;
		for (int i = 0; i < inf_monom.size(); i++)
		{
			int j = 0;
			int coef = 1;
			if (inf_monom[i][0] == '-')
			{
				coef = -1;
				if (inf_monom[i][1] != 'x' && inf_monom[i][1] != 'y' && inf_monom[i][1] != 'z')
				{
					coef *= (inf_monom[i][1]);
					j++;
				}
				j ++;
			}
			else if (inf_monom[i][0] == '+')
			{
				if (inf_monom[i][1] != 'x' && inf_monom[i][1] != 'y' && inf_monom[i][1] != 'z')
				{
					coef *= (inf_monom[i][1]);
					j++;
				}
				j ++;
			}
			else if (inf_monom[i][0] != 'x' && inf_monom[i][0] != 'y' && inf_monom[i][0] != 'z')
			{
				coef = (inf_monom[i][0] - '0');
				j++;
			}

			int alpha = 0, beta = 0, gamma = 0;

			for (j; j < inf_monom[i].size(); j++)
			{
				if (inf_monom[i][j] == 'x')
				{
					alpha = (inf_monom[i][j + 1] - '0');
				}
				if (inf_monom[i][j] == 'y')
				{
					beta = (inf_monom[i][j + 1] - '0');
				}
				if (inf_monom[i][j] == 'z')
				{
					gamma = (inf_monom[i][j + 1] - '0');
				}
			}
			if (p == nullptr)
			{
				pFirst = new Monom{ alpha * 100 + beta * 10 + gamma, coef, nullptr };
				p = pFirst;
			}
			else
			{
				Monom* pp = new Monom{ alpha * 100 + beta * 10 + gamma, coef, nullptr };
				p->pNext = pp;
				p = p->pNext;
			}
		}
		Monom* pp = new Monom{ 0, 0, nullptr }; // добавление фиктивного монома
		p->pNext = pp;

	}
}


vector<pair<int, int>> Polinom::get_information()
{
	vector<pair<int, int>> res;
	Monom* p = pFirst;
	while (p != nullptr)
	{
		pair<int, int> h;
		h.first = p->coef;
		h.second = p->degrees;
		res.push_back(h);
		p = p->pNext;
	}
	return res;
}

Polinom Polinom::operator+(const Polinom& pol) const
{
	Polinom a;
	Monom* p = pFirst;
	Monom* f = pol.pFirst;
	Monom* h = nullptr;

	if (p->degrees > f->degrees)
	{
		Monom* pp = new Monom{ p->degrees, p->coef, nullptr };
		a.pFirst = pp;
		h = pp;
		p = p->pNext;
	}
	else if (p->degrees < f->degrees)
	{
		Monom* pp = new Monom{ f->degrees, f->coef, nullptr };
		a.pFirst = pp;
		h = pp;
		f = f->pNext;
	}
	else if (p->degrees == f->degrees)
	{
		Monom* pp = new Monom{ p->degrees, p->coef + f->coef, nullptr };
		a.pFirst = pp;
		h = pp;
		p = p->pNext;
		f = f->pNext;
	}
	while (p != nullptr && f != nullptr)
	{
		if (p->degrees > f->degrees)
		{

			Monom* pp = new Monom{ p->degrees, p->coef, nullptr };
			h->pNext = pp;
			h = h->pNext;
			p = p->pNext;
		}
		else if (p->degrees < f->degrees)
		{
			Monom* pp = new Monom{ f->degrees, f->coef, nullptr };
			h->pNext = pp;
			f = f->pNext;
			h = h->pNext;
		}
		else if (p->degrees == f->degrees)
		{
			Monom* pp = new Monom{ p->degrees, p->coef + f->coef, nullptr };
			h->pNext = pp;
			p = p->pNext;
			f = f->pNext;
			h = h->pNext;
		}
	}
	return a;
}

Polinom Polinom::operator-(const Polinom& pol) const
{
	Polinom a;
	Monom* p = pFirst;
	Monom* f = pol.pFirst;
	Monom* h = nullptr;

	if (p->degrees > f->degrees)
	{
		Monom* pp = new Monom{ p->degrees, p->coef, nullptr };
		a.pFirst = pp;
		h = pp;
		p = p->pNext;
	}
	else if (p->degrees < f->degrees)
	{
		Monom* pp = new Monom{ f->degrees, -1 * f->coef, nullptr };
		a.pFirst = pp;
		h = pp;
		f = f->pNext;
	}
	else if (p->degrees == f->degrees)
	{
		Monom* pp = new Monom{ p->degrees, p->coef - f->coef, nullptr };
		a.pFirst = pp;
		h = pp;
		p = p->pNext;
		f = f->pNext;
	}
	while (p != nullptr && f != nullptr)
	{
		if (p->degrees > f->degrees)
		{

			Monom* pp = new Monom{ p->degrees, p->coef, nullptr };
			h->pNext = pp;
			h = h->pNext;
			p = p->pNext;
		}
		else if (p->degrees < f->degrees)
		{
			Monom* pp = new Monom{ f->degrees, -1 * f->coef, nullptr };
			h->pNext = pp;
			f = f->pNext;
			h = h->pNext;
		}
		else if (p->degrees == f->degrees)
		{
			Monom* pp = new Monom{ p->degrees, p->coef - f->coef, nullptr };
			h->pNext = pp;
			p = p->pNext;
			f = f->pNext;
			h = h->pNext;
		}
	}
	return a;
}

Polinom& Polinom::operator=(const Polinom& pol)
{
	Monom* p = pol.pFirst;
	pFirst = new Monom{ p->degrees, p->coef, nullptr };
	Monom* fr = pFirst;
	p = p->pNext;
	while (p != nullptr)
	{
		Monom* pp = new Monom{ p->degrees, p->coef, nullptr };
		fr->pNext = pp;
		p = p->pNext;
	}
	return *this;
}

Polinom Polinom::operator*(int value) const
{
	Polinom a;
	a.pFirst = new Monom{ (pFirst->coef) * value, pFirst->degrees, nullptr };
	Monom* h = a.pFirst;
	for (Monom* p = pFirst->pNext; p != nullptr; p = p->pNext)
	{
		Monom* pp = new Monom{ p->degrees, p->coef, nullptr };
		h->pNext = pp;
	}
	return a;
}

double Polinom::calculate_at_point(double x_, double y_, double z_)
{
	double result = 0;
	for (Monom* p = pFirst; p != nullptr; p = p->pNext)
	{
		result += p->coef * pow(x_, p->degrees % 1000 / 100) * pow(y_, p->degrees % 100 / 10) * pow(y_, p->degrees % 10);
	}
	return result;
}
