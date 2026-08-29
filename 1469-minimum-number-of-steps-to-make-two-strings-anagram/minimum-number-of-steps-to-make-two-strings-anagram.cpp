class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> sm, tm;
        for(char c: s){
            sm[c]++;
        }
        for(char c: t){
            tm[c]++;
        }
        int ans=0;
        for(auto it: sm){
            char c = it.first;
            int val = it.second;
            int diff=val-tm[c];
            if(diff>0) ans=ans+diff;
        }
        return ans;
    }
};