// Сheckers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"//Подключаю класс с массой нужных нам библиотек
#include "CheckersManager.h"//Подключаю класс CheckersManager.h для управления игрой

int main() {

	setlocale(LC_ALL, "Rus");
	srand((unsigned)time(NULL));
	CheckersManager manager;

	while (true) {

		if (!manager.init()) {
			cout << "Попробуйте еще раз." << endl;
			continue;
		}
		break;
	}

	while (!manager.isGameFinished()) {
		manager.makeMove();
	}

	_getch();
	return 0;

}
