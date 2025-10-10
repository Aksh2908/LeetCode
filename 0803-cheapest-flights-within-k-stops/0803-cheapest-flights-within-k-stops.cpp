class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());

        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        typedef pair<int,pair<int,int>> pp;
        queue<pp> q; //{stops,{cost,node}}
        vector<int> dist(n,INT_MAX);
        q.push({0,{0,src}});
        dist[src]=0;

        while(!q.empty()){
            int stops=q.front().first;
            int cost=q.front().second.first;
            int node=q.front().second.second;

            q.pop();
            if(stops>k) continue;
            for(auto it:adj[node]){
                int u=it.first;
                int c=it.second;
                if(c+cost<dist[u] && stops<=k){
                    dist[u]=c+cost;
                    q.push({stops+1,{c+cost,u}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};