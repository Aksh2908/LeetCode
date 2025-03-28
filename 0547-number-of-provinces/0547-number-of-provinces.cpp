class Solution {
private:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited,int src){
        visited[src]=true;
        for(int i=0;i<adj[src].size();i++) if(!visited[adj[src][i]]) dfs(adj,visited,adj[src][i]);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n,vector<int>());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n,false);
        int cnt=0;
        for(int i=0;i<n;i++) {
            if(!visited[i]){ 
                cnt++;
                dfs(adj,visited,i);
            }
        }
        return cnt;
    }
};