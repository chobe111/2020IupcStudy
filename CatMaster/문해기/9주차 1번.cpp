#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int w[501] = {};
int v[501] = {};

struct stuff {
	int value;
	int weight;
};


bool cmp(stuff a, stuff b) {
	if (a.value / a.weight <= b.value / b.weight) {
		return false;
	}
	else {
		return true;
	}
}

int main() {
	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		vector<stuff> bag;
		int num, max_weight;
		cin >> num >> max_weight;
		for (int j = 0;j < num;j++) {
			cin >> w[j];
		}

		for (int j = 0;j < num;j++) {
			cin >> v[j];
		}

		for (int j = 0;j < num;j++) {
			stuff temp;
			temp.value = v[j];
			temp.weight = w[j];
			bag.push_back(temp);
		}

		sort(bag.begin(), bag.end(),cmp);


		int temp_weight = 0;
		int answer = 0;

		for (int j = 0;j < bag.size();j++) {
			if (temp_weight + bag[j].weight <= max_weight) {
				answer += bag[j].value;
				temp_weight += bag[j].weight;
			}
			else if (temp_weight + bag[j].weight > max_weight) {
				answer += ((bag[j].value / bag[j].weight) * (max_weight - temp_weight));
				break;
			}
		}

		cout << answer << '\n';
	}

	return 0;
}
