#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct plan {
	int start;
	int end;
};

bool cmp(plan p1, plan p2) {
	if (p1.end == p2.end) {
		return p1.start < p2.start;
	}
	else {
		return p1.end < p2.end;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		int cnt;
		int answer = 0;
		int game_end = 0;
		string temp;
		cin >> cnt;
		vector<plan> T(cnt);
		for (int j = 0;j < cnt;j++) {
			cin >> temp >> T[j].start >> T[j].end;
		}

		sort(T.begin(), T.end(), cmp);

		for (int j = 0;j < T.size();j++) {
			if (game_end <= T[j].start) {
				game_end = T[j].end;
				answer++;
			}
		}

		cout << answer << '\n';
	}
	return 0;
}
