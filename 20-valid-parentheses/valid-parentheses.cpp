#include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char c: s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }else{
                if(c==')'){
                    if(!st.empty() && st.top()=='('){
                        st.pop();
                    }else{
                        return false;
                    }
                }
                if(c=='}'){
                    if(!st.empty() && st.top()=='{'){
                        st.pop();
                    }else{
                        return false;
                    }
                }
                if(c==']'){
                    if(!st.empty() && st.top()=='['){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }

        }
        if(st.empty()) return true;
        return false;
    }
};