class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0,r=0;
        int ans=0;
        map<int,int> mp;
        while(r<n){
            mp[fruits[r]]++;
            if(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }else{
                int len = r-l+1;
                ans=max(ans,len);
            }
            r++;
        }
        return ans;
    }
};