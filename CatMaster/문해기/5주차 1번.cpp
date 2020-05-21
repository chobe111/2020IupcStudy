#include<iostream>
#include<string>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		string S;
		cin >> S;
		int t1 = 0;
		int t2 = S.length() - 1;
		int real = 0;
		while (t1 < t2) {
			if (S[t1] >= 'a'&&S[t1] <= 'z') {
				S[t1] = S[t1] - 32;
			}

			if (S[t2] >= 'a'&&S[t2] <= 'z') {
				S[t2] = S[t2] - 32;
			}

			if (S[t1]<'A' || ('Z' < S[t1] && S[t1] < 'a') || S[t1]>'z') {
				t1++;
			}
			else if (S[t2]<'A' || ('Z' < S[t2] && S[t2] < 'a') || S[t2]>'z') {
				t2--;
			}
			else if (S[t1] != S[t2]) {			
				real = 1;
				break;
			}
			else if (S[t1] == S[t2]) {
				t1++;
				t2--;
			}
		}

		if (real == 1) {
			cout << "No" << endl;
		}
		else if (real == 0) {
			cout << "Yes" << endl;
		}
	}
	return 0;
}
