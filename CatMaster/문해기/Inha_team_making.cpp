#include <cstdio>
#include <algorithm>
using namespace std;

int N, S[100000], cnt; // cnt : ���� ���� ������� ��, S[i] : i��° ������ �����ϴ� ������ �ε����� ����Ǿ����� �迭
bool visited[100000], finished[100000];

//� �йݿ� N���� ������� �����Ѵٰ� ��������
//�ش�йݿ��� ���� �����Ϸ����ϴµ� �̶� ���� s1�� s2��, s2�� s3��.. �׷������� sN�� s1�� �����ϴ� ��ȯ������ �̷�������Ѵ�
//�̶� ���ڵ��� �˾Ƽ� ���� �����ϰ� �ȴٸ�, ������ �������� ���� ������� ���� ���Ͽ���


//�ϸ� ����Ŭ�� ����ִ��� ã�Ƴ���, �ش� ����Ŭ�� �̷�� ����� ���� üũ�ϴ� �������
//dfs�� ���ԵǾ��ִ� �� �� �ִ�
void dfs(int curr) {
	//�ϴ� ���� �κ��� true�� �������ְ�, curr�� �����ϴ� ����� �ε����� next�� �������ش�
	visited[curr] = true;
	int next = S[curr];

	//���� �̹� dfs�� ����� ���� ����� �����Ѵٸ�
	if (visited[next]) {
		//�ش� ������ ������� �����ؼ� �ϳ��� ����Ŭ�� �̷�� ���� ��� cnt���� ���Խ����ش�
		//�� for���� �ٽñ� �ش� ������ ����� ���� ������ ����ȴ�
		if (!finished[next]) {
			for (int temp = next; temp != curr; temp = S[temp]) 
				cnt++;
			cnt++; // �ڱ� �ڽ�
		}
	}
	//dfs�� ����Ǿ��� ���� �ƴ� ���� ����� �����Ѵٸ� �״�� dfs�� �������ָ� �ȴ�
	else dfs(next);

	//�� �κ��� ����Ǵ� ���� ���� visited[next]==true, finished[next]==false�϶��� ����̴�
	//���������� curr�� ����Ŭ�� �����ϴ� ���������� �����̶� �� �� �ִ�
	finished[curr] = true;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", S + i);
			S[i]--;		//�ε����� 0���� �����ϴ� ����� �Էµ� S[i]�� ������ 1�� ���ش�
		}

		// �� ������Ʈ�� ���� DFS ����

		//cnt �ʱ�ȭ �� visited�� finished �迭���� ���� ��� false�� �ʱ�ȭ
		//string.h �ְ� false�� �ʱ�ȭ�ص� �ȴ�
		fill(visited, visited + N, false);
		fill(finished, finished + N, false);
		cnt = 0;

		//�湮�Ǿ��� ���� ����, �� dfs�� ����� ���� ���� �κ��̶�� �ٷ� dfs�� �������ش�
		for (int i = 0; i < N; i++)
			if (!visited[i]) dfs(i);
		printf("%d\n", N - cnt);
	}
	return 0;
}
