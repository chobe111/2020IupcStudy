#include<iostream>
using namespace std;
int board[17][17] = {};

bool checker(int dx, int dy, int col) {
	int tmp_x = dx;
	int tmp_y = dy;
	int curr_color = col;
	int cnt = 0;
	while (curr_color == col) {
		cnt++;
		curr_color = board[--tmp_x][tmp_y];
	}
	tmp_x = dx;
	tmp_y = dy;
	curr_color = col;
	while (curr_color == col)
	{
		cnt++;
		curr_color = board[++tmp_x][tmp_y];
	}

	if (cnt - 1 == 5) {
		return true;
	}

	tmp_x = dx;
	tmp_y = dy;
	curr_color = col;
	cnt = 0;
	while (curr_color == col) {
		cnt++;
		curr_color = board[tmp_x][--tmp_y];
	}
	tmp_x = dx;
	tmp_y = dy;
	curr_color = col;
	while (curr_color == col)
	{
		cnt++;
		curr_color = board[tmp_x][++tmp_y];
	}

	if (cnt - 1 == 5) {
		return true;
	}

	tmp_x = dx;
	tmp_y = dy;
	curr_color = col;
	cnt = 0;
	while (curr_color == col) {
		cnt++;
		curr_color = board[--tmp_x][++tmp_y];
	}
	tmp_x = dx;
	tmp_y = dy;
	curr_color = col;
	while (curr_color == col)
	{
		cnt++;
		curr_color = board[++tmp_x][--tmp_y];
	}

	if (cnt - 1 == 5) {
		return true;
	}

	tmp_x = dx;
	tmp_y = dy;
	curr_color = col;
	cnt = 0;
	while (curr_color == col) {
		cnt++;
		curr_color = board[--tmp_x][--tmp_y];
	}
	tmp_x = dx;
	tmp_y = dy;
	curr_color = col;
	while (curr_color == col)
	{
		cnt++;
		curr_color = board[++tmp_x][++tmp_y];
	}

	if (cnt - 1 == 5) {
		return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		int end_turn;
		int vic_color = 0;
		for (int j = 0;j < 17;j++) {
			for (int k = 0;k < 17;k++) {
				board[j][k] = 0;
			}
		}

		bool done = false;
		for (int j = 0;j < 225;j++) {
			int x, y;
			if (done == true){
				cin >> x >> y;
			}
			else if (done != true) {
				cin >> x >> y;
				if (j % 2 == 0) {
					board[x][y] = 1;
				}
				else {
					board[x][y] = 2;
				}

				done = checker(x, y, board[x][y]);

				if (done == true) {
					end_turn = j + 1;
					vic_color = board[x][y];
				}
			}
		}

		if (vic_color == 1) {
			cout << end_turn << " " << 'B' << '\n';
		}
		else if (vic_color == 2) {
			cout << end_turn << " " << 'W' << '\n';
		}
	}
	return 0;
}
