#include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }else{
                if(!st.empty()){
                    switch (c){
                        case ')': 
                            if(st.top()=='('){
                                st.pop();
                            }else{
                                return false;
                            }
                            break;
                        case '}':
                            if(st.top()=='{'){
                                st.pop();
                            }else{
                                return false;
                            }
                            break;
                        case ']':
                            if(st.top()=='['){
                                st.pop();
                            }else{
                                return false;
                            }
                            break;
                    }
                }else{
                    return false;
                }
            }

        }
        return st.empty();
    }
};