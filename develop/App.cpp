// CMakeProject1.cpp: определяет точку входа для приложения.
//
#include <iostream>
#include <string>
#include <limits>
#include <list>

using namespace std;

string word_list[8] = {"a", "b", "c", "d", "e", "f", "g", "h"};
int number_list[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

int x_white_king, y_white_king, x_black_elephant, y_black_elephant, x_black_rook, y_black_rook, 
	x_black_queen, y_black_queen, x_black_knight, y_black_knight;

int check_elephant(int x1, int y1, int x2, int y2) {
	if (x1 + y1 == x2 + y2 || x1 - y1 == x2 - y2) 
	{
		return 0;
	}
	else return 1;
}

int check_rook(int x1, int y1, int x2, int y2) {
	if (x1 == x2 || y1 == y2)
	{
		return 0;
	}
	else return 1;
}

int check_knight(int x1, int y1, int x2, int y2)
{
	if (x1 + 1 + y1 + 2 == x2 + y2 || x1 - 1 + y1 + 2 == x2 + y2 || x1 + 1 + y1 - 2 == x2 + y2 || x1 - 1 + y1 - 2 == x2 + y2)
	{
		return 0;
	}
	else return 1;
}

int check_queen(int x1, int y1, int x2, int y2)
{
	if (x1 == x2 || y1 == y2 || x1 + y1 == x2 + y2 || x1 - y1 == x2 - y2)
	{
		return 0;
	}
	else return 1;
}

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
					else if (i == y_black_knight && y == x_black_knight) {
						return 1;
					}
					else if (i == y_black_queen && y == x_black_queen) {
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
					else if (i == y_black_knight && y == x_black_knight) {
						return 1;
					}
					else if (i == y_black_queen && y == x_black_queen) {
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
					else if (i == y_black_knight && y == x_black_knight) {
						return 1;
					}
					else if (i == y_black_queen && y == x_black_queen) {
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
					else if (i == y_black_knight && y == x_black_knight) {
						return 1;
					}
					else if (i == y_black_queen && y == x_black_queen) {
						return 1;
					}
				}
			}
		}
		cout << "шах от слона" << endl;
		return 0;
	}
	if (figures == "rook") {
		if (y_black_rook == y_white_king) {
			if (x_black_rook > x_white_king) {
				for (int i = x_black_rook; i >= x_white_king; i--) {
					if (i == x_black_elephant && y_black_rook == y_black_elephant) {
						return 1;
					}
					else if (i == x_black_knight && y_black_rook == y_black_knight) {
						return 1;
					}
					else if (i == x_black_queen && y_black_rook == y_black_queen) {
						return 1;
					}
				}
			}
			else {
				for (int i = x_black_rook; i <= x_white_king; i++) {
					if (i == x_black_elephant && y_black_rook == y_black_elephant) {
						return 1;
					}
					else if (i == x_black_knight && y_black_rook == y_black_knight) {
						return 1;
					}
					else if (i == x_black_queen && y_black_rook == y_black_queen) {
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
					else if (i == y_black_knight && x_black_rook == x_black_knight) {
						return 1;
					}
					else if (i == y_black_queen && x_black_rook == x_black_queen) {
						return 1;
					}
				}
			}
			else {
				for (int i = y_black_rook; i <= y_white_king; i++) {
					if (i == y_black_elephant && x_black_rook == x_black_elephant) {
						return 1;
					}
					else if (i == y_black_knight && x_black_rook == x_black_knight) {
						return 1;
					}
					else if (i == y_black_queen && x_black_rook == x_black_queen) {
						return 1;
					}
				}
			}
		}
		cout << "шах от ладьи" << endl;
		return 0;
	}
	if (figures == "queen") {
		if (y_black_queen == y_white_king) {
			if (x_black_queen > x_white_king) {
				for (int i = x_black_queen; i >= x_white_king; i--) {
					if (i == x_black_elephant && y_black_queen == y_black_elephant) {
						return 1;
					}
					else if (i == x_black_knight && y_black_queen == y_black_knight) {
						return 1;
					}
					else if (i == x_black_rook && y_black_queen == y_black_rook) {
						return 1;
					}
				}
			}
			else {
				for (int i = x_black_queen; i <= x_white_king; i++) {
					if (i == x_black_elephant && y_black_queen == y_black_elephant) {
						return 1;
					}
					else if (i == x_black_knight && y_black_queen == y_black_knight) {
						return 1;
					}
					else if (i == x_black_rook && y_black_queen == y_black_rook) {
						return 1;
					}
				}
			}
		}
		else if (x_black_queen == x_white_king) {
			if (y_black_queen > y_white_king) {
				for (int i = y_black_queen; i >= y_white_king; i--) {
					if (i == y_black_elephant && x_black_queen == x_black_elephant) {
						return 1;
					}
					else if (i == y_black_knight && x_black_queen == x_black_knight) {
						return 1;
					}
					else if (i == y_black_rook && x_black_queen == x_black_rook) {
						return 1;
					}
				}
			}
			else {
				for (int i = y_black_queen; i <= y_white_king; i++) {
					if (i == y_black_elephant && x_black_queen == x_black_elephant) {
						return 1;
					}
					else if (i == y_black_knight && x_black_queen == x_black_knight) {
						return 1;
					}
					else if (i == y_black_rook && x_black_queen == x_black_rook) {
						return 1;
					}
				}
			}
		}
		else if (y_black_queen > y_white_king) {
			if (x_black_queen > x_white_king) {
				int y = x_black_queen + 1;
				for (int i = y_black_queen; i >= y_white_king; i--) {
					y -= 1;
					if (i == y_black_rook && y == x_black_rook) {
						return 1;
					}
					else if (i == y_black_knight && y == x_black_knight) {
						return 1;
					}
					else if (i == y_black_elephant && y == x_black_elephant) {
						return 1;
					}
				}
			}
			else {
				int y = x_black_queen - 1;
				for (int i = y_black_queen; i >= y_white_king; i--) {
					y += 1;
					if (i == y_black_rook && y == x_black_rook) {
						return 1;
					}
					else if (i == y_black_knight && y == x_black_knight) {
						return 1;
					}
					else if (i == y_black_elephant && y == x_black_elephant) {
						return 1;
					}
				}
			}
		}
		else if (y_black_queen < y_white_king) {
			if (x_black_queen > x_white_king) {
				int y = x_black_queen + 1;
				for (int i = y_black_queen; i <= y_white_king; i++) {
					y -= 1;
					if (i == y_black_rook && y == x_black_rook) {
						return 1;
					}
					else if (i == y_black_knight && y == x_black_knight) {
						return 1;
					}
					else if (i == y_black_elephant && y == x_black_elephant) {
						return 1;
					}
				}
			}
			else {
				int y = x_black_queen - 1;
				for (int i = y_black_queen; i <= y_white_king; i++) {
					y += 1;
					if (i == y_black_rook && y == x_black_rook) {
						return 1;
					}
					else if (i == y_black_knight && y == x_black_knight) {
						return 1;
					}
					else if (i == y_black_elephant && y == x_black_elephant) {
						return 1;
					}
				}
			}
		}
		cout << "шах от ферзя" << endl;
		return 0;
	}
	if (figures == "knight") {
		cout << "шах от коня" << endl;
		return 0;
	}
}

std::pair<int, int> figure_location(string figure) {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int y_figure, x_int;
	string x_figure;
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

	std::pair<int, int> d = figure_location("чёрного коня");
	x_black_knight = d.first;
	y_black_knight = d.second;

	std::pair<int, int> e = figure_location("чёрного ферзя");
	x_black_queen = e.first;
	y_black_queen = e.second;

	int fe = check_elephant(x_white_king, y_white_king, x_black_elephant, y_black_elephant);
	int fr = check_rook(x_white_king, y_white_king, x_black_rook, y_black_rook);
	int fk = check_knight(x_white_king, y_white_king, x_black_knight, y_black_knight);
	int fq = check_queen(x_white_king, y_white_king, x_black_queen, y_black_queen);

	if (fe == 0) {
		fe = overlapped_figures("elephant");
	}

	if (fr == 0) {
		fr = overlapped_figures("rook");
	}

	if (fk == 0) {
		fk = overlapped_figures("knight");
	}

	if (fq == 0) {
		fq = overlapped_figures("queen");
	}

	if (fr + fe + fk + fq == 4) {
		cout << "Нет шаха";
	}

	cout << "\nНажмите любую кнопку чтобы закрыть окно";
	cin.get();
	cin.get();
	return 0;
}