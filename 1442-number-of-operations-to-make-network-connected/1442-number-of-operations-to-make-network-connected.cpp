class Disjoint{
    public:
        vector<unsigned long long> parent,size;
        Disjoint(int n){
            parent.resize(n+1);
            size.resize(n+1,1);

            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }

        int findParent(int u){
            if(u==parent[u]) return u;
            return parent[u]=findParent(parent[u]);
        }

        void unionBySize(int u, int v){
            int pu=findParent(u);
            int pv=findParent(v);

            if(size[pu]<size[pv]){
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
            else{
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint ds(n);

        int extras=0,connected=0;

        for(auto it:connections){
            if(ds.findParent(it[0])==ds.findParent(it[1])){
                extras++;
            }
            ds.unionBySize(it[0],it[1]);
        }

        for(int i=0;i<n;i++){
            if(ds.findParent(i)==i) connected++;
        }

        if(extras>=(connected-1)) return connected-1;
        return -1;
    }
};