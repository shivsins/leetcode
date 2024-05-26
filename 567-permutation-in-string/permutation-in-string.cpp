class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> m;
        for(char c: s1){
            m[c]++;
        }
        int l=0, r=0;
        int s2l = s2.size();
        while(r<s2l){
            map<char,int> temp = m;
            int res=0;
            r=l;
            while(!m[s2[r]] && r<s2l){
                r++;
            }
            while(temp[s2[r]] && r<s2l){
                res++;
                temp[s2[r]]--;
                r++;
            }
            if(res == s1.size()) return true;
            l++;
        }
        return false;
    }
};