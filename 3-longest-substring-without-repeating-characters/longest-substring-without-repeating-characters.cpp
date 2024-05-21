#include <vector>
// #include <math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int l = 0, r = 1;
        int res = 1;
        m[s[l]]++;
        if(s.size()==0 || s.size()==1) return s.size();
        while(r<s.size()){
            if(!m[s[r]]){
                res = max(res,r-l+1);
                m[s[r]]++;
                r++;
            }else{
                m[s[l]]--;
                l++;
            }
        }
        return res;
    }
};