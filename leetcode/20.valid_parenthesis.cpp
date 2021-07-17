class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int answer = 0;
        if (s.size() % 2 == 1){ // 홀수면 짝이 안맞음
            return false;
        }
        
        for (int i=0; i<s.size(); i++){
            if (st.empty()){
                if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                    st.push(s[i]);
                }
                else if (s[i] == ')' || s[i] == '}' || s[i] == '}'){
                    return false;
                }
             }
            else{   // stack에 하나라도 있을 때
                if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                    st.push(s[i]);
                }
                else if (s[i] == ')'){
                    if (st.top() == '('){
                        st.pop();
                        answer = 1;
                    }
                    else{
                        answer = 0;
                        break;
                    }
                }
                else if (s[i] == '}'){
                    if (st.top() == '{'){
                        st.pop();
                        answer = 1;
                    }
                    else{
                        answer = 0;
                        break;
                    }
                }
                else if (s[i] == ']'){
                    if (st.top() == '['){
                        st.pop();
                        answer = 1;
                    }
                    else{
                        answer = 0;
                        break;
                    }
                }
            }
        }
        
        if (answer == 0 || !st.empty()) return false;
        else return true;
    }
};

// !st.empty()인 경우를 고려한 이유: [[[] -> [[ , 2개가 남음
