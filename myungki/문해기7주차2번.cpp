////
//// Created by myungki cho on 2020/04/30.
////
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//#define INF 987654321
//#define MAX 1001
//using namespace std;
//
//typedef pair<int, int> pii;
//int dp[MAX];
//
//void solve(vector<pii> v, int N) {
//    for (int i = 1; i <= N; i++) {
//        int fee = INF;
//        int pc = 0;
////      총 물품가격
//        int sum = 0;
//        for (int j = i; j <= N; j++) {
////          수수료 계산
//            sum += v[j - 1].first;
//            fee = min(fee, v[j - 1].first);
//            if (j == i) pc = 0; else pc += v[j - 1].second;
//            dp[j] = min(dp[j], fee + sum + pc + dp[i - 1]);
//        }
//    }
//}
//
//int main() {
//    int T;
//
//    cin >> T;
//
//    while (T--) {
//        int N;
//        cin >> N;
//        vector<pii> v;
//        for (int i = 1; i <= N; i++) {
//            int a, b;
//            cin >> a >> b;
//            v.push_back(make_pair(a, b));
//        }
//        for (int i = 1; i < MAX; i++) {
//            dp[i] = INF;
//        }
//        solve(v, N);
//        cout << dp[N];
//    }
//
//    return 0;
//}
