#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		int arr[10001] = {};
		int M;
		int answer = 0;
		cin >> M;
		for (int j = 0;j < M;j++) {
			cin >> arr[j];
		}
		int temp = M;
		while (temp != 0) {
			if (temp == 0) {
				break;
			}
			else {
				for (int j = 0;j < M;j++) {
					if (arr[j] == temp) {
						arr[j] = -1;
						temp--;
					}
				}
				answer++;
			}
		}
		cout << answer << endl;
	}
	return 0;
}
