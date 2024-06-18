/*
Структура "Спортивная команда"
- название;
- город;
- количество игроков;
- количество набранных очков.
Удалить все элементы с количеством очков меньше
заданного, добавить 2 элемента в начало файла.
*/

# include <iostream>
# include <fstream>
using namespace std;
struct SportTeam {
	char TeamName[100];
	char TeamCity[100];
	int TeamNumberOfPlayers;
	int TeamScore;
};
void addelements() {
	fstream SportTeamFile("D:\\Вуз\\Лабораторные работы информатика\\Labs\\8_лаб\\file.txt", std::ios::app);
	if (SportTeamFile.is_open()) {
		SportTeamFile.seekg(1111110, ios::beg);
		SportTeam newteam;
		cout << "Введите название новой команды" << endl;
		cin.getline(newteam.TeamName, 100);
		SportTeamFile << "Название команды: " << newteam.TeamName << endl;
		cout << "Введите город команды" << endl;
		cin.getline(newteam.TeamCity, 100);
		SportTeamFile << "Город команды:  " << newteam.TeamCity << endl;
		cout << "Введите количество игроков" << endl;
		cin >> newteam.TeamNumberOfPlayers;
		SportTeamFile << "Количество игроков: " << newteam.TeamNumberOfPlayers << endl;
		cout << "Введите счёт команды " << endl;
		cin >> newteam.TeamScore;
		SportTeamFile << "Счёт команды: " << newteam.TeamScore << endl;
		cin.ignore();
		SportTeam newteam1;
		cout << "Введите название новой команды" << endl;
		cin.getline(newteam1.TeamName, 100);
		SportTeamFile << "Название команды: " << newteam1.TeamName << endl;
		cout << "Введите город команды" << endl;
		cin.getline(newteam1.TeamCity, 100);
		SportTeamFile << "Город команды:  " << newteam1.TeamCity << endl;
		cout << "Введите количество игроков" << endl;
		cin >> newteam1.TeamNumberOfPlayers;
		SportTeamFile << "Количество игроков: " << newteam1.TeamNumberOfPlayers << endl;
		cout << "Введите счёт команды " << endl;
		cin >> newteam1.TeamScore;
		SportTeamFile << "Счёт команды: " << newteam1.TeamScore << endl;

	}
	else {
		cout << "Ошибка открытия файла";
	}
	SportTeamFile.close();
}
int main() {
	setlocale(LC_ALL, "RU");
	addelements();
	return 0;
}