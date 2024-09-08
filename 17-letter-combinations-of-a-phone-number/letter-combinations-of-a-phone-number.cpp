class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> mt;
        mt['2'] = "abc";
        mt['3'] = "def";
        mt['4'] = "ghi";
        mt['5'] = "jkl";
        mt['6'] = "mno";
        mt['7'] = "pqrs";
        mt['8'] = "tuv";
        mt['9'] = "wxyz";
        vector<string> ans;
        if(digits.size()==0) return ans;
        backtrack(ans, "", 0,digits, mt);
        return ans;
    }

    void backtrack(vector<string> &ans, string curr, int i, string digits, map<char, string> mt){
        if(digits.size()==curr.size()){
            ans.push_back(curr);
            return;
        }
        for(char c: mt[digits[i]]){
            backtrack(ans, curr+c, i+1,digits, mt);
        }
    }
};