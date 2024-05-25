class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> m;
        int l=0, r = 0;
        int res = 1;
        int n = s.size();
        int maxi=0;;
        while(r<n){
            m[s[r]]++;
            maxi = max(maxi, m[s[r]]);
            while(((r-l+1) - maxi)>k){
                m[s[l]]--;
                maxi=0;
                for(auto it = m.begin(); it!=m.end(); it++){
                    maxi = max(maxi,it->second);
                }
                l++;   
            }
            
            res = max(res, r-l+1);
            r++;

        }
        return res;
    }
};