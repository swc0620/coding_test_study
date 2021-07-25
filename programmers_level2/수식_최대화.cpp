#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long calculate(long long a, char op, long long b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
    }
}

long long solution(string expression) {
    vector<char> oper_list{ '+','-','*' };
    vector<long long> nums;
    vector<char> oper;
    string num{ "" };
    for (char c : expression) {
        if (c == '+' || c == '-' || c == '*') {
            oper.push_back(c);
            nums.push_back(stoll(num)); // 연산문자 직전까지의 수
            num = "";
        } else {
            num += c;
        }
    }
    nums.push_back(stoll(num)); // 연산 수식의 맨 마지막 수
    long long answer{ nums[0] };
    
    do {
        vector<char> tmp_oper = oper; // 복사
        vector<long long> tmp_nums = nums;
        
        for (int i=0; i<3; i++) { // oper_list 우선순위
            for (int j=0; j<tmp_oper.size(); j++) { // 연산수식 내 operand의 수보다 1 적음
                if (tmp_oper[j] == oper_list[i]) { // 해당 연산 우선 수행
                    tmp_nums[j] = calculate(tmp_nums[j],oper_list[i],tmp_nums[j+1]); // a자리에 a+b 넣기
                    // 사용한 것들 삭제
                    tmp_nums.erase(tmp_nums.begin()+j+1); // b 삭제
                    tmp_oper.erase(tmp_oper.begin()+j);
                    j--;
                }
            }
        }
        long long prize = abs(tmp_nums.front());
        if (answer < prize)
            answer = prize;
    } while (next_permutation(oper_list.begin(), oper_list.end()));
    
    return answer;
}

//실행한 결괏값 22000이(가) 기댓값 60420와(과) 다릅니다.