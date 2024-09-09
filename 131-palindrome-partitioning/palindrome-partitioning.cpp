// we loop in the string to put a partition in the string, and we only move forward for a particular case if
// the first partition is a palindrome, if not then we dont consider that case.
// if yes we apply backtrack to the rest of the partition the same way
// so when idx is out of bounds we will know all the partition has been a palindrome bcz that's why
// we added it to the curr


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        int n = s.size();
        bt(res, curr, 0, n, s);
        return res;
    }

    bool isPal(string s, int l, int r){
        while(l<=r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void bt(vector<vector<string>> &res, vector<string> curr, int idx, int n, string s){
        if(idx>=n){
            res.push_back(curr);
            return;
        }
        for(int i = idx;i<n;i++){
            if(isPal(s, idx, i)){
                curr.push_back(s.substr(idx, i-idx+1));
                bt(res, curr, i+1, n, s);
                curr.pop_back();
            }
        }
    }
};