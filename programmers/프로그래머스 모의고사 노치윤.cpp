#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a = 0;
    int b = 0;
    int c = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == (i % 5 + 1)) {
            a++;
        }
    }
    for (int i = 0; i < answers.size(); i++) {
        int rest = i % 8;
        if (rest % 2 == 0) {
            if (answers[i] == 2) {
                b++;
            }
        }
        else if (rest == 1) {
            if (answers[i] == 1) {
                b++;
            }
        }
        else if (rest == 3) {
            if (answers[i] == 3) {
                b++;
            }
        }
        else if (rest == 5) {
            if (answers[i] == 4) {
                b++;
            }
        }
        else if (rest == 7) {
            if (answers[i] == 5) {
                b++;
            }
        }
    }
    for (int i = 0; i < answers.size(); i++) {
        int rest = i % 10;
        if (rest == 0 || rest == 1) {
            if (answers[i] == 3) {
                c++;
            }
        }
        else if (rest == 2 || rest == 3) {
            if (answers[i] == 1) {
                c++;
            }
        }
        if (rest == 4 || rest == 5) {
            if (answers[i] == 2) {
                c++;
            }
        }
        if (rest == 6 || rest == 7) {
            if (answers[i] == 4) {
                c++;
            }
        }
        if (rest == 8 || rest == 9) {
            if (answers[i] == 5) {
                c++;
            }
        }
    }
    answer.push_back(1);
    if (b > a) {
        answer.pop_back();
        answer.push_back(2);
    }
    else if (b == a) {
        answer.push_back(2);
    }
    if (answer.back() == 1) {
        if (c > a) {
            answer.pop_back();
            answer.push_back(3);
        }
        else if (c == a) {
            answer.push_back(3);
        }
    }
    else if (answer.back() == 2) {
        if (c > b) {
            answer.clear();
            answer.push_back(3);
        }
        if (c == b) {
            answer.push_back(3);
        }
    }
    return answer;
}