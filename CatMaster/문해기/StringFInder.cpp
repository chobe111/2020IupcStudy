#include<iostream>
#include<string>
using namespace std;

//���� �˰��� Ÿ���� ������ �����̵� ����̴�
//� �� ���ڿ����� Ư�� ������ �����ϴ��� Ȯ���ϱ� ���� ������ �������� ������ �����س����鼭
//�ð����⵵�� �ִ��� ���� �˰���

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