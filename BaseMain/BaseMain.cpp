#include <locale>
#include "pch.h"
#include <iostream>
#include <fstream>
#include<string>
#include <iomanip>
#include <cstdio>
#include "Windows.h"

using namespace std;



struct Students
{
	string Name, Last_Name, First_Name;
	int gruppa;
	int dohod;
	double sb;

}
arrstud[100];
int kol;

void add() //Заполнение данными
{
	ofstream F;
	F.open("F.txt");
	cout << "Введите количество студентов >>";
	cin >> kol;
	cout << endl;
	for (int i = 0; i < kol; i++)
	{
		cout << "Введите фамилию >> " ;

		cin >> arrstud[i].First_Name;
		F << arrstud[i].First_Name << endl;
		cout << "Введите имя >> " ;

		cin >> arrstud[i].Name;
		F << arrstud[i].Name << endl;
		cout << "Введите отчество >> " ;

		cin >> arrstud[i].Last_Name;
		F << arrstud[i].Last_Name << endl;
		cout << "Введите номер группы >> " ;

		cin >> arrstud[i].gruppa;
		F << arrstud[i].gruppa << endl;

		cout << "Введите средний балл >> " ;
		cin >> arrstud[i].sb;
		F << arrstud[i].sb << endl;

		cout << "Введите доход на чел-ка >> " ;
		cin >> arrstud[i].dohod;
		F << arrstud[i].dohod << endl;
		cout << endl;
		F << endl;
	}
	cout << endl;
	F.close();
}

void present() //Вывод данных

{
	ifstream Fi;
	Fi.open("F.txt");
	cout << "" << endl;
	char s;
	while (Fi.get(s))
	{
		cout << s;
	}
	cout << endl;
	Fi.close();
}

void clear()
{
	ofstream FDel;
	ofstream FOut;
	FDel.open("F.txt", ios::out);
	FOut.open("out.txt", ios::out);
	FDel.clear();
	FOut.clear();
	FDel.close();
	FOut.close();
}

Students buf;



void EditRec()
{
	string Edit_FName;;
	ifstream F;
	F.open("F.txt");
	if (!F.good())
	{
		cout << "Файл не найден.\n";
		return;
	}
	cout << "Введите слово: ";
	cin >> Edit_FName;

	cout << "\nРезультаты поиск по фамилии:\n" << endl;
	string First_Name, Name, Last_Name, gruppa, sb, dohod;
	cout << "Фамилия |  Имя  | Отчество | Номер группы | Средний балл | Доход на чел-ка" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	int i = 0;
	

	
}

void search() //поиск по фамилии
{
	
	bool find = false;
	string S_First_Name;
	ifstream F;
	F.open("F.txt");
	if (!F.good())
	{
		cout << "Файл не найден.\n";
		return;
	}
	cout << "Введите слово: ";
	cin >> S_First_Name;

	cout << "\nРезультаты поиск по фамилии:\n" << endl;
	string First_Name, Name, Last_Name, gruppa, sb, dohod;
	cout << "Фамилия |  Имя  | Отчество | Номер группы | Средний балл | Доход на чел-ка" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	int i = 0;
	while (F >> arrstud[i].First_Name >>
		arrstud[i].Name >>
		arrstud[i].Last_Name >>
		arrstud[i].gruppa >>
		arrstud[i].sb >>
		arrstud[i].dohod)
	{
		
		if (arrstud[i].First_Name == S_First_Name)
			cout << arrstud[i].First_Name
			<< setw(10) << arrstud[i].Name
			<< setw(12) << arrstud[i].Last_Name
			<< setw(10) << arrstud[i].gruppa
			<< setw(12) << arrstud[i].sb
			<< setw(16) << arrstud[i].dohod << endl;

	}
	cout << "" << endl;
	
	F.close();

}

