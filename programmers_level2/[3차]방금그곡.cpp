#include <string>
#include <vector>
#include <sstream>

using namespace std;

void sharpToLower(string &musicsheet) {
    string result = "";
    int idx = 0, last = musicsheet.length();
    
    while (idx < last) {
        if (musicsheet[idx+1] == '#') {
            result += tolower(musicsheet[idx]); // C# -> c
            idx += 2;
        } else {
            result += musicsheet[idx];
            idx += 1;
        }
    }
    
    musicsheet = result;
}

int getPlayTime(string start, string end) {
    int hour_diff = stoi(end.substr(0,2)) - stoi(start.substr(0,2));
    int min_diff = stoi(end.substr(3,2)) - stoi(start.substr(3,2));
    return hour_diff * 60 + min_diff;
}

string solution(string m, vector<string> musicinfos) {
    // # -> 소문자
    sharpToLower(m);
    
    int max_time = 0;
    string answer = "(None)";
    
    for (string info : musicinfos) {
        // 음악이 시작한 시각, 끝난 시각, 음악 제목, 악보 정보 파싱
        stringstream ss(info);
        string start, end, title, musicsheet;
        getline(ss, start, ',');
        getline(ss, end, ',');
        getline(ss, title, ',');
        getline(ss, musicsheet, ',');
        
        // # -> 소문자
        sharpToLower(musicsheet);
        
        // 재생된 시간 구하기
        int playtime = getPlayTime(start, end);
        int full = playtime / musicsheet.length(); // 악보정보가 온전히 반복 재생
        int part = playtime % musicsheet.length(); // 악보정보의 부분만 재생
        
        // 재생된 시간만큼 재생된 노래 문자열 만들기
        string played_music = "";
        for (int i=0; i<full; ++i)
            played_music += musicsheet;
        played_music += musicsheet.substr(0,part);
        
        // 재생된 노래가 들은 노래 m을 포함하고, 재생시간이 max_time보다 클 때 노래제목 저장
        if (played_music.find(m) != string::npos && max_time < playtime) { // < 이므로 재생된 시간도 같을 경우 먼저 입력된 음악 제목을 반환
            max_time = playtime;
            answer = title;
        }
    }
    return answer;
}