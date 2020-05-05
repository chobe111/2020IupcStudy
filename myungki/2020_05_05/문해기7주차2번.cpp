//
// Created by myungki cho on 2020/05/01.
//

#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 1002
using namespace std;

int parent[MAX];
bool visited[MAX];

int T;

struct vertex {
    int a, b;

    vertex(int a, int b) {
        this->a = a;
        this->b = b;
    }
};

class Edge {
public:
    int s, e, distance;

    Edge(int s, int e, int distance) {
        this->s = s;
        this->e = e;
        this->distance = distance;
    }

    bool operator<(const Edge &ed) const {
        return this->distance < ed.distance;
    }
};

int get_parent(int a) {
    if (parent[a] == a) return a;
    return get_parent(parent[a]);
}

void union_parent(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool find_parent(int a, int b) {
    return get_parent(a) == get_parent(b);
}

vector<vertex> v;
vector<Edge> edges;

void solve(int base_price) {
    int ans;
    int fee_sum = 0;
    int cnt = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (!find_parent(edges[i].s, edges[i].e)) {
            union_parent(edges[i].s, edges[i].e);
            fee_sum += edges[i].distance;
        }
    }

    ans = fee_sum + base_price;

    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        int sum = 0;

        for (int i = 0; i <= N; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            sum += a;
            v.emplace_back(a, b);
        }
//          간선 이어줌.
        for (int i = 0; i < N; i++) {
//          fee = 수수료
            edges.emplace_back(i, N, v[i].a);
            if (i != N - 1)
                edges.emplace_back(i, i + 1, v[i + 1].b);
        }


        sort(edges.begin(), edges.end());

        solve(sum);
    }

}