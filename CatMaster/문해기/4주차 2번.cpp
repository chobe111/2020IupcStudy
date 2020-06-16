#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int janki[501][501] = {};
int checked[501][501] = {};
queue<int> xpoint;
queue<int> ypoint;
int temp_x, temp_y;
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = { 2,1,-1,-2,2,1,-1,-2 };

void checker(int x, int y, int goal_x, int goal_y, int length) {
	xpoint.push(x);
	ypoint.push(y);
	janki[x][y] = 0;
	checked[x][y] = 1;
	while (!xpoint.empty() && !ypoint.empty()) {
		temp_x = xpoint.front();
		xpoint.pop();
		temp_y = ypoint.front();
		ypoint.pop();
		if (temp_x == goal_x && temp_y == goal_y) {
			cout << janki[temp_x][temp_y] << '\n';
			break;
		}

		for (int i = 0;i < 8;i++) {
			int xx = temp_x + dx[i];
			int yy = temp_y + dy[i];
			if (checked[xx][yy] == 0 && xx >= 0 && xx < length&&yy >= 0 && yy < length) {
				checked[xx][yy] = 1;
				xpoint.push(xx);
				ypoint.push(yy);
				janki[xx][yy] = janki[temp_x][temp_y] + 1;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int T, len;
	int x1, x2, y1, y2;
	cin >> T;
	for (int i = 0;i < T;i++) {
		cin >> len;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		if (x1 == x2 && y1 == y2) {
			cout << 0 << endl;
		}
		else {
			checker(x1, y1, x2, y2, len);
			memset(janki, 0, sizeof(janki));
			memset(checked, 0, sizeof(checked));

			while (!xpoint.empty()) {
				xpoint.pop();
			}

			while (!ypoint.empty()) {
				ypoint.pop();
			}
		}
	}
	return 0;
}
