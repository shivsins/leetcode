class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int total=0;
        vector<int> color(n,0);
        vector<int> ans;
        for(vector<int> q: queries){
            int i = q[0];
            int c = q[1];
            if(c==color[i]) {
                ans.push_back(total);
                continue;
            }
            if(color[i]!=0){
                if(i-1>=0){
                    if(color[i]==color[i-1]) total--;
                }
                if(i+1<n){
                    if(color[i]==color[i+1]) total--;
                }
                color[i]=c;
                if(i-1>=0){
                    if(color[i]==color[i-1]) total++;
                }
                if(i+1<n){
                    if(color[i]==color[i+1]) total++;
                }
            }else{
                color[i]=c;
                if(i-1>=0){
                    if(color[i]==color[i-1]) total++;
                }
                if(i+1<n){
                    if(color[i]==color[i+1]) total++;
                }
            }
            ans.push_back(total);
        }
        return ans;
    }
};