// CMakeProject1.cpp: определяет точку входа для приложения.
//
#include "lib.h"
#include "App.h"

using namespace std;

std::pair<int, int> figure_location(string figure) {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Укажите столбец(a-h) и строку(1-8) " << figure << " через пробел: ";
	cin >> x_figure;
	cin.clear();
	cin >> y_figure;
	return std::make_pair(x_figure, y_figure);
}



int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Нажмите любую кнопку чтобы начать";

	std::pair<int, int> a = figure_location("белого короля");
	x_white_king = a.first;
	y_white_king = a.second;

	std::pair<int, int> b = figure_location("чёрного слона");
	x_black_elephant = b.first;
	y_black_elephant = b.second;

	std::pair<int, int> c = figure_location("чёрной ладьи");
	x_black_rook = c.first;
	y_black_rook = c.second;

	check_elephant(x_white_king, y_white_king, x_black_elephant, y_black_elephant);
	check_rook(x_white_king, y_white_king, x_black_rook, y_black_rook);

	return 0;
}
