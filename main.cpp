#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

class Animal {
protected:
	char* name;
	char* ms;
public:
	virtual void show() = 0;
	Animal(char*, char*);
	virtual ~Animal() = 0;
};

class Mammal :public Animal {
	char* pt;
	int age;
public:
	Mammal(char*, char*, char*, int);
	~Mammal();
	void show();
};

class Fish :public Animal {
	int kolplavn;
	int ves;
public:
	Fish(char*, char*, int, int);
	~Fish();
	void show();
};

class Bird :public Animal {
	int razmah;
	char* color;
public:
	Bird(char*, char*, int, char*);
	~Bird();
	void show();
};

int menu();
int menuMain();
int getInt();
string writeWords();

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char nam[80], mesto[80], tp[80], clr[80];
	int pr, kol, vib, vibm, n = 0;
	double vs, rz;
	Animal** p = new Animal*[n];
	while (true) {
		vibm = menuMain();
		if (vibm == 0) {
			while (true) {
				vib = menu();
				if (vib == 0) {
					cout << "Название: ";
					string nam1 = writeWords();
					strcpy_s(nam, nam1.c_str());
					cout << "Место обитания: ";
					string mesto1 = writeWords();
					strcpy_s(mesto, mesto1.c_str());
					cout << "Введите тип питания: ";
					string tp1 = writeWords();
					strcpy_s(tp, tp1.c_str());
					cout << "Продолжительность жизни(лет): ";
					pr = getInt();
					Animal** p1 = new Animal * [n + 1];
					copy(p, p + n, p1);
					p1[n] = new Mammal(nam, mesto, tp, pr);
					n++;
					delete[]p;
					p = p1;
				}
				else if (vib == 1) {
					cout << "Название: ";
					string nam1 = writeWords();
					strcpy_s(nam, nam1.c_str());
					cout << "Место обитания: ";
					string mesto1 = writeWords();
					strcpy_s(mesto, mesto1.c_str());
					cout << "Количество плавников: ";
					kol = getInt();
					cout << "Вес(гр): ";
					vs = getInt();
					Animal** p1 = new Animal * [n + 1];
					copy(p, p + n, p1);
					p1[n] = new Fish(nam, mesto, kol, vs);
					n++;
					delete[]p;
					p = p1;
				}
				else if (vib == 2) {
					cin.clear();
					cout << "Название: ";
					string nam1 = writeWords();
					strcpy_s(nam, nam1.c_str());
					cout << "Место обитания: ";
					string mesto1 = writeWords();
					strcpy_s(mesto, mesto1.c_str());
					cout << "Размах крыльев(см): ";
					rz = getInt();
					cout << "Цвет: ";
					string clr1 = writeWords();
					strcpy_s(clr, clr1.c_str());
					Animal** p1 = new Animal * [n + 1];
					copy(p, p + n, p1);
					p1[n] = new Bird(nam, mesto, rz, clr);
					n++;
					delete[]p;
					p = p1;
				}
				else break;
				system("pause");
			}
		}
		else if (vibm == 1) {
			if (n == 0) {
				cout << "Нет введенной информации!!!" << endl;
			}
			else {
				for (int i = 0; i < n; i++) {
					p[i]->show();
				}
			}
			system("pause");
		}
		else break;
	}
	for (int i = 0; i < n; i++) {
		delete p[i];
	}
	delete[]p;
	return 0;
}

Animal::Animal(char* n, char* m) {
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
	ms = new char[strlen(m) + 1];
	strcpy_s(ms, strlen(m) + 1, m);
}

Animal::~Animal() {
	delete[] name;
	delete[] ms;
}

Mammal::Mammal(char* n, char* m, char* p, int a) :Animal(n, m) {
	pt = new char[strlen(p) + 1];
	strcpy_s(pt, strlen(p) + 1, p);
	age = a;
}

void Mammal::show() {
	cout << endl;
	cout << "Млекопитающее\n" << "Название: " << name << endl
		<< "Место обитания: " << ms << endl
		<< "Тип питания: " << pt << endl
		<< "Продолжительность жизни: " << age << " лет" << endl;
}

Mammal::~Mammal() {
	delete[] pt;
}

Fish::Fish(char* n, char* m, int k, int v) :Animal(n, m) {
	kolplavn = k;
	ves = v;
}

void Fish::show() {
	cout << endl;
	cout << "Рыба\n" << "Название: " << name << endl
		<< "Место обитания: " << ms << endl
		<< "Количество плавников: " << kolplavn << endl
		<< "Вес: " << ves << " гр" << endl;
}

Fish::~Fish() {

}

Bird::Bird(char* n, char* m, int r, char* c) :Animal(n, m) {
	razmah = r;
	color = new char[strlen(c) + 1];
	strcpy_s(color, strlen(c) + 1, c);
}

void Bird::show() {
	cout << endl;
	cout << "Птица\n" << "Название: " << name << endl
		<< "Место обитания: " << ms << endl
		<< "Размах крыльев: " << razmah << " см" << endl
		<< "Цвет: " << color << endl;
}

Bird::~Bird() {
	delete[] color;
}

int menu()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 4) % 4;

		if (choiceButton == 0) cout << "->Млекопитающие" << endl;
		else cout << "Млекопитающие" << endl;

		if (choiceButton == 1) cout << "->Рыбы" << endl;
		else cout << "Рыбы" << endl;

		if (choiceButton == 2) cout << "->Птицы" << endl;
		else cout << "Птицы" << endl;

		if (choiceButton == 3) cout << "->Выход" << endl;
		else cout << "Выход" << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) {
			system("cls");
			return choiceButton;
		}

		system("cls");
	}
}

int menuMain()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 3) % 3;

		if (choiceButton == 0) cout << "->Ввод информации" << endl;
		else cout << "Ввод информации" << endl;

		if (choiceButton == 1) cout << "->Просмотр информации" << endl;
		else cout << "Просмотр" << endl;

		if (choiceButton == 2) cout << "->Выход" << endl;
		else cout << "Выход" << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) {
			system("cls");
			return choiceButton;
		}

		system("cls");
	}
}

int getInt() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}

string writeWords() {
	string word;
	int Knopka;
	char simvol;
	while (true) {
		Knopka = _getch();
		if (Knopka == 8) {
			if (word.length() != 0) {
				cout << '\b' << " " << '\b';
				word.erase(word.length() - 1);
			}
		}
		else
			if (Knopka == 13 && word.length() != 0) break;
			else {
				simvol = (char)Knopka;
				if ((simvol >= 'а' && simvol <= 'я') || (simvol >= 'А' && simvol <= 'Я') || simvol == '-' || simvol == ' ' || simvol == '.') {
					word = word + simvol;
					cout << simvol;
				}
			}
	}
	cout << endl;
	return word;
}
