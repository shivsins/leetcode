class Solution {
public:
    vector<int> parent, size;

    int findParent(int node){
        if(parent[node]==node) return node;
        else return parent[node]=findParent(parent[node]);
    }

    void unite(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu==pv) return;
        else if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
        int extra=0;
        for(auto c : connections){
            int u = c[0], v = c[1];
            int pu = findParent(u);
            int pv = findParent(v);
            if(pu==pv) extra++;
            else{
                unite(u,v);
            }
        }
        int noc = 0;
        for(int i=0; i<n; i++){
            if(parent[i]==i){
                noc++;
            }
        }
         if(extra>=noc-1) return noc-1;
         return -1;
    }
};