class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;
        for(char c: s){
            mp[c]++;
        }
        string ans="";
        for(char c: order){
            int count = mp[c];
            while(count){
                ans=ans+c;
                mp[c]--;
                count--;
            }
        }
        for(auto it : mp){
            int count = it.second;
            while(count){
                ans=ans+it.first;
                // mp[c]--;
                count--;
            }
        }
        return ans;
    }
};