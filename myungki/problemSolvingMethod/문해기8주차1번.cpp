////
//// Created by myungki cho on 2020/05/06.
////
//
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//#define MAX 1000001
//using namespace std;
//
//int T, M, N;
//
//int arr[MAX];
//int score[MAX];
//
//void solve() {
//    long long ans = 0;
//
//    int cnt = 0;
//    for (int i = 1; i <= M; i++) {
//        cnt += 1;
//        if (i == 1) continue;
//        if (arr[i] < arr[i - 1]) {
//            ans += score[cnt - 1];
//            cnt = 1;
//        }
//    }
//
//    cout << ans + score[cnt] << "\n";
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> T;
//
//    while (T--) {
//        cin >> M >> N;
//
//        for (int i = 1; i <= M; i++) {
//            cin >> score[i];
//        }
//
//        for (int i = 1; i <= M; i++) {
//            int a, b;
//            cin >> a >> b;
//            arr[b] = a;
//        }
//
//        solve();
//    }
//    return 0;
//}