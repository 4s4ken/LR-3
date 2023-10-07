#include<iostream>
#include<string>
#include <windows.h>
#include<math.h>
using namespace std;
bool Onecolor(int a, int b, int c, int d)
{
	int fir=0, sec=0;
	if (b % 2 == 0)
	{
		if (a % 2 != 0)
			fir = 1;
	}
	else if (a % 2 == 0)
		fir = 1;

		if (d % 2 == 0)
		{
			if (c % 2 != 0)
				sec = 1;
		}
		else if (c % 2 == 0)
			sec = 1;
	if (fir == sec)
		return 1;
	else
		return 0;
}
bool danger(string s, int a, int b, int c, int d)
{
	int z = abs(a - c), x = abs(b - d);
	if (s == "Конь")
	{
		if ((x == 2 && z == 1) || (x == 1 && z == 2))
			return 1;

		else
			return 0;
	}
	if (s == "Ладья")
	{

		if (z == 0 || x == 0)
			return 1;
		else
			return 0;
	}
	if (s == "Слон")
	{
		if(Onecolor(a,b,c,d)==false)
			return 0;
		if (z == x)
			return 1;
		else
			return 0;
	}
	if (s == "Ферзь")
	{
		if ((z == 0 || x == 0) || z == x || (x == 2 && z == 1))
			return 1;

		else
			return 0;
	}
}

