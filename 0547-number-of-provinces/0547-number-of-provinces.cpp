class Solution {
public:
    void dfs(int src, vector<bool>& visited, vector<vector<int>> adj){
        visited[src]=1;
        for(auto it:adj[src]){
            if(!visited[it]) dfs(it,visited,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<vector<int>> adj(v);
        int i,j;
        for(i=0;i<v;i++){
            for(j=0;j<v;j++){
                if(isConnected[i][j] && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<bool> visited(v);
        for(i=0;i<v;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,visited,adj);
            }
        }
        return cnt;
    }
};