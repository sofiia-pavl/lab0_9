#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

enum Specialty { КН, МЕ, ТН, ІФ, ФІ };
string strSpecialty[] = { "КН", "МЕ", "ТН", "ІФ", "ФІ" };
struct Student
{
	string prizv;
	Specialty specialty;
	short unsigned kurs;
	short unsigned physic;
	short unsigned math;
	short unsigned inform;
};
void Create(Student* s, const int N);
void Print(Student* s, const int N);
void Best(Student* s, const int N);
double LineSearch(Student* p, const int N);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "Введіть N: "; cin >> N;

	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);
	Best(s, N);
	double proc = LineSearch(s, N);
	cout << "Процент студентів, які вчаться відмінно:" << endl;
	cout << proc << "%" << endl;
	return 0;
}
void Create(Student* s, const int N)
{
	int kurs, specialty{};
	for (int i = 0; i < N; i++)
	{
		cout << "Студент№" << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "прізвище"; getline(cin, s[i].prizv);
		cout << "курс"; cin >> s[i].kurs;
		cout << "оцінка з фізики"; cin >> s[i].physic;
		cout << "оцінка з математики"; cin >> s[i].math;
		cout << " спеціальність (0 - КН, 1 - МЕ, 2 - ТН, 3 - ІФ, 4 - ФІ): ";
		cin >> specialty;
		s[i].specialty = (Specialty)specialty;
	}
}
void Print(Student* s, const int N)
{
	cout << "===================================================================================="
		<< endl;
	cout << "| №   | Прізвище  | Курс | Спеціальність |  Фізика  |  Математика  |  Інформатика  |"
		<< endl;
	cout << "-------------------------------------------------------------------------------------";
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << " "
			<< "| " << setw(8) << right << strSpecialty[s[i].specialty] << "    "
			<< "| " << setw(4) << right << s[i].physic << "  "
			<< "| " << setw(6) << right << s[i].math << "  "
			<< "| " << setw(4) << right << s[i].inform;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	}
cout << "==================================================================================================================" << endl;
}
void Best(Student* s, const int N)
{
	cout << "Прізвище cтудента, у якого найкращий сердній бал:" << endl;
	double best = 0;
	double tmp;
	for (int i = 0; i < N; i++)
	{
		tmp = (s[i].physic + s[i].math + s[i].inform) / 3;
	}
	if (tmp > best)
		best = tmp;
	for (int j = 0; j < N; j++)
		if (tmp == best)
			cout << setw(3) << right
			<< " " << s[j].prizv << endl;
}
double LineSearch(Student* p, const int N)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		n++;
		if (p[i].physic == 5)
			if (p[i].math == 5)
				if (p[i].inform == 5)
				{
					k++;

				}
	}
	return 100.0 * k / n;
}