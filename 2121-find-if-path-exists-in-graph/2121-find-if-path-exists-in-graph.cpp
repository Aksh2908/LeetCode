class Solution {
private:
    bool isPath(vector<vector<int>> adj, int src, int dst, int v){
        queue<int> q;
        vector<bool> visited(v+1);
        q.push(src);
        visited[src];
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==dst) return true;
            for(auto it:adj[node]){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        int u,v;
        for(auto it:edges){
            u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return isPath(adj,source,destination,n);
    }
};