#include <cstdio>
#include <algorithm>
using namespace std;

int N, S[100000], cnt; // cnt : 팀에 속한 사람들의 수, S[i] : i번째 팀원이 좋아하는 팀원의 인덱스가 저장되어지는 배열
bool visited[100000], finished[100000];

//어떤 분반에 N명의 사람들이 존재한다고 가정하자
//해당분반에서 팀을 조성하려고하는데 이때 팀은 s1이 s2를, s2가 s3를.. 그런식으로 sN이 s1을 좋아하는 순환구조로 이루어져야한다
//이때 각자들이 알아서 팀을 조성하게 된다면, 팀으로 조성되지 못한 사람들의 수를 구하여라


//일명 사이클이 어디있는지 찾아내고, 해당 사이클을 이루는 사람의 수를 체크하는 방식으로
//dfs가 포함되어있다 볼 수 있다
void dfs(int curr) {
	//일단 현재 부분을 true로 지정해주고, curr가 좋아하는 사람의 인덱스를 next에 저장해준다
	visited[curr] = true;
	int next = S[curr];

	//만약 이미 dfs가 진행된 곳의 사람을 좋아한다면
	if (visited[next]) {
		//해당 지점의 사람부터 시작해서 하나의 사이클을 이루는 팀을 모두 cnt값에 포함시켜준다
		//이 for문은 다시금 해당 지점의 사람이 나올 때까지 진행된다
		if (!finished[next]) {
			for (int temp = next; temp != curr; temp = S[temp]) 
				cnt++;
			cnt++; // 자기 자신
		}
	}
	//dfs가 진행되어진 곳이 아닌 곳의 사람을 좋아한다면 그대로 dfs를 실행해주면 된다
	else dfs(next);

	//이 부분이 실행되는 경우는 위의 visited[next]==true, finished[next]==false일때의 경우이다
	//최종적으로 curr는 사이클을 구성하는 시작점이자 끝점이라 볼 수 있다
	finished[curr] = true;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", S + i);
			S[i]--;		//인덱스가 0부터 시작하는 관계상 입력된 S[i]의 값에서 1을 빼준다
		}

		// 각 컴포넌트에 대해 DFS 시작

		//cnt 초기화 및 visited와 finished 배열안의 값을 모두 false로 초기화
		//string.h 넣고 false로 초기화해도 된다
		fill(visited, visited + N, false);
		fill(finished, finished + N, false);
		cnt = 0;

		//방문되어진 적이 없는, 즉 dfs가 실행된 적이 없는 부분이라면 바로 dfs를 실행해준다
		for (int i = 0; i < N; i++)
			if (!visited[i]) dfs(i);
		printf("%d\n", N - cnt);
	}
	return 0;
}
