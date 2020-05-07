#include<iostream>
#include<string>
using namespace std;
string str1, str2;
int LCS[1001][1001] = {};

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int tc = 0;tc < T;tc++) {
		string A, B;
		cin >> A >> B;
		//공통부분서열의 길이를 지정하기 위해 편의상 문자열 앞에 0을 추가해주는 것이 좋음
		str1 = '0' + A;
		str2 = '0' + B;

		for (int i = 0;i < str1.length();i++)
		{
			for (int j = 0;j < str2.length();j++)
			{
				//초기 LCS의 값을 0으로 지정해주고 계속 for문을 실행한다
				if (i == 0 || j == 0)
				{
					LCS[i][j] = 0;
					continue;
				}
				
				//서로 같은 문자를 가진 위치가 나타났다면 제일 최근에 결정된 LCS값에서 1을 더해준다
				if (str1[i] == str2[j])
				{
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
				}
				//서로 같은 문자를 가지고 있지 않는 위치가 나타났다면
				//제일 최근에 결정된 LCS값들 중 LCS[i - 1][j]와 LCS[i][j - 1]중 큰 값을 저장해준다
				else
				{
					if (LCS[i - 1][j] > LCS[i][j - 1])
					{
						LCS[i][j] = LCS[i - 1][j];
					}
					else
					{
						LCS[i][j] = LCS[i][j - 1];
					}
				}
			}	
		}
		//구하고자하는 최종적인 LCS의 값을 출력한다.
		cout << LCS[str1.length() - 1][str2.length() - 1] << endl;
	}
	

	return 0;
}
