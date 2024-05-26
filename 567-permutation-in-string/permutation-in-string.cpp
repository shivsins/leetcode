class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // map<char,int> m;
        // for(char c: s1){
        //     m[c]++;
        // }
        // int l=0, r=0;
        // int s2l = s2.size();
        // while(r<s2l){
        //     map<char,int> temp = m;
        //     int res=0;
        //     r=l;
        //     while(!m[s2[r]] && r<s2l){
        //         r++;
        //     }
        //     while(temp[s2[r]] && r<s2l){
        //         res++;
        //         temp[s2[r]]--;
        //         r++;
        //     }
        //     if(res == s1.size()) return true;
        //     l++;
        // }
        // return false;

        map<char,int> m1;
        map<char,int> m2;
        for(char c: s1){
            m1[c]++;
        }
        if(s2.size()<s1.size()) return false;
        for(int i=0;i<s1.size();i++){
            m2[s2[i]]++;
        }
        int l=0, r=s1.size()-1;
        int s2l = s2.size();
        
        while(r<s2l){
            if(m1==m2) return true;
            else{
                if(m2[s2[l]]==1) m2.erase(s2[l]);
                else m2[s2[l]]--;
                l++;
                r++;
                if(r<s2l) m2[s2[r]]++;
            }
        }
        return false;
    }
};