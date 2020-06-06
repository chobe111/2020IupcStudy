#include<iostream>
#include<string.h>		//memset을 사용하기 위해 필요한 헤더
#include<vector>
#include<queue>

using namespace std;


//좌표값 구조체(x좌표, y좌표)
struct Pos {
	int y;
	int x;
};


//Node 구조체 -> NodeOP의 실행을 위해 2개의 x,y좌표를 옮겨담고자 만든 함수
struct Node {
	int x1, y1, x2, y2;
};

//NodeOP 구조체 -> Node들을 정렬하기 위한 함수
//n1 좌표쌍과 n2 좌표쌍중에 우선적으로 y 좌표의 합이 작은 것을 먼저 정렬해주고, y좌표의 합이 서로 같다면 x좌표의 합이 작은 것을 먼저 정렬해준다
//counting sort기법으로, 정렬의 기준이 되어지는 범위를 배열의 크기로 잡아놓고, 해당 거리, 즉 정렬의 대상이 나오게 되면
//그 값이 나오게 되는 좌표를 해당 거리가 위치한 곳에 좌표값을 정리시켜주는 시스템
struct NodeOP {
	bool operator()(const Node& n1, const Node& n2) const {
		if (n1.y1 + n1.y2 == n2.y1 + n2.y2)
			return n1.x1 + n1.x2 > n2.x1 + n2.x2;
		return n1.y1 + n1.y2 > n2.y1 + n2.y2;
	};
};

//PQ를 Node가 들어간 vector<Node> 컨테이너를 NodeOP 규칙에 따라 비교 및 정렬해준다
typedef priority_queue<Node, vector<Node>, NodeOP> PQ;

PQ pq[26][20001];		//주어진 모든 점들 사이의 거리를 저장해두는 배열
vector<Pos> vp[26];		//알파벳 A ~ Z를 각각 구분지어서 각각의 알파벳에 대한 x,y 좌표값을 저장한다
bool used[101][101];	//규칙에 따라 제거 및 참고한 카드쌍에 1을 저장한다

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < 26; i++)
			vp[i].clear();
		memset(used, 0, sizeof(used));

		for (int i = 0; i < M; i++) {
			char type;
			int x, y;
			cin >> type >> x >> y;
			vp[type - 'A'].push_back({ y,x });
		}

		//각각의 알파벳들에 대하여 모든 점과 점 사이의 거리와 해당하는 거리를 만들어낸 두 좌표값을 pq에 저장해준다
		//이때 저장되어지는 좌표값은 pq의 정렬조건에 따라 자동으로 정렬되어진다
		for (int alpha = 0; alpha < 26; alpha++) {
			for (int i = 0; i < vp[alpha].size(); i++) {
				for (int j = i + 1; j < vp[alpha].size(); j++) {
					auto& p1 = vp[alpha][i];
					auto& p2 = vp[alpha][j];
					pq[alpha][(p1.y - p2.y) * (p1.y - p2.y) + (p1.x - p2.x) * (p1.x - p2.x)].push({ p1.x, p1.y , p2.x, p2.y });
				}
			}
		}


		//각각의 알파벳들에 대하여 알파벳 안에 들어갈 수 있는 최대한의 점과 점 사이의 거리들의 갯수만큼 for문을 돌려준다
		for (int alpha = 0; alpha < 26; alpha++) {
			for (int i = 1; i <= N * N * 2; i++) {
				//하지만 보통 이 for문은 해당 알파벳 내에 있는 점과 점 사이들의 거리들의 갯수가 바닥나게 되면 종료되어진다

				while (!pq[alpha][i].empty()) {
					auto ele = pq[alpha][i].top();
					pq[alpha][i].pop();
					//만약 해당 좌표 둘 중 하나라도 이전에 최단거리로 인식되어져서 출력이 되어졌다면
					//출력하는 작업 및 해당좌표값의 used에 true 넣는 과정을 하지 않는다
					if (used[ele.y1][ele.x1] || used[ele.y2][ele.x2])
						continue;
					used[ele.y1][ele.x1] = true;
					used[ele.y2][ele.x2] = true;

					if (ele.y1 > ele.y2 || (ele.y1 == ele.y2 && ele.x1 > ele.x2))
						cout << (char)(alpha + 'A') << " " << ele.x2 << " " << ele.y2 << " " << ele.x1 << " " << ele.y1 << '\n';
					else
						cout << (char)(alpha + 'A') << " " << ele.x1 << " " << ele.y1 << " " << ele.x2 << " " << ele.y2 << '\n';
				}
			}
		}
	}
	return 0;
}