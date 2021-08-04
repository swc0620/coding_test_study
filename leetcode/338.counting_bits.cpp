class Solution {
public:
    string to_binary(int num) {
        string s = "";
        while (num > 0) {
            if (num % 2 == 1){
                s = "1" + s;
            }
            else {
                s = "0" + s;
            }
            num /= 2;
        }
        return s;
    }

    vector<int> countBits(int n) {
        vector <string> temp;
        vector <int> answer;
        // 1 갯수 세기
        int cnt = 0;
        // 2진수 벡터 만들기
        for (int i=0; i<n+1; i++){
            temp.push_back(to_binary(i));
        }
        
        for (int i=0; i<temp.size(); i++){
            cnt = 0;
            for (int j=0; j<temp[i].size(); j++){
                if (temp[i][j] == '1'){
                    cnt += 1;
                }
            }
            answer.push_back(cnt);
        }
        return answer;
    }
};