void edit()
{
	ofstream F;
	F.open("F.txt", ios::app);
	cout << "Введите количество студентов >> ";
	cin >> kol;
	for (int i = 0; i < kol; i++)
	{
		cout << "Введите ФИО >> " << endl;

		cin >> arrstud[i].First_Name;
		F << arrstud[i].First_Name << endl;
		cout << "Введите имя >> " << endl;

		cin >> arrstud[i].Name;
		F << arrstud[i].Name << endl;
		cout << "Введите отчество >> " << endl;

		cin >> arrstud[i].Last_Name;
		F << arrstud[i].Last_Name << endl;
		cout << "Введите номер группы >> " << endl;

		cin >> arrstud[i].gruppa;
		F << arrstud[i].gruppa << endl;

		cout << "Введите средний балл >> " << endl;
		cin >> arrstud[i].sb;
		F << arrstud[i].sb << endl;

		cout << "Введите доход на чел-ка >> " << endl;
		cin >> arrstud[i].dohod;
		F << arrstud[i].dohod << endl;
		F << endl;

	}
	F.close();
}


void sort() //Сортировка
{
	ifstream F;
	F.open("F.txt");
	char s;
	int min_zp;
	cout << "Введите минимальную зарплату >>" ;
	cin >> min_zp;

	for (int j = 0; j < kol - 1; j++)   // сортировка всех по доходу
	{
		for (int i = 0; i < kol - 1 - j; i++)
		{
			if (arrstud[i].dohod > arrstud[i + 1].dohod)
			{
				buf = arrstud[i + 1];
				arrstud[i + 1] = arrstud[i];
				arrstud[i] = buf;
			}
		}
	}

	int indexBordZp = 0; // индекс минимума по зарплатам
	while (arrstud[indexBordZp].dohod < min_zp * 2)
	{
		indexBordZp++;
	}


	for (int j = 0; j < kol - indexBordZp - 1; j++)
		//сортировка от индекса зарплат по баллам
	{
		for (int i = indexBordZp; i < kol - 1 - j; i++)
		{
			if (arrstud[i].sb < arrstud[i + 1].sb)
			{
				buf = arrstud[i + 1];
				arrstud[i + 1] = arrstud[i];
				arrstud[i] = buf;
			}
		}
	}
	ofstream Fout;


	Fout.open("out.txt", ios::app);
	for (int i = 0; i < kol; i++)
	{
		
		Fout << arrstud[i].First_Name << endl;
		
		Fout << arrstud[i].Name << endl;
		
		Fout << arrstud[i].Last_Name << endl;
		
		Fout << arrstud[i].gruppa << endl;
		
		Fout << arrstud[i].sb << endl;
	
		Fout << arrstud[i].dohod << endl;
		Fout << endl;

	}
	Fout << endl;
	cout << endl;
	Fout.close();
	ifstream FS;
	FS.open("out.txt");
   while (FS.get(s))
   {
	cout << s;
	}
	cout << endl;
	FS.close();

   
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {
		cout << "Меню:" << endl;
		cout << "1)Нажмите 1, для заполнения данных" << endl;
		cout << "2)Нажмите 2, для вывода данных" << endl;
		cout << "3)Нажмите 3, для сортировки данных" << endl;
		cout << "4)Нажмите 4, для очистки файла" << endl;
		cout << "5)Нажмите 5, для редактирования файла(добавление записи)" << endl;
		cout << "6)Нажмите 6, для выхода" << endl;
		cout << "7)Нажмите 7, для поиска по фамилии" << endl;
		cout << "8)Нажмите 8, для редактирования записи" << endl;
		int event = 0;
		cin >> event;

		switch (event)
		{

		case 1:
			cout << "" << endl;
			cout << "Заполнение данными" << endl;
			add();
			break;
		case 2:
			cout << "" << endl;
			cout << "Вывод данных" << endl;
			present();
			break;
		case 3:
			cout << "" << endl;
			cout << "Сортировка" << endl;
			sort();
			break;
		case 4:
			cout << "" << endl;
			cout << "Очищение файла" << endl;
			clear();
			break;
		case 5:
			cout << "" << endl;
			cout << "Добавление записи" << endl;
			edit();
			break;
		case 6:
			exit;
			break;
		case 7:
			cout << "" << endl;
			cout << "Поиск по фамилии" << endl;
			search();
			break;
		case 8:
			cout << "" << endl;
			cout << "Редактирование записи" << endl;
			EditRec();
			break;
		default:
			break;
		}
	}

	return 0;
}