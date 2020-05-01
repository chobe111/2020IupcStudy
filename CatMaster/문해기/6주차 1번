#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//10^1000 이하인 자연수 A와 100000 이하인 자연수 B가 있다
//이때, A가 B의 배수인지를 판별하라


int main() {
	ios::sync_with_stdio(false);
	int Tc;							//테스트케이스 갯수
	cin >> Tc;

	for (int i = 0;i < Tc;i++) {
		string A;
		string B;
		//너무 큰 숫자가 입력되기 때문에 big integer를 구현하려했으나
		//문자열로 숫자를 받아도 최대 1001자리이기 때문에 A와 B를 문자열 형식으로 받는다
		cin >> A >> B;
		int pt = B.length();
		//배수판정을 위한 연산이 어디까지 되었는지 표시하기 위한 변수
		//처음엔 A_temp를 B의 길이만큼 변환시켰으니 그부분부터 pt의 값이 지정되어진다
		//ex) B가 천의자릿수면 pt = 4
		int A_temp = 0;
		int B_temp = 0;
		//A_temp의 경우 문자열 A의 맨 왼쪽부터 B의 자릿수만큼 정수로 반환하여 저장해둔다
		//B_temp의 경우 문자열로 받은 B의 값을 정수로 돌려받는다
		for (int j = 0;j < B.length();j++) {
			A_temp += (A[j] - '0')*pow(10, B.length() - j - 1);
			B_temp += (B[j] - '0')*pow(10, B.length() - j - 1);
		}
		//배수판정방식
		//1. A[0]에서 A[pt - 1]만큼 받은 문자열을 순차적으로 정수로 변환하여 A_temp에 저장한다
		//2. A_temp의 값에서 B_temp를 될 수 있는 만큼 감산해준다
		//3. 만약 pt가 A.length()와 같지 않다면 현재 남은 A_temp의 값에 10을 곱해준 후, 그 값에 A[pt]를 정수로 변환한 것을 더해준 후 pt++를 해준다
		//4. 만약 pt가 A.length()와 같다면, 현재 남은 A_temp의 값이 0일경우 배수임이 맞으므로 1 출력 아니면 0을 출력
		while (pt <= A.length()) {
			int t = A_temp / B_temp;
			A_temp = A_temp - (B_temp * t);
			if (pt == A.length()) {
				if (A_temp != 0) {
					cout << 0 << endl;
					break;
				}
				else if (A_temp == 0) {
					cout << 1 << endl;
					break;
				}
			}
			else if (pt != A.length()) {
				A_temp = A_temp * 10;
				A_temp += A[pt] - '0';
				pt++;
			}
		}
	}
	return 0;
}

/*또 다른 방법
위의 방법과 의도는 같지만 비교적 코드가 간단하며 시간복잡도 또한 상대적으로 낮은 편이라 생각된다

#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string A;
	int B, Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		cin >> A >> B;
		int C = (A[0] - '0') % B;
		for (int j = 1;j < A.length();j++) {
			C = (10 * C + (A[j] - '0')) % B;
		}

		if (C == 0) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	return 0;
}

*/
