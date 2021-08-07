#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] % 2 == 0)
            answer.push_back(numbers[i] + 1);
        else {
            long long bit = 1;
            while (true) {
                if ((numbers[i] & bit) == 0) break;
                bit *= 2;
            }
            bit = bit / 2;
            answer.push_back(numbers[i] + bit);
        }
    }
    return answer;
}

/*
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string to_binary(int num) {
	string s = "";
	while (num > 0) {
		if (num % 2 == 1) s = "1" + s;
		else s = "0" + s;
		num >>= 1;
	}
	return s;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    vector<string> binary; //{'10', '111'}
    int cnt, n;
    
    for (int i=0; i<numbers.size(); i++){
        binary.push_back(to_binary(numbers[i]));
    }
    
    for (int i=0; i<binary.size(); i++){
        cnt = 0;
        n = 0;
        
        while (true){
            if (numbers[i] % 2 == 0){
                answer.push_back(numbers[i]+1);
                break;
            }
            else{
                n += 1;
                long long temp_num = numbers[i]+n;
                string temp = to_binary(numbers[i]+n); // "11" (3의 이진법 버전)
                for (int j=0; j<binary[i].size(); j++){
                    if (temp.size() != binary[i].size()){ //두개 자릿수가 다를 때
                        cnt += 1;
                        temp.erase(0, 1);
                    }
                        
                    if (temp[j] != binary[i][j]){ // 각 자리수에 달라지면
                        cnt += 1;
                        if (cnt > 2){
                            break;
                        }
                    }  
                }

                if (cnt == 1 || cnt == 2){
                    answer.push_back(temp_num);
                    break;
                }
            }
        }
    }
    return answer;
}

int main (){
    vector <long long > numbers;
    vector <long long > answer;
    numbers.push_back(2);
    numbers.push_back(7);

    std::cout<< "Hi" << " ";

    answer = solution(numbers);
    for (int i=0; i<answer.size(); i++){
        std::cout<< answer[i] << " ";
    }
    std::cout<< "Bye" << " ";
}
*/