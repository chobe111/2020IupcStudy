#include<iostream>
#include<algorithm>
using namespace std;
int items[501][100001] = {};	//물건의 현재까지 담은 갯수 및 총무게	
int value[501] = {};			//물건 가치
int weight[501] = {};			//물건 무게
int num, max_weight;

//int bag(int idx, int max_w) {
//	if (idx == num) {
//		return 0;
//	}
//	else {
//		int temp_maxv = 0;
//		if (items[idx][0] <= max_w) {
//			temp_maxv = items[idx][1] + bag(idx + 1, max_w - items[idx][0]);
//		}
//		temp_maxv = max(temp_maxv, bag(idx + 1, max_w));
//		return temp_maxv;
//	}
//}

//주석처리된거 써먹으려했는데 시간초과나옴
//뭔가가 잘못되어서 함수가 무한번 돌아가는거거나 재귀가 너무 심해서 시간복잡도가 엄청높은가보다

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {

		cin >> num >> max_weight;
		for (int j = 1;j <= num;j++) {
			cin >> weight[j];
		}

		for (int j = 1;j <= num;j++) {
			cin >> value[j];
		}

		for (int j = 1;j <= num;j++) {
			for (int k = 1;k <= max_weight;k++) {
				items[j][k] = items[j - 1][k];

				if (k - weight[j] >= 0) {
					items[j][k] = max(items[j][k], items[j - 1][k - weight[j]] + value[j]);
				}
			}
		}

		cout << items[num][max_weight] << '\n';

	}
	return 0;
}
