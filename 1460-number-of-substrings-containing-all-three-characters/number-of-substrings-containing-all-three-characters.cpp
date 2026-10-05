class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last = {-1,-1,-1};
        int ans=0;
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
            ans=ans+ 1+min(last[0],min(last[1],last[2]));
        }
        return ans;
    }
};