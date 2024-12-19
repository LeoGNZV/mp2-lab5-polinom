#include <iostream>
#include <string>
#include "polinom.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Добро пожаловать в программу, позволяющую работать с полиномами" << endl;
	cout << "Вам доступны некторые действия, каждое из которых выбирается нажатием определённой цифры" << endl;
	cout << "1.Ввод полинома\n2.Вывод таблицы полиномов\n3.Вычисление полинома в точке\n4.Сложить полиномы\n5.Вычесть полиномы\n6.Умножить полином на константу\n7.Выход из программы\n\n";
	vector<Polinom> polinomials;
	int meneger;

	do 
	{
		cout << "Следующая операция: ";
		cin >> meneger;
		cout << "\n";
		switch (meneger)
		{
		case 1:
		{
			cout << "Введите полином: ";
			string expression;
			cin >> expression;
			cout << "\n";
			Polinom a(expression);
			polinomials.push_back(a);
			break;
		}
		case 2:
		{
			if (polinomials.size() == 0)
			{
				cout << "Введите полиномы прежде чем выводить таблицу\n";
			}
			else
			{
				for (int i = 0; i < polinomials.size(); i++)
				{
					vector<pair<int, int>> pol = polinomials[i].get_information();
					for (int j = 0; j < pol.size()-1; j++)
					{
						if (pol[j].first != 0 && pol[j].second != 0)
						{
							if (pol[j].first > 0 && j != 0)
							{
								cout << "+";
							}
							if (pol[j].first != 0)
								cout << pol[j].first;
							if (pol[j].second % 1000 / 100 != 0)
								cout << "x" << pol[j].second % 1000 / 100;
							if (pol[j].second % 100 / 10 != 0)
								cout << "y" << pol[j].second % 100 / 10;
							if (pol[j].second % 10 != 0)
								cout << "z" << pol[j].second % 10;
						}
					}
					cout << "\n";
				}
			}
			break;
		}
		case 3:
		{
			if (polinomials.size() == 0)
			{
				cout << "Введите полиномы прежде чем выполнять операцию\n";
			}
			else
			{
				cout << "Введите номер полинома, для которого хотите вычислить значение (нумерация с нуля)\n";
				int o;
				cin >> o;
				while (o < 0 || o >= polinomials.size())
				{
					cout << "Введите номер полинома, который будет существовать в таблице полиномов: ";
					cin >> o;
					cout << "\n";
				}
				int o1, o2, o3;
				cout << "Введите точку x: ";
				cin >> o1;
				cout << "\n";
				cout << "Введите точку y: ";
				cin >> o2;
				cout << "\n";
				cout << "Введите точку z: ";
				cin >> o3;
				cout << "\n";
				cout << polinomials[o].calculate_at_point(o1, o2, o3) << endl;
			}
			break;
		}
		case 4:
		{
			if (polinomials.size() == 0)
			{
				cout << "Введите полиномы прежде чем выполнять операцию\n";
			}
			else
			{
				cout << "Введите номера полиномов, которые хотите использовать для вычисления: ";
				int i1, i2;
				cin >> i1 >> i2;
				while (i1 < 0 || i1 >= polinomials.size())
				{
					cout << "Введите корректный номер первого полинома, который будет существовать в таблице полиномов: ";
					cin >> i1;
					cout << "\n";
				}
				while (i1 < 0 || i1 >= polinomials.size())
				{
					cout << "Введите корректный номер второго полинома, который будет существовать в таблице полиномов: ";
					cin >> i1;
					cout << "\n";
				}
				
				polinomials.push_back(polinomials[i1] + polinomials[i2]);
				vector<pair<int, int>> pol = (polinomials[i1] + polinomials[i2]).get_information();
				for (int j = 0; j < pol.size() - 1; j++)
				{
					if (pol[j].first != 0 && pol[j].second != 0)
					{
						if (pol[j].first > 0 && j != 0)
						{
							cout << "+";
						}
						if (pol[j].first != 0)
							cout << pol[j].first;
						if (pol[j].second % 1000 / 100 != 0)
							cout << "x" << pol[j].second % 1000 / 100;
						if (pol[j].second % 100 / 10 != 0)
							cout << "y" << pol[j].second % 100 / 10;
						if (pol[j].second % 10 != 0)
							cout << "z" << pol[j].second % 10;
					}
				}
				if (pol.size() == 1)
					cout << "0";
				cout << "\n";
			}
			break;
		}
		case 5:
		{
			if (polinomials.size() == 0)
			{
				cout << "Введите полиномы прежде чем выполнять операцию\n";
			}
			else
			{
				cout << "Введите номера полиномов, которые хотите использовать для вычисления: ";
				int i1, i2;
				cin >> i1 >> i2;
				while (i1 < 0 || i1 >= polinomials.size())
				{
					cout << "Введите корректный номер первого полинома, который будет существовать в таблице полиномов: ";
					cin >> i1;
					cout << "\n";
				}
				while (i1 < 0 || i1 >= polinomials.size())
				{
					cout << "Введите корректный номер второго полинома, который будет существовать в таблице полиномов: ";
					cin >> i1;
					cout << "\n";
				}

				polinomials.push_back(polinomials[i1] - polinomials[i2]);
				vector<pair<int, int>> pol = (polinomials[i1] - polinomials[i2]).get_information();
				for (int j = 0; j < pol.size() - 1; j++)
				{
					if (pol[j].first != 0 && pol[j].second != 0)
					{
						if (pol[j].first > 0 && j != 0)
						{
							cout << "+";
						}
						if (pol[j].first != 0)
							cout << pol[j].first;
						if (pol[j].second % 1000 / 100 != 0)
							cout << "x" << pol[j].second % 1000 / 100;
						if (pol[j].second % 100 / 10 != 0)
							cout << "y" << pol[j].second % 100 / 10;
						if (pol[j].second % 10 != 0)
							cout << "z" << pol[j].second % 10;
					}
				}
				if (pol.size() == 1)
					cout << "0";
				cout << "\n";
			}
			break;
		}
		case 6:
		{
			if (polinomials.size() == 0)
			{
				cout << "Введите полином прежде чем выполнять операцию\n";
			}
			else
			{
				cout << "Введите номер полинома, который хотите использовать для вычисления: ";
				int i1;
				cin >> i1;
				while (i1 < 0 || i1 >= polinomials.size())
				{
					cout << "Введите корректный номер полинома, который будет существовать в таблице полиномов: ";
					cin >> i1; ;
					cout << "\n";
				}
				int i2;
				cout << "Введите значение константы: ";						
				cin >> i2;
				cout << "\n";

				polinomials.push_back(polinomials[i1] * i2);
				vector<pair<int, int>> pol = (polinomials[i1] * i2).get_information();
				for (int j = 0; j < pol.size() - 1; j++)
				{
					if (pol[j].first != 0 && pol[j].second != 0)
					{
						if (pol[j].first > 0 && j != 0)
						{
							cout << "+";
						}
						if (pol[j].first != 0)
							cout << pol[j].first;
						if (pol[j].second % 1000 / 100 != 0)
							cout << "x" << pol[j].second % 1000 / 100;
						if (pol[j].second % 100 / 10 != 0)
							cout << "y" << pol[j].second % 100 / 10;
						if (pol[j].second % 10 != 0)
							cout << "z" << pol[j].second % 10;
					}
				}
				if (pol.size() == 1)
					cout << "0";
				cout << "\n";

			}
			break;
		}
		default:
		{ break; }
		}
	} while (meneger != 7);
	
	return 0;
}
