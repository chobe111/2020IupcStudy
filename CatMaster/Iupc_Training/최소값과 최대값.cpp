#include <iostream>
#include <cmath>
#include<algorithm>

using namespace std;

long long int arr[100001];
long long int segtree[400004];
long long int segtree2[400004];

long long int init(int left, int right, int node) {
	if (left == right) {
		return segtree[node] = arr[left];
	}

	int mid = (left + right) / 2;

	return segtree[node] = min(init(left, mid, node * 2), init(mid + 1, right, node * 2 + 1));
}

long long int search_min(int left, int right, int node, int node_left, int node_right) {
	if (node_left > right || node_right < left) {
		return 1000000000;
	}

	if (node_left >= left && right >= node_right) {
		return segtree[node];
	}

	int mid = (node_left + node_right) / 2;

	return min(search_min(left, right, node * 2, node_left, mid), search_min(left, right, node * 2 + 1, mid + 1, node_right));
}


long long int init2(int left, int right, int node) {
	if (left == right) {
		return segtree2[node] = arr[left];
	}

	int mid = (left + right) / 2;

	return segtree2[node] = max(init2(left, mid, node * 2), init2(mid + 1, right, node * 2 + 1));
}

long long int search_max(int left, int right, int node, int node_left, int node_right) {
	if (node_left > right || node_right < left) {
		return -1;
	}

	if (node_left >= left && right >= node_right) {
		return segtree2[node];
	}

	int mid = (node_left + node_right) / 2;

	return max(search_max(left, right, node * 2, node_left, mid), search_max(left, right, node * 2 + 1, mid + 1, node_right));
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;

	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
	}

	init(1, N, 1);
	init2(1, N, 1);

	for (int j = 0;j < M;j++) {
		int s, e;
		cin >> s >> e;

		cout << search_min(s, e, 1, 1, N) << " " << search_max(s, e, 1, 1, N) << '\n';
	}

	return 0;
}

//이번엔 최댓값을 구하는 새그먼트 쿼리도 만들어봄
