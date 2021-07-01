#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n, 1); // 학생별 가진 체육복의 갯수를 담은 벡터 (크기는 학생 수 n만큼, 기본값은 1벌)
    
    for(int i = 0; i< reserve.size(); i++){ // 여벌 체육복이 있는 학생은 +1
        students[reserve[i]-1]++;
    }
    
    for(int i = 0; i< lost.size(); i++){    // 잃어버린 학생은 -1
        students[lost[i]-1]--;
    }
    
    for(int i = 0; i < n; i++){
        if(i > 0 && students[i] == 0 && students[i-1] == 2){
            students[i-1]--; students[i]++;
        }
        if(i < n-1 && students[i] == 0 && students[i+1] == 2){
            students[i+1]--; students[i]++;
        }
    }
    
    for(int s : students){
        if(s > 0) answer++;
    }
    
    return answer;
}