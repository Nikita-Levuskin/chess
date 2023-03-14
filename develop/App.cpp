// CMakeProject1.cpp: определяет точку входа для приложения.
//
#include "lib.h"
#include "App.h"

using namespace std;

string word_list[8] = {"a", "b", "c", "d", "e", "f", "g", "h"};
int number_list[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

std::pair<int, int> figure_location(string figure) {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	bool par = false;
	bool parm1 = false;
	bool parm2 = false;
	cin.clear();
	cout << "Укажите столбец(a-h) и строку(1-8) " << figure << " через пробел: ";
	cin >> x_figure;
	cin.clear();
	cin >> y_figure;
	cin.clear();

	for (int i = 0; i < 8; i++) {
		if (x_figure == word_list[i]) {
			x_int = i + 1;
			parm1 = true;
		}
		if (y_figure == number_list[i]) {
			parm2 = true;
		}
		if (parm1 == true && parm2 == true) {
			return std::make_pair(x_int, y_figure);
		}
	}
	figure_location(figure);
}

int main()	{
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