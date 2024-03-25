class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        int n = s.length();
        for(int i = 0; i<n; i++){
            if(isalnum(s[i])){
                temp.push_back(tolower(s[i]));            
            }
        }
        n = temp.length();
        for(int i = 0; i<n/2; i++){
            if(temp[i]!=temp[n-i-1]) return false;
        }
        return true;
    }
};