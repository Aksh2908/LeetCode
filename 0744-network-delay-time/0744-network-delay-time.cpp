class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        queue<pair<int,int>> q;

        q.push({0,k});
        dist[k]=0;

        while(!q.empty()){
            int cost=q.front().first;
            int node=q.front().second;

            q.pop();

            for(auto it:adj[node]){
                if(cost+it.second<dist[it.first]){
                    dist[it.first]=cost+it.second;
                    q.push({cost+it.second,it.first});
                }
            }
        }

        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
        }
        return *max_element(dist.begin()+1,dist.end());
    }
};