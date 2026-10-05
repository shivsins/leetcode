#include <vector>
// #include <math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int l = 0, r = 1, n=s.size();
        int res = 1;
        m[s[l]]++;
        if(n==0) return 0;
        while(r<n){
            if(!m[s[r]]){
                m[s[r]]++;
                res=max(res, r-l+1);
                r++;
            }else{
                res=max(res, r-l);
                while(l<r && m[s[r]]){
                    m[s[l]]--;
                    l++;
                }
            }
        }
        return res;
    }
};