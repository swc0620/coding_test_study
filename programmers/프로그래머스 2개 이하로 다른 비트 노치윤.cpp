#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

string makeBinary(long num) {
    string temp = "";
    while (num != 0) {
        temp += to_string(num % 2);
        num = num / 2;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 2 == 0) {
            answer.push_back(numbers[i] + 1);
        }
        else {//홀수 인 경우
            string a = makeBinary(numbers[i]);
            int len = a.length();
            int cnt = 0;
            for (int j = len - 1; j >= 0; j--) {
                if (a[j] == '0') {
                    break;
                }
                else cnt++;
            }//뒤에서부터 순서대로 1이나오는 개수를 cnt라고 하면 num+2^(cnt-1) 하면 최소 수가 나옴. -> 01(v)11~~1 -> 1011111~~1로 바꾸면 되기에. 1(v)만큼만 더해주면 왼쪽의 수가 오른쪽의 수가 됨. 따라서 2^(cnt-1)를 더함. 
            answer.push_back(numbers[i] + pow(2, cnt - 1));
        }
    }
    return answer;
}