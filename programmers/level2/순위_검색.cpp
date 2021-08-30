#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

map<string,vector<int>> DB; // 지원자 정보를 가지고 검색 가능한 모든 쿼리가 key, 그 쿼리에 해당하는 지원자 풀에서의 모든 점수가 value

// 지원자 정보 채워넣기
void mapInfo(const string &info) {
    string info_arr[4][2] = { {"-","-"},{"-","-"},{"-","-"},{"-","-"} }; // 각 원소값을 고려하거나, 고려하지 않을 수 있음. info에는 무조건 -이 아닌 원소값 들어오므로 -로 초기화
    int info_score;
    
    // 파싱
    istringstream ss(info);
    ss >> info_arr[0][1] >> info_arr[1][1] >> info_arr[2][1] >> info_arr[3][1] >> info_score; // info 지원자의 개발언어, 직군, 경력, 소울푸드 원소값 차례대로 받아오기 [["-","java"],["-","frontend"]...]
    
    // info가 해당될 수 있는 모든 쿼리 만들기
    for (int i=0; i<2; ++i) { // "-" 또는 해당되는 원소값
        for (int j=0; j<2; ++j) {
            for (int k=0; k<2; ++k) {
                for (int l=0; l<2; ++l) {
                    // DB의 key
                    string info_string = info_arr[0][i] + ' ' + info_arr[1][j] + ' ' + info_arr[2][k] + ' ' + info_arr[3][l];
                    // DB에 저장
                    DB[info_string].push_back(info_score);
                }
            }
        }
    }
}

int answerQuery(const string &query) {
    int cnt{ 0 };
    
    string query_arr[4];
    int query_score;
    
    string trash;
    istringstream ss(query);
    ss >> query_arr[0] >> trash >> query_arr[1] >> trash >> query_arr[2] >> trash >> query_arr[3] >> query_score;
    
    string query_string = query_arr[0] + ' ' + query_arr[1] + ' ' + query_arr[2] + ' ' + query_arr[3];
    vector<int> scores = DB[query_string];
    cnt = scores.end() - lower_bound(scores.begin(),scores.end(),query_score);
    
    return cnt;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    // info를 먼저 DB에 담기
    for (const string &applicant : info)
        mapInfo(applicant);
    
    // DB에 저장되어 있는 점수 정렬
    for (auto &data : DB)
        sort(data.second.begin(),data.second.end());
    
    // query 검색
    for (const string &search : query)
        answer.push_back(answerQuery(search));
    
    return answer;
}