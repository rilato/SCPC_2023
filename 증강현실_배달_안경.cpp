#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

int Answer;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, test_case;

    cin >> T;

    for (test_case = 0; test_case < T; test_case++) {
        int N, A, B;
        Answer = 0;

        cin >> N >> A >> B;

        int a = max(A, B);
        int b = min(A, B);

        // b상자(적게 들어있는 상자)의 개수
        int bCount = N / b;
        int aCount;

        while (1) {
            // 적게 들어있는 b상자만으로 다 채울 수 있는 경우
            if (bCount * b == N) {
                Answer = bCount;
                break;
            }
            // a상자를 써야하는 경우
            else {
                int aCount = (N - bCount * b) / a;

                if (aCount * a + bCount * b == N) {
                    Answer = aCount + bCount;
                    break;
                }
                else {
                    bCount--;
                }
            }
        }

        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}
