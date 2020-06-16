#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int money[200001] = {};
int cnt_money[202] = {};



double CalcMedian(int D) {
	int med_count = 0;
	double median = 0;
	int fC, sC;
	if(D % 2 != 0) {
		for (int j = 0;j <= 200;j++) {
			med_count = med_count + cnt_money[j];
			if (med_count > D / 2){
				median = j;
				break;
			}
		}
	}
	else if(D % 2 == 0) {
		fC = 0;
		sC = 0;
		for (int j = 0;j <= 200;j++) {
			med_count = med_count + cnt_money[j];
			if (med_count >= D / 2 && fC == 0) {
				fC = j;
			}
			
			if (med_count >= D / 2 + 1 && sC == 0) {
				sC = j;
				median = (fC + sC) / 2.0	;
				break;
			}
		}
	}

	return median;
}

int main() {
	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		memset(money, 0, sizeof(money));
		memset(cnt_money, 0, sizeof(cnt_money));
		int day, day_check;
		cin >> day >> day_check;
		int answer = 0;
		for (int j = 0;j < day;j++) {
			cin >> money[j];
		}

		for (int j = 0;j < day_check;j++) {
			cnt_money[money[j]]++;
		}

		for (int j = day_check;j < day;j++) {
			double temp = CalcMedian(day_check);
			if (temp * 2 <= money[j]) {
				answer++;
			}
			cnt_money[money[j]]++;
			cnt_money[money[j - day_check]]--;
		}
		cout << answer << '\n';
	}
	return 0;
}
