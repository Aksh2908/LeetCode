class Solution {
private:
    int timer=0;
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited, vector<int>& time, vector<int>& low, vector<vector<int>>& bridges){
        visited[node]=1;
        time[node]=timer;
        low[node]=timer;
        timer++;

        for(auto it:adj[node]){ 
            if(it==parent) continue;
            if(!visited[it]){
                dfs(it,node,adj,visited,time,low,bridges);
                low[node]=min(low[node],low[it]);

                if(low[it]>time[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n,vector<int>());

        // create adjcency list
        for(auto it:connections){ //O(E)
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(n,0);//(V)
        vector<int> time(n);//(V)
        vector<int> low(n);//(V)

        vector<vector<int>> bridges;//(E)
        dfs(0,-1,adj,visited,time,low,bridges); //O(V+E)
        return bridges;
    }
};