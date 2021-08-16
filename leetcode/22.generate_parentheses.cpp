class Solution {
public:
vector<string> generateParenthesis(int n) {
    vector<string> res;
    generateParenthesis(res, "", n, n);
    return res;
}

void generateParenthesis(vector<string>& res, string str, int n1, int n2) {
    if(n1 == 0 && n2 == 0)
        res.push_back(str);
    else{
        if(n1 > 0)
            generateParenthesis(res, str + "(", n1 - 1, n2);
        if(n2 > n1)
            generateParenthesis(res, str + ")", n1, n2 - 1);
    }
  }
};