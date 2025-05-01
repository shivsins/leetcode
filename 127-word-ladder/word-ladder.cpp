class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        int n = beginWord.size();
        unordered_set<string> ws(wordList.begin(), wordList.end());
        ws.insert(beginWord);
        q.push({beginWord,1});
        while(!q.empty()){
            pair<string,int> curr = q.front();
            q.pop();
            if(curr.first==endWord) return curr.second;
            for(int i=0;i<n;i++){
                for(char ch='a';ch<='z';ch++){
                    string nw = curr.first;
                    nw[i] = ch;
                    if(ws.find(nw)!=ws.end()){
                        ws.erase(nw);
                        q.push({nw,curr.second+1});
                    }
                }
            }
        }
        return 0;
    }
};