bool danger2move(string s, int a, int b, int c, int d)
{
	int k = a, l = b, m = c, n = d;
	int z = abs(a - c), x = abs(b - d);
	if (s == "Конь")
	{
		if (a <= 6 && b <= 7)
			a += 2;b += 1;
		z = abs(a - c), x = abs(b - d);
		if ((x == 2 && z == 1) || (x == 1 && z == 2))
		{
			cout <<"(" << a << ";" << b <<") ";
			return 1;
		}
		a = k;b = l;

		if (a <= 7 && b <= 6)
			a += 1;b += 2;
		z = abs(a - c), x = abs(b - d);
			if ((x == 2 && z == 1) || (x == 1 && z == 2))
			{
				cout <<"(" << a << ";" << b <<") ";
				return 1;
			}
		a = k;b = l;

		 	if (a >= 3 && b <= 7)
		a -= 2;b += 1;
		z = abs(a - c), x = abs(b - d);
		if ((x == 2 && z == 1) || (x == 1 && z == 2))
		{
			cout << "(" << a << ";" << b << ") ";
			return 1;
		}
		a = k;b = l;

		if (a >= 1 && b <= 6)
			a -= 1;b += 2;
		z = abs(a - c), x = abs(b - d);
		if ((x == 2 && z == 1) || (x == 1 && z == 2))
		{
			cout << "(" << a << ";" << b << ") ";
			return 1;
		}
		a = k;b = l;

		if (a >= 2 && b >= 1)
			a -= 2;b -= 1;
		z = abs(a - c), x = abs(b - d);
			if ((x == 2 && z == 1) || (x == 1 && z == 2))
			{
				cout <<"(" << a << ";" << b <<") ";
				return 1;
			}
		a = k;b = l;

		if (a >= 1 && b >= 2)
			a -= 1;b -= 2;
		z = abs(a - c), x = abs(b - d);
			if ((x == 2 && z == 1) || (x == 1 && z == 2))
			{
				cout <<"(" << a << ";" << b <<") ";
				return 1;
			}
			if (a <= 6 && b >= 1)
				a += 2;b -= 1;
			z = abs(a - c), x = abs(b - d);
			if ((x == 2 && z == 1) || (x == 1 && z == 2))
			{
				cout << "(" << a << ";" << b << ") ";
				return 1;
			}
			a = k;b = l;

			if (a <= 7 && b >= 2)
				a += 1;b -= 2;
			z = abs(a - c), x = abs(b - d);
			if ((x == 2 && z == 1) || (x == 1 && z == 2))
			{
				cout << "(" << a << ";" << b << ") ";
				return 1;
			}
		a = k;b = l;
			return 0;
	}
	if (s == "Ладья")
	{
		int k = a, l = b, m = c, n = d;
		int z = abs(a - c), x = abs(b - d);
		a = 0;
		while (a <= 8)
		{

			a++;
			if (z == 0 || x == 0 && a!=k && b!=l)
			{
				cout <<"(" << a << ";" << b <<") ";
				return 1;
			}
		}
		a = k;
		b = 0;
		while (b <= 8)
		{
			b++;
			if (z == 0 || x == 0 && a != k && b != l  && a != m && b != n)
			{
				cout <<"(" << a << ";" << b <<") ";
				return 1;
			}
		}
			return 0;
	}
	if (s == "Слон")
	{
		if (Onecolor( a,  b,  c,  d) == false)
			return 0;
		int k = a, l = b, m = c, n = d;
		int q = min(a, b);
		q--;
		a -= q;
		b -= q;
		while (a < 8 && b < 8)
		{
			a++;b++;
			int z = abs(a - c), x = abs(b - d);
			if (z == x && a != k && b != l  && a != m && b != n)
			{
				cout <<"(" << a << ";" << b <<") ";
				return 1;
			}
		}
		a = k;b = l;
		q = 8 - a;
		b -= q;a += q;
		while (a > 0 && b < 8)
		{
			a--;b++;
				int z = abs(a - c), x = abs(b - d);
			if (z == x && a != k && b != l  && a != m && b != n)
			{
				cout <<"(" << a << ";" << b <<") ";
				return 1;
			}
		}
		return 0;
	}

	if (s == "Ферзь")
	{
	
		int k = a, l = b, m = c, n = d;
		int z = abs(a - c), x = abs(b - d);
			if (a <= 6 && b <= 7)
				a += 2;b += 1;
			z = abs(a - c), x = abs(b - d);
			if ((z == 0 || x == 0) || z == x || (x == 2 && z == 1))
			{
				cout <<"(" << a << ";" << b <<") ";
				return 1;
			}
			a = k;b = l;
			if (a <= 7 && b <= 6)
				a += 1;b += 2;
			z = abs(a - c), x = abs(b - d);
				if ((z == 0 || x == 0) || z == x || (x == 2 && z == 1))
				{
					cout <<"(" << a << ";" << b <<") ";
					return 1;
				}
			a = k;b = l;
			if (a >= 2 && b >= 1)
				a -= 2;b -= 1;
			z = abs(a - c), x = abs(b - d);
				if ((z == 0 || x == 0) || z == x || (x == 2 && z == 1))
				{
					cout <<"(" << a << ";" << b <<") ";
					return 1;
				}
			a = k;b = l;
			if (a >= 1 && b >= 2)
				a -= 1;b -= 2;
			z = abs(a - c), x = abs(b - d);
				if ((z == 0 || x == 0) || z == x || (x == 2 && z == 1))
				{
					cout <<"(" << a << ";" << b <<") ";
					return 1;
				}
			a = k;b = l;

			a = 0;
			while (a <= 8)
			{

				a++;
				if ((z == 0 || x == 0) || z == x || (x == 2 && z == 1) && a != k && b != l  && a != m && b != n)
				{
					cout <<"(" << a << ";" << b <<") ";
					return 1;
				}
			}
			a = k;
			b = 0;
			while (b <= 8)
			{
				b++;
				if ((z == 0 || x == 0) || z == x || (x == 2 && z == 1) && a != k && b != l  && a != m && b != n)
				{
					cout <<"(" << a << ";" << b <<") ";
					return 1;
				}
			}
			a = k;b = l;

			int q = min(a, b);
			q--;
			a -= q;
			b -= q;
			while (a <= 8 && b <= 8)
			{
				a++;b++;
					int z = abs(a - c), x = abs(b - d);
				if ((z == 0 || x == 0) || z == x || (x == 2 && z == 1) && a != k && b != l  && a != m && b != n)
				{
					cout <<"(" << a << ";" << b <<") ";
					return 1;
				}
			}
			a = k;b = l;
			q = 8 - a;
			b -= q;a += q;
			while (a >= 0 && b <= 8)
			{
				a--;b++;
					int z = abs(a - c), x = abs(b - d);
				if ((z == 0 || x == 0) || z == x || (x == 2 && z == 1) && a != k && b != l  && a != m && b != n)
				{
					cout <<"(" << a << ";" << b <<") ";
					return 1;
				}
			}
			return 0;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string s;
	int a, b, c, d;


	while(1)
	{
		cout << "Введите координаты своей фигуры:" << endl;
		cin >> a >> b;
		if (a>8 || a<=0 || b>8 || b<=0)
		{
			cout << "Ошибка вводы координат - неккоектные данные. Попробуйте снова начать ввод заново:" << endl;
			cin >> a >> b;
		}
		else
			break;
	}

	while (1)
	{
		cout << "Введите координаты фигуры-противника:" << endl;
		cin >> c >> d;
		if (c > 8 || c <= 0 || d>8 || d <= 0)
			{
				cout << "Ошибка вводы координат - неккоектные данные. Попробуйте снова начать ввод заново:" << endl;
				cin >> c >> d;
			}
			else
				break;
	}
	if (Onecolor(a, b, c, d)==true)
		cout << "Фигуры стоят на клетке одного цвета." << endl;
	else
		cout << "Фигуры стоят на клетках разного цвета." << endl;
	cout << endl << "Введите фигуру." << endl;
	cin >> s;
	cout << endl;
	while (1)
		if (s != "Ферзь" && s != "Ладья" && s != "Слон" && s != "Конь")
		{
			cout << "Вы допустили ошибку, попрообуйте снова!" << endl;
			cout << "Введите фигуру." << endl;
			cin >> s;
		}
		else
			break;
	int z = abs(a - c), x = abs(b - d);
	if (danger(s, a, b, c, d) == 1)
		cout << "Фигура угрожает за 1 ход!" << endl;
	else
		cout << "Фигура не угрожает за 1 ход!" << endl;

	if (danger2move(s, a, b, c, d) == true)
		cout << " - координаты первого хода, угрожает за 2 хода.";
	else
		cout << "Фигура не угрожает за 2 хода.";
}
