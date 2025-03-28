class Solution {
private:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int src){
        visited[src]=1;
        for(int i=0;i<adj[src].size();i++){
            if(!visited[adj[src][i]]) dfs(adj,visited,adj[src][i]);
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n,vector<int>());
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);
        dfs(adj,visited,source);
        return visited[destination];
    }
};