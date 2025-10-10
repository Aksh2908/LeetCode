class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        typedef pair<int,int> pp;

        vector<vector<pp>> adj(n,vector<pp>());

        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[(u-1)].push_back({(v-1),w});
        }

        priority_queue<pp,vector<pp>,greater<pp>> pq; //time,node

        vector<int> dist(n,1e9);

        pq.push({0,k-1});
        dist[k-1]=0;

        while(!pq.empty()){
            int t=pq.top().first;
            int n=pq.top().second;

            pq.pop();

            for(auto it:adj[n]){
                int v=it.first;
                int w=it.second;

                if(dist[n]+w<dist[v]){
                    dist[v]=dist[n]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        for(auto it:dist){
            if(it==1e9) return -1;
        }
        return *max_element(dist.begin(),dist.end());
    }
};