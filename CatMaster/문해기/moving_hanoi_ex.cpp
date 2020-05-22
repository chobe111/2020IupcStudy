#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int arr[10002] = {};

	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		int N;
		int round = 0;
		cin >> N;
		for (int j = 1;j <= N + 1;j++) {
			arr[j] = 0;
		}

		for (int j = 1;j <= N;j++) {
			int temp;
			cin >> temp;
			arr[temp] = 1;
			if (arr[temp + 1] != 1) {
				round++;
			}
		}
		cout << round << '\n';
	}
	return 0;
}