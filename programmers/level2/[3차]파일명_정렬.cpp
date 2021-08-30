#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int startOfNum(string filename) {
    int start = 0;
    while (!isdigit(filename[start])) ++start;
    return start;
}

string getHEAD(string filename) {
    string head = filename.substr(0,startOfNum(filename));
    transform(filename.begin(), filename.end(), filename.begin(), ::tolower);
    return head;
}

int getNUMBER(string filename) {
    // int start = startOfNum(filename);
    // int end = start;
    // while (!isdigit(filename[end])) ++end;
    // if (end )
    return stoi(filename.substr(startOfNum(filename),5)); // stoi는 주어진 문자열에서 앞에서부터 연속된 숫자까지만 자름. 최대 길이 5이므로 5개만 살펴봄
}
bool compHEAD(string &a, string &b) {
    return getHEAD(a) < getHEAD(b);
}

bool compNUMBER(string &a, string &b) {
    return getNUMBER(a) < getNUMBER(b);
}
vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), compHEAD);
    stable_sort(files.begin(), files.end(), compNUMBER);
    return files;
}