#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        typedef pair<long long,int> pp;
        vector<vector<pp>> adj(n);

        for(auto it : roads){
            adj[it[0]].push_back({it[1], (long long)it[2]});
            adj[it[1]].push_back({it[0], (long long)it[2]});
        }

        vector<int> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);

        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        int mod = (int)(1e9 + 7);

        while(!pq.empty()){
            long long w = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for(auto it : adj[u]){
                int v = it.first;
                long long wt = it.second;

                if(w + wt < dist[v]){
                    dist[v] = w + wt;
                    pq.push({dist[v], v});
                    ways[v] = ways[u];
                }
                else if(dist[v] == w + wt){
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};
