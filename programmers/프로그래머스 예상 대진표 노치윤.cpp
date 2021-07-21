using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    while (true) {
        a = (a - 1) / 2 + 1;//a의 다음 라운드 번호
        b = (b - 1) / 2 + 1;//b의 다음 라운드 번호
        if (a == b) {//a,b가 맞붙게 되는 경우 그 다음 라운드 번호는 같게됨.
            break;
        }
        else {
            answer++;
        }
    }

    return answer;
}