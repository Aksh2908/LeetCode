class Disjoint{
    vector<unsigned long long> parent,size;

    public:
    Disjoint(unsigned long long n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(unsigned long long i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findParent(long long u){
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }

    void unionBySize(long long u, long long v){
        long long pu=findParent(u);
        long long pv=findParent(v);

        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        long long n=accounts.size();
        Disjoint ds(n);
        sort(accounts.begin(),accounts.end());

        unordered_map<string,long long> mpp;

        for(long long i=0;i<n;i++){
            for(long long j=1;j<accounts[i].size();j++){
                string s=accounts[i][j];
                if(mpp.find(s)==mpp.end()){
                    mpp[s]=i;
                }
                else{
                    ds.unionBySize(i,mpp[s]);
                }
            }
        }

        vector<vector<string>> merged(n);

        for(auto it:mpp){
            long long node=ds.findParent(it.second);
            merged[node].push_back(it.first);
        }

        vector<vector<string>> ans;

        for(long long i=0;i<n;i++){
            if(merged[i].size()==0) continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};