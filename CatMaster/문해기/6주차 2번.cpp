#include<iostream>
#include<cmath>
#include<stack>
using namespace std;
int M, N;
int left_num[10] = {};
int right_num;
int calc[10] = {}; //1이면 +, 2이면 *

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		cin >> M >> N;
		for (int j = 0;j < M;j++) {

			stack<int> s;

			bool flag_find = false;

			for (int k = 0;k < N;k++) {
				cin >> left_num[k];
			}

			cin >> right_num;

			int op_set = pow(2, N - 1) - 1;

			for (int k = op_set;k >= 0;k--) {

				int temp_answer = 0;

				int mask = 1;

				for (int l = 0;l < N - 1;l++) {
					if (k&mask) {
						calc[l] = 1;
					}
					else {
						calc[l] = 2;
					}
					mask = mask << 1;
				}

				s.push(left_num[0]);

				for (int l = 0;l < N - 1;l++) {
					if (calc[l] == 1) {
						s.push(left_num[l + 1]);
					}
					else if (calc[l] == 2) {
						int temp = s.top();
						s.pop();
						temp *= left_num[l + 1];
						s.push(temp);
					}
				}

				int tem_size = s.size();

				for (int l = 0;l < tem_size;l++) {
					int temp = s.top();
					temp_answer += temp;
					s.pop();
				}

				if (temp_answer == right_num)
				{
					flag_find = true;
					break;
				}
			}

			if (flag_find == true) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}

	}

	return 0;
}
