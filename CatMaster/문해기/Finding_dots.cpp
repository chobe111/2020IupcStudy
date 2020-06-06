#include<iostream>
#include<string.h>		//memset�� ����ϱ� ���� �ʿ��� ���
#include<vector>
#include<queue>

using namespace std;


//��ǥ�� ����ü(x��ǥ, y��ǥ)
struct Pos {
	int y;
	int x;
};


//Node ����ü -> NodeOP�� ������ ���� 2���� x,y��ǥ�� �Űܴ���� ���� �Լ�
struct Node {
	int x1, y1, x2, y2;
};

//NodeOP ����ü -> Node���� �����ϱ� ���� �Լ�
//n1 ��ǥ�ְ� n2 ��ǥ���߿� �켱������ y ��ǥ�� ���� ���� ���� ���� �������ְ�, y��ǥ�� ���� ���� ���ٸ� x��ǥ�� ���� ���� ���� ���� �������ش�
//counting sort�������, ������ ������ �Ǿ����� ������ �迭�� ũ��� ��Ƴ���, �ش� �Ÿ�, �� ������ ����� ������ �Ǹ�
//�� ���� ������ �Ǵ� ��ǥ�� �ش� �Ÿ��� ��ġ�� ���� ��ǥ���� ���������ִ� �ý���
struct NodeOP {
	bool operator()(const Node& n1, const Node& n2) const {
		if (n1.y1 + n1.y2 == n2.y1 + n2.y2)
			return n1.x1 + n1.x2 > n2.x1 + n2.x2;
		return n1.y1 + n1.y2 > n2.y1 + n2.y2;
	};
};

//PQ�� Node�� �� vector<Node> �����̳ʸ� NodeOP ��Ģ�� ���� �� �� �������ش�
typedef priority_queue<Node, vector<Node>, NodeOP> PQ;

PQ pq[26][20001];		//�־��� ��� ���� ������ �Ÿ��� �����صδ� �迭
vector<Pos> vp[26];		//���ĺ� A ~ Z�� ���� ������� ������ ���ĺ��� ���� x,y ��ǥ���� �����Ѵ�
bool used[101][101];	//��Ģ�� ���� ���� �� ������ ī��ֿ� 1�� �����Ѵ�

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

		//������ ���ĺ��鿡 ���Ͽ� ��� ���� �� ������ �Ÿ��� �ش��ϴ� �Ÿ��� ���� �� ��ǥ���� pq�� �������ش�
		//�̶� ����Ǿ����� ��ǥ���� pq�� �������ǿ� ���� �ڵ����� ���ĵǾ�����
		for (int alpha = 0; alpha < 26; alpha++) {
			for (int i = 0; i < vp[alpha].size(); i++) {
				for (int j = i + 1; j < vp[alpha].size(); j++) {
					auto& p1 = vp[alpha][i];
					auto& p2 = vp[alpha][j];
					pq[alpha][(p1.y - p2.y) * (p1.y - p2.y) + (p1.x - p2.x) * (p1.x - p2.x)].push({ p1.x, p1.y , p2.x, p2.y });
				}
			}
		}


		//������ ���ĺ��鿡 ���Ͽ� ���ĺ� �ȿ� �� �� �ִ� �ִ����� ���� �� ������ �Ÿ����� ������ŭ for���� �����ش�
		for (int alpha = 0; alpha < 26; alpha++) {
			for (int i = 1; i <= N * N * 2; i++) {
				//������ ���� �� for���� �ش� ���ĺ� ���� �ִ� ���� �� ���̵��� �Ÿ����� ������ �ٴڳ��� �Ǹ� ����Ǿ�����

				while (!pq[alpha][i].empty()) {
					auto ele = pq[alpha][i].top();
					pq[alpha][i].pop();
					//���� �ش� ��ǥ �� �� �ϳ��� ������ �ִܰŸ��� �νĵǾ����� ����� �Ǿ����ٸ�
					//����ϴ� �۾� �� �ش���ǥ���� used�� true �ִ� ������ ���� �ʴ´�
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