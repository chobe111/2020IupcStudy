#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int arr[10] = {};		//순열을 이루는 숫자가 저장되는곳
bool sel[10] = {};		//순열을 이루는 숫자들 중 어떤 숫자가 쓰였는지 체크하는곳
vector<int> Vec;		//임시적으로 만든 순열의 상태를 저장해두는 곳
unsigned long long int num, min_num, max_num, must_num;
//각각 순열의 길이, 문제 조건에 제시된 결과값의 최소 ~ 최대값, 문제조건에 쓰이는 제곱값이다
int real_answer = 0;
//문제에 제시된 조건을 만족하는 순열의 갯수

//최대 9개의 숫자들이 배열 arr 안에 저장되어있다 가정하자.
//이 숫자들을 모두 사용한 순열을 만들었을 때, 현재 순열 위치의 값 * (must_num ^ 순열의 위치)의 합들을 모두더해 1013으로 나눈 나머지를 구한다.
//그 나머지의 값이 min_num이상 max_num이하인 경우의 순열 종류를 모두 출력하면 된다.


//순열을 만드는 알고리즘
void Permu(int cnt) {
	//모든 숫자들을 사용한 순열이 만들어졌다면 문제에 제시된 규칙대로 answer라는 값을 만들어
	//이 값이 최소 ~ 최대값 사이인지를 구한다
	if (cnt == num) {
		unsigned long long int answer = 0;
		for (int k = 0;k < num;k++) {
			unsigned long long int temp = (unsigned long long int)pow(must_num, k) % 1013;
			answer += Vec[k] * temp % 1013;
		}
		answer = answer % 1013;
		if (answer >= min_num && answer <= max_num) {
			real_answer++;
		}
	}
	else {
		for (int i = 0;i < num;i++) {
			//sel[i]값이 true가 아니면, Vec에 입력하여 임시적으로 순열을 이루게 한다
			if (sel[i] == true) {
				continue;
			}
			sel[i] = true;
			Vec.push_back(arr[i]);
			Permu(cnt + 1);
			Vec.pop_back();
			sel[i] = false;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		cin >> num;
		for (int j = 0;j < num;j++) {
			cin >> arr[j];
		}
		cin >> min_num >> max_num >> must_num;
		Permu(0);
		cout << real_answer << '\n';
		real_answer = 0;
	}
	return 0;
}
