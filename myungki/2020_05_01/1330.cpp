//
// Created by myungki cho on 2020/05/01.
//


#include<iostream>
#include<algorithm>

using namespace std;

void solve(int num) {
    if((num % 4 == 0 && num % 100 != 0) || num % 400 == 0)
    {
        cout << 1;
        return;
    }
    cout << 0;
}

int main() {

    int num;
    cin >> num;
    solve(num);
}
