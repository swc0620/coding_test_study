#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> vec(n + 1, 0);//인덱스==그 숫자를 만들기 위해 0부터 n까지 n+1 할당
    vec[0] = 1;//소수면 0, 아니면 1
    vec[1] = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (vec[i] == 1) {
            continue;
        }
        int j = i * 2;
        while (j <= n) {
            vec[j] = 1;
            j += i;
        }
    }
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == 0)answer++;
    }
    return answer;
}
