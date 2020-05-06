#include<iostream>
#include<algorithm>
using namespace std;
int num[101] = {};
int score[101] = {};
int total_scores[101] = {};
int N;


int search_LIS() {
	int pt = 0;
	int idx = 0;
	while (num[pt] == 0) {
		if (num[pt] != 0) {
			break;
		}
		pt++;
	}

	if (pt == N - 1) {
		return 1;
	}
	else {
		int num_temp[101] = {};
		num_temp[idx] = num[pt];
		num[pt] = 0;
		for (int i = pt + 1;i < N;i++) {
			if (num_temp[idx] < num[i]) {
				num_temp[++idx] = num[i];
				num[i] = 0;
			}
			else if (num_temp[idx] >= num[i] && num[i] != 0) {
				break;
			}
		}
		return idx + 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int i = 0;i < tc;i++) {
		int M, temp;
		int answer = 0;
		temp = 0;
		cin >> N >> M;
		for (int j = 0;j < N;j++) {
			cin >> score[j];
		}

		for (int j = 0;j < N;j++) {
			int temp1, temp2;
			cin >> temp1 >> temp2;
			num[temp2 - 1] = temp1;
		}

		for (int j = 0;j < N;j++) {
			if (num[j] != 0) {
				total_scores[temp] = search_LIS();
				temp++;
			}
		}

		for (int j = 0;j < temp;j++) {
			answer += score[total_scores[j] - 1];
		}

		cout << answer << '\n';
	}
	return 0;
}
