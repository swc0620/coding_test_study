#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> db[3][2][2][2];

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string key[4], tmp;
    for (string s : info) {
        istringstream iss(s);
        vector<int> idx;
        string point = "";
        iss >> key[0] >> key[1] >> key[2] >> key[3] >> point;//문자열 parsing
        for (int i = 0; i <= 3; i++) {
            if (key[i] == "cpp" || key[i] == "backend" || key[i] == "junior" || key[i] == "chicken") idx.push_back(0);
            else if (key[i] == "python") idx.push_back(2);
            else idx.push_back(1);
        }
        db[idx[0]][idx[1]][idx[2]][idx[3]].push_back(stoi(point));
    }

    for (int i = 0; i < 3; i++)//이진탐색을 사용하기위해 sort해줌.
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    sort(db[i][j][k][l].begin(), db[i][j][k][l].end());

    for (string s : query) {
        istringstream iss(s);
        vector<int> idx_lower;
        vector<int> idx_upper;
        string tmp = "";
        string point = "";
        iss >> key[0] >> tmp >> key[1] >> tmp >> key[2] >> tmp >> key[3] >>
            point;
        int ai, bi, aj, bj, ak, bk, al, bl;
        if (key[0] == "cpp") ai = bi = 0;
        else if (key[0] == "java") ai = bi = 1;
        else if (key[0] == "python") ai = bi = 2;
        else { ai = 0; bi = 2; } // '-'

        if (key[1] == "backend") aj = bj = 0;
        else if (key[1] == "frontend") aj = bj = 1;
        else { aj = 0; bj = 1; }; // '-'

        if (key[2] == "junior") ak = bk = 0;
        else if (key[2] == "senior") ak = bk = 1;
        else { ak = 0; bk = 1; } // '-'

        if (key[3] == "chicken") al = bl = 0;
        else if (key[3] == "pizza") al = bl = 1;
        else { al = 0; bl = 1; } // '-'
        int score = stoi(point);

        int ans = 0;
        for (int i = ai; i <= bi; i++) {
            for (int j = aj; j <= bj; j++) {
                for (int k = ak; k <= bk; k++) {
                    for (int l = al; l <= bl; l++) {
                        int n = db[i][j][k][l].size();
                        if (n == 0) continue;

                        auto iter = lower_bound(db[i][j][k][l].begin(), db[i][j][k][l].end(), score);//이진탐색.

                        if (iter == db[i][j][k][l].end()) continue;
                        ans += n - (iter - db[i][j][k][l].begin());
                    }
                }
            }
        }
        answer.push_back(ans);

    }

    return answer;
}