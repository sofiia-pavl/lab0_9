#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

enum Specialty { ��, ��, ��, ��, Բ };
string strSpecialty[] = { "��", "��", "��", "��", "Բ" };
struct Student
{
	string prizv;
	Specialty specialty;
	short unsigned kurs;
	short unsigned physic;
	short unsigned math;
	union
	{
		short unsigned programing;
		short unsigned metods;
		short unsigned pedagogika;
	};
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
	cout << "������ N: "; cin >> N;

	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);
	Best(s, N);
	double proc = LineSearch(s, N);
	cout << "������� ��������, �� ������� ������:" << endl;
		cout << proc << "%" << endl;
	return 0;
}

void Create(Student* s, const int N)
{
	int kurs, specialty{};
	for (int i = 0; i < N; i++)
	{
		cout << "�������" << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "�������"; getline(cin, s[i].prizv);
		cout << "����"; cin >> s[i].kurs;
		cout << "������ � ������"; cin >> s[i].physic;
		cout << "������ � ����������"; cin >> s[i].math;
		cout << " ������������ (0 - ��, 1 - ��, 2 - ��, 3 - ��, 4 - Բ): "; 
		cin >> specialty;
		s[i].specialty = (Specialty)specialty;
		switch (s[i].specialty)
		{
		case ��:
			cout << "������ � �������������"; cin >> s[i].programing;
			break;
		case ��:
			cout << "������ � ���������"; cin >> s[i].pedagogika;
			break;
		case ��:
			cout << "������ � ���������"; cin >> s[i].pedagogika;
			break;
		case ��:
			cout << "������ � ��������� ������"; cin >> s[i].metods;
			break;
		case Բ:
			cout << "������ � ���������"; cin >> s[i].pedagogika;
			break;
		}
	}
}

void Print(Student* s, const int N)
{
	cout << "========================================================================================================================"
		<< endl;
	cout << "| �   | �������  | ���� | ������������ |  Գ����  |  ����������  |  ���������������  |  ������� ������ | ��������� |"
		<< endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------";
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << " "
			<< "| " << setw(8) << right << strSpecialty[s[i].specialty] << "    "
			<< "| " << setw(4) << right << s[i].physic << "  "
			<< "| " << setw(6) << right << s[i].math << "  ";
		switch (s[i].specialty)
		{
		case 0:
			cout << "| " << setw(7) << right << s[i].programing << "     |" << setw(18) << "|" << setw << (13) << "|" << endl;
			break;
		case 3:
			cout << "| " << setw(15) << "|" << setw(10) << right << s[i].metods << "    |" << setw(13) << "|" << endl;
			break;
		case 1:
		case 2:
		case 4:
			cout << "| " << setw(15) << "|" << setw(18) << "|" << right << setw(7) << s[i].pedagogika << "    |" << endl;
			break;
		}
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	}
	cout << "==================================================================================================================" << endl;
}
void Best(Student* s, const int N)
{
	cout << "������� c�������, � ����� ��������� ������ ���:" << endl;
	double best = 0;
	double tmp;
	for (int i = 0; i < N; i++)
	{
		tmp = (s[i].physic + s[i].math + s[i].pedagogika) / 3;
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
				if (p[i].pedagogika == 5)
				{
					k++;

				}
	}
	return 100.0 * k / n;
}