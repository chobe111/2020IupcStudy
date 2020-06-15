#include<iostream>
#include<algorithm>
using namespace std;
int i[9];

//next_permutation의 존재를 알게 된 이후 만들게 된 또다른 정답코드
//이게 더 간략한가? 헷갈린다
//다만 next_permutation의 경우엔 순열의 길이가 길수록 시간복잡도로 인하여 시간초과가 날 가능성이 높다고한다

int main() {
	int T;
	cin >> T;
	for (int a = 0; a < T; a++) {
		int N;
		cin >> N;
		for (int a = 0; a < N; a++) {
			cin >> i[a];
		}
		int ax, b, x;
		cin >> ax >> b >> x;
		unsigned long long int ans = 0;
		int k = 1;
		int fi = 0;
		sort(i, i + N);
		do {
			ans = 0;
			k = 1;
			for (int a = 0; a < N; a++) {
				ans += i[a] * k;
				k = k * x;
			}
			ans = ans % 1013;
			if (ans >= ax && ans <= b) {
				fi++;
			}
		} while (next_permutation(i, i + N));
		cout << fi << endl;
	}
	return 0;
}
