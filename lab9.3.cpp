#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;
struct Price
{
	string name;
	string shop;
	double price;
};
void Create(Price* p, const int N);
void Print(Price* p, const int N);
int BinSearch(Price* p, const int N, const string shop);
void Sort(Price* p, const int N);
void SaveToFile(Price* p, const int N, const char* filename);
void LoadFromFile(Price*& p, int& N, const char* filename);
int main()
{ 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 

	int N;
	cout << "������ ������� N: "; cin >> N;

	Price* p = new Price[N];
	int iposada;
	string name;
	string shop;
	int found;
	char filename[100];
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [4] - ������� ������������� �����" << endl;
		cout << " [5] - ������� ����� ���������� �� ������� �� ��������" << endl;
		cout << " [7] - ����� ����� � ����" << endl;
		cout << " [8] - ���������� ����� �� �����" << endl << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 4:
			Sort(p, N);
			break;
		case 5:
			cin.get(); 
			cin.sync(); 

			cout << " ����� ��������: "; cin>> shop;
			cout << endl;
			if ((found = BinSearch(p, N, shop)) != -1)
				cout << "�������� � ������� " << found + 1 << endl;
			else
				cout << "�������� �� ��������" << endl;
			break;
		case 7:
			cin.get(); 
			cin.sync(); 

			cout << "������ ��'� �����: "; cin.getline(filename, 99);
			SaveToFile(p, N, filename);
			break;
		case 8:
			cin.get(); 
			cin.sync();

			cout << "������ ��'� �����: "; cin.getline(filename, 99);
			LoadFromFile(p, N, filename);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Price* p, const int N)
{
	int posada;
	for (int i = 0; i < N; i++)
	{
		cout << "Price � " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

		cout << " ����� ������: "; getline(cin, p[i].name);
		cout << " ����� ��������: "; getline(cin, p[i].shop);
		cout << " ������� � ���: "; cin >> p[i].price;
		cout << endl;
	}
}
void Print(Price* p, const int N)
{
	cout << "================================================="
		<< endl;
	cout << "| � | ����� ������ | ������� | ������� � ��� |"
		<< endl;
	cout << "-------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].name
			<< "| " << setw(4) << right << p[i].shop << " "
			<< "| " << setw(11) << left << p[i].price;
		cout << endl;
	}
	cout << "=================================================="
		<< endl;
	cout << endl;
}
void Sort(Price* p, const int N)
{
	Price tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((p[i1].name > p[i1 + 1].name))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}
int BinSearch(Price* p, const int N, const string shop)
{ 
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (p[m].shop == shop)
			return m;
		if ((p[m].shop < shop))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}
void SaveToFile(Price* p, const int N, const char* filename)
{
	ofstream fout(filename, ios::binary); // ������� ������� ���� ������
	fout.write((char*)&N, sizeof(N)); // �������� ������� ��������
	for (int i = 0; i < N; i++)
		fout.write((char*)&p[i], sizeof(Price)); // �������� �������� ������
	fout.close(); // ������� ����
}
void LoadFromFile(Price*& p, int& N, const char* filename)
{
	delete[] p; 
	ifstream fin(filename, ios::binary); 
	fin.read((char*)&N, sizeof(N)); 
	p = new Price[N]; 
	for (int i = 0; i < N; i++)
		fin.read((char*)&p[i], sizeof(Price)); 
	fin.close(); 
}