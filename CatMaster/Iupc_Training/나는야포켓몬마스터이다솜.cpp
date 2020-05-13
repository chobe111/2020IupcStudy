#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

//이게왜 실버 4인가싶을 정도로 다양한 함수 및 컨테이너를 사용했기에 남김
//M개의 포켓몬 이름이 포켓몬도감에 입력되어진다. 입력 순서대로 번호는 자동으로 입력되며 1부터 M까지 1씩 늘어난다.
//N개의 테스트케이스동안 포켓몬 이름을 입력하면 도감번호, 도감번호를 입력하면 포켓몬 이름을 출력하게 만들자


//map 컨테이너 사용 -> 문자열 기준으로 자동으로 정렬됨
//map1 : 포켓몬이름 사전순으로 도감번호 정렬 & 포켓몬이름을 키값으로 가짐으로써 도감번호를 value값으로 가진다
//map2 : 도감번호 순으로 포켓몬이름 정렬
map<string, int> map1;
string map2[100001] = {};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int M, N;
	cin >> M >> N;
	for (int i = 1;i <= M;i++) {
		string temp;
		cin >> temp;
		map1.insert(pair<string, int>(temp, i));
		map2[i] = temp;
	}

	for (int i = 0;i < N;i++) {
		string temp;
		cin >> temp;
		//입력된 temp가 숫자라면 map2[도감번호]를 사용하기 위해 stoi로 temp를 숫자로 변환해준다
		if (isdigit(temp[0])) {
			cout << map2[stoi(temp)] << '\n';
		}
		//입력된 temp가 문자열이라면 map1[포켓몬이름]을 사용하여 키값에 해당하는 value값을 출력해준다
		else {
			cout << map1[temp] <<'\n';
		}
	}
	return 0;
}
