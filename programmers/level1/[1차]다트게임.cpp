#include <string>
#include <stack>
#include <cctype> // isdigit
#include <cmath> // pow

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    stack<int> points;
    
    for (char c : dartResult) {
        if (isdigit(c)) {
            if (points.top() == 1 && c == '0') { // 10이 들어왔을 때
                points.pop();
                points.push(10);
            } else {
                points.push(c-'0'); // char to int
            }
        } else { // ischar
            int point = points.top();
            points.pop();
            switch (c) {
                case 'S':
                    break;
                case 'D':
                    point = pow(point,2);
                    break;
                case 'T':
                    point = pow(point,3);
                    break;
                case '*': { // initializing inside switch case
                    point *= 2;
                    int prev = points.top();
                    points.pop();
                    points.push(prev*2);
                    break;
                }
                case '#':
                    point *= -1;
                    break;
            }
            points.push(point);
        }
    }
            
    while (!points.empty()) {
        answer += points.top();
        points.pop();
    }
    
    return answer;
}