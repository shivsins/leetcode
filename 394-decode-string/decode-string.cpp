class Solution {
public:
    string decodeString(string s) {
        // string ans="";
        int n=s.size();
        stack<string> st;
        int i=0;
        // st.push(string(1, s[i]));
        while(i<n){
            if(s[i]==']'){
                string temp="";
                while(st.top()!="["){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                int count = stoi(st.top());
                st.pop();
                string temp1="";
                while(count){
                    temp1=temp1+temp;
                    count--;
                }
                st.push(temp1);
            }else{
                string temp="";
                if(isdigit(s[i])){
                    while(isdigit(s[i])){
                        temp+=s[i];
                        i++;
                    }
                    st.push(temp);
                    i--;
                }else{
                    st.push(string(1, s[i]));
                }
            }
            i++;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};