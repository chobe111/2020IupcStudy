////
//// Created by myungki cho on 2020/05/05.
////
//
//#include<iostream>
//#include<algorithm>
//#include<map>
//
//using namespace std;
//
//char arr[101][101];
//char new_arr[101][101];
//
//map<char, char> m;
//
//int N, M;
//
//void make_map() {
//    m.insert(make_pair('.', '.'));
//    m.insert(make_pair('O', 'O'));
//    m.insert(make_pair('-', '|'));
//    m.insert(make_pair('|', '-'));
//    m.insert(make_pair('/', '\\'));
//    m.insert(make_pair('\\', '/'));
//    m.insert(make_pair('^', '<'));
//    m.insert(make_pair('<', 'v'));
//    m.insert(make_pair('v', '>'));
//    m.insert(make_pair('>', '^'));
//}
//
//int main() {
//
//    make_map();
//
//    cin >> N >> M;
//
//    for (int i = 1; i <= N; i++) {
//        for (int j = 1; j <= M; j++) {
//            char c;
//            cin >> c;
//            arr[i][j] = c;
//        }
//    }
//
//    for (int i = 1; i <= N; i++) {
//        for (int j = 1; j <= M; j++) {
//            new_arr[j][i] = m.find(arr[i][j])->second;
//        }
//    }
//
//    for (int i = M; i >= 1; i--) {
//        for (int j = 1; j <= N; j++) {
//            cout << new_arr[i][j];
//        }
//        cout << "\n";
//    }
//
//    return 0;
//}