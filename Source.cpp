#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

int main()
{
	//setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string alc,str,ss;
	int a = 0;
	cout << "Введите креость напитка: ";
	cin >> alc;
	fstream x;
	x.exceptions(ifstream::badbit | ifstream::failbit);	
	wcout << endl;
	try
	{
		x.open("menu.txt", fstream::in);
		while (!x.eof())
		{
			str = "";
			x >> str;
			if (str == (alc + "%"))
			{
				x << str;			
				cout << "Вам может подойти: " << ss<<" "<<str << endl;	
			}
			else 
			{
				int ALC = stoi(alc);//перевод string в int
				int ALCP, ALCM;
				for (int i = 1; i <= 5; i++)
				{
					ALCP = ALC + i;
					ALCM = ALC - i;
					if ((ALC>0) & (str == (to_string(ALCM) + "%")))
					{
						if (ALCM != 0 ) 
						{
							a++;
							x << str;
							cout << "Вам может подойти: " << ss << " " << str << endl;
							a = 0;
						}
					}
					if ((ALC > 0) & str == (to_string(ALCP) + "%"))
					{
						a++;
						x << str;
						cout << "Вам может подойти: " << ss << " " << str << endl;
						a = 0;
					}
				}
			}
			ss = str;
		}
		return 0;
	}
	catch (const ifstream::failure&ex)
	{
		return 0;
	}
	x.close();
}