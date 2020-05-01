//
// Created by myungki cho on 2020/04/29.
//

#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>

#define MOD 1013
#define MAX 10
using namespace std;
int ans, N, a, b, x, T;
int arr[MAX];
int visited[MAX];
vector<int> v;

void solve() {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i] * pow(x, i);
    }
    if (sum % MOD >= a && sum % MOD <= b) ans++;
    return;
}

void dfs(int cnt) {
    if (cnt == N) {
        solve();
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        v.push_back(arr[i]);
        dfs(cnt + 1);
        v.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;

    while (T--) {
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        v.clear();
        ans = 0;
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        cin >> a >> b >> x;
        dfs(0);
        cout << ans << "\n";
    }
}