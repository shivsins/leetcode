//very good question. 
//the first commented approach is kind of brute force approach but it still works under the give time frame.
// the second approach is O(constant*n).
//in second we are moving in batches if s1.length. and creating map for s2 on the fly and we check whether the two maps match or not.
// just remember to erase the key if it decreases to 0 count.


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