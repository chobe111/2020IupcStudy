#include<iostream>
#include<algorithm>
using namespace std;


int shorter[100001] = {}; //먼저 떨어지는 구슬의 이동거리를 오름차순으로 저장해둔다

//위의 두 배열의 총 크기는 해봤자 1MB 안쪽
//L의 길이인 막대에 num마리의 개미가 있다고 가정하자
//각각의 개미들의 이동속도는 1이며 idx값이 음수이면 왼쪽, 양수이면 오른쪽으로 이동한다.
//marvels[j]의 값의 절대값이 막대 위에서 개미들이 위치하는 좌표 및 이동방향이라 한다면
//idx번째로 
int main()
{
	int T, L, num, idx;
	int marvels; //구슬이 막대상에 위치하는 좌표 및 이동방향
	cin >> T;
	for (int i = 0;i < T;i++)
	{
		cin >> num >> L >> idx;
		for (int j = 0;j < num;j++)
		{
			cin >> marvels;
			//입력받은 구슬의 이동방향에 따라 충돌을 고려하지 않은 낙하까지의 최소이동거리를 저장해둔다
			if (marvels > 0) {
				shorter[j] = L - marvels;
			}
			else if (marvels < 0) {
				shorter[j] = marvels * -1;
			}
		}

		sort(shorter, shorter + num);
		cout << shorter[idx - 1] << '\n';
	}
	return 0;
}
