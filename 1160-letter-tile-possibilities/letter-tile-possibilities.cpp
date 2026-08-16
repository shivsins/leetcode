class Solution {
public:
    int numTilePossibilities(string tiles) {
        int ans=0;
        set<string> s;
        map<char,int> count;
        for(int i=0;i<tiles.size();i++){
            count[tiles[i]]++;
        }
        bt(tiles,"",s,count);
        return s.size();
    }

    void bt(string tiles, string curr, set<string> &s, map<char,int> &count){
        for(char c : tiles){
            if(count[c]>0){
                curr+=string(1,c);
                count[c]--;
                s.insert(curr);
                bt(tiles, curr,s,count);
                curr.pop_back();
                count[c]++;
            }
        }
    }
};