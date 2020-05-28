#include<iostream>
#include<algorithm>
using namespace std;


int marvels[100001] = {}; 
int shorter[100001] = {}; 
int main()
{
	int T, L, num, idx;
	cin >> T;
	for (int i = 0;i < T;i++)
	{
		cin >> num >> L >> idx;
		for (int j = 0;j < num;j++)
		{
			cin >> marvels[j];
			if (marvels[j] > 0) {
				shorter[j] = L - marvels[j];
			}
			else if (marvels[j] < 0) {
				shorter[j] = marvels[j] * -1;
			}
		}
		sort(marvels, marvels + num);
		sort(shorter, shorter + num);
		cout << shorter[idx - 1] << '\n';
	}
	return 0;
}
