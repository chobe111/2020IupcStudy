#include<iostream>
#include<string>
using namespace std;

//사용된 알고리즘 타입은 윈도우 슬라이딩 기법이다
//어떤 한 문자열에서 특정 조건을 만족하는지 확인하기 위한 범위의 시작점과 끝점을 조정해나가면서
//시간복잡도를 최대한 줄인 알고리즘

int WindowSliding(string x, string y) {
	int Win_CntArr[128] = {};
	int R_CntArr[128] = {};

	int start = 0;
	int end = 0;
	int window_len = 0;
	int count = 0;
	int A_len = x.length();
	int B_len = y.length();
	int min_len = A_len + 1;

	for (int i = 0;i < B_len;i++) {
		R_CntArr[y[i]]++;
	}

	while (end <= A_len) {
		Win_CntArr[x[end]]++;

		if (R_CntArr[x[end]] >= Win_CntArr[x[end]]) {
			count++;
		}

		while (count == B_len) {
			window_len = end - start + 1;

			if (window_len < min_len) {
				min_len = window_len;
			}

			if (R_CntArr[x[start]] >= Win_CntArr[x[start]]) {
				count--;
			}

			Win_CntArr[x[start]]--;
			start++;
		}
		end++;
	}

	if (min_len > A_len) {
		return 0;
	}
	return min_len;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		string A, B;
		cin >> A;
		cin >> B;
		cout << WindowSliding(A, B) << '\n';
	}
	return 0;
}