#include <vector>
// #include <math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0) return 0;
        else if(n==1) return 1;
        vector<char> substr;
        int ans=1;
        substr.push_back(s[0]);
        for(int i=1;i<n;i++){
            std::vector<char>::iterator it = std::find (substr.begin(), substr.end(), s[i]);
            if(it!=substr.end()) {substr.erase(substr.begin());i--;}
            else{substr.push_back(s[i]);}
            // ans=std::max(ans,substr.size());
            if(ans<substr.size()) ans = substr.size();
        }
        return ans;
    }
};