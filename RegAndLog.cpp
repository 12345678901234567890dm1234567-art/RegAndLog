#define NOMINMAX
#include<iostream>
#include<Windows.h>
#include<string>
#include<limits>

int main() // строка
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // 1251 ,CP_UTF8
	system("chcp 1251");
	srand(time(NULL));
	// pasvord > 5,pasvord<15
	int col = 0;
	std::string zif{ "1234567890" };
	std::string login1{ "h" }, login2{ "t" }, totallogin, vibor{ "arg" };
	std::string pasvord1{ "b" }, pasvord2{ "d" }, totalpasvord{ "f" } ;
	do
	{
		std::cout << "Введите новое имя пользователя:";
		//логин на регистрацию
		std::cin >> login2;
		//проверка логина
		std::cout << "Ваш логин :" << login2;
		std::cout << "\nПридумайте пароль ";
		std::cout << "\n(он должен быть из латиницы, больше 5 и меньше 15 символов ";
		std::cout << ", минимум 2 из них должны быть цифрами)";
		//Ввод пароля ( не getline,потому, что на новой итерации не ввести логин или пароль)
		std::cin >> pasvord1;
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (pasvord1.size() >= 5 && pasvord1.size() <= 15)
		{
			for (int i = 0; i < pasvord1.size(); i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (zif[j] == pasvord1[i])
					{
						col++;
					}
				}
			}
			if (col >= 2)
			{
				std::cout << "\nПароль составлен корректно,повторите ввод для уверенности:";
				// повторный ввод пароля
				std::cin >> pasvord2;
				if (pasvord2 != pasvord1)
				{
					std::cout << "\nПароли не совпадают, если хотите ";
					std::cout << "попробовать еще раз вводите не 'cont'";
					std::cin >> vibor;
				}
				else
				{
					std::cout << "\n" << login1 << "Вы зарегистрированы";
					vibor = { "cont" };
				}
			}
			else
			{
				std::cout <<"\nНе достаточно цифр в пароле";
				std::cout <<",если хотите попробовать еще раз вводите не 'cont'";
				std::cin >> vibor;
			}
		}
		else
		{
			std::cout <<"\nНе то количество символов";
			std::cout << ",если хотите попробовать еще раз вводите не 'cont'";
			std::cin >> vibor;
		}
	} while (vibor != "cont");
	do
	{
		std::cout << "\nВведите логин";
		std::cin >> totallogin;
		if(totallogin == login2)
		{
			std::cout << "\nВведите пароль";
			std::cin >> totalpasvord;
			if (totalpasvord == pasvord1)
			{
				std::cout << "\nДобро пожаловать" << totallogin;
				vibor = { "stop" };
			}
			else
			{
				std::cout <<"\nпароль неверен";
			}
		}
		else
		{
			std::cout << "\nневерный логин ";
		}

	} while (totalpasvord != pasvord1 || vibor != "stop");
	return 0;
}