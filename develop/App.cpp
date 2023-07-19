// CMakeProject1.cpp: определяет точку входа для приложения.
//
#include "lib.h"
#include "App.h"

using namespace std;

string word_list[8] = {"a", "b", "c", "d", "e", "f", "g", "h"};
int number_list[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

int overlapped_figures(string figures) {
	if (figures == "elephant") {
		if (y_black_elephant > y_white_king) {
			if (x_black_elephant > x_white_king) {
				int y = x_black_elephant + 1;
				for (int i = y_black_elephant; i >= y_white_king; i--) {
					y -= 1;
					if (i == y_black_rook && y == x_black_rook) {
						return 1;
					}
				}
			}
			else {
				int y = x_black_elephant - 1;
				for (int i = y_black_elephant; i >= y_white_king; i--) {
					y += 1;
					if (i == y_black_rook && y == x_black_rook) {
						return 1;
					}
				}
			}
		}
		else {
			if (x_black_elephant > x_white_king) {
				int y = x_black_elephant + 1;
				for (int i = y_black_elephant; i <= y_white_king; i++) {
					y -= 1;
					if (i == y_black_rook && y == x_black_rook) {
						return 1;
					}
				}
			}
			else {
				int y = x_black_elephant - 1;
				for (int i = y_black_elephant; i <= y_white_king; i++) {
					y += 1;
					if (i == y_black_rook && y == x_black_rook) {
						return 1;
					}
				}
			}
		}
		cout << "шах от слона";
		return 0;
	}
	if (figures == "rook") {
		if (y_black_rook == y_white_king) {
			if (x_black_rook > x_white_king) {
				for (int i = x_black_rook; i >= x_white_king; i--) {		
					if (i == x_black_elephant && y_black_rook == y_black_elephant) {
						return 1;
					}
				}
			}
			else {
				for (int i = x_black_rook; i <= x_white_king; i++) {
					if (i == x_black_elephant && y_black_rook == y_black_elephant) {
						return 1;
					}
				}
			}
		}
		else {
			if (y_black_rook > y_white_king) {
				for (int i = y_black_rook; i >= y_white_king; i--) {
					if (i == y_black_elephant && x_black_rook == x_black_elephant) {
						return 1;
					}
				}
			}
			else {
				for (int i = y_black_rook; i <= y_white_king; i++) {
					if (i == y_black_elephant && x_black_rook == x_black_elephant) {
						return 1;
					}
				}
			}
		}
		cout << "шах от ладьи";
		return 0;
	}
}

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

int main() {
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

	int e = check_elephant(x_white_king, y_white_king, x_black_elephant, y_black_elephant);
	int r = check_rook(x_white_king, y_white_king, x_black_rook, y_black_rook);

	if (e == 0) {
		e = overlapped_figures("elephant");
	}

	if (r == 0) {
		r = overlapped_figures("rook");
	}

	if (r + e == 2) {
		cout << "Нет шаха";
	}

	cout << "\nНажмите любую кнопку чтобы закрыть окно";
	cin.get();
	cin.get();
	return 0;
}