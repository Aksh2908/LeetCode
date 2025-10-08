class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            dist[u][v]=w;
            dist[v][u]=w;
        }

        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(dist[j][i]!=1e9 && dist[i][k]!=1e9){
                        dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
                    }
                }
            }
        }

        int maxNode=-1;
        int minCnt=INT_MAX;
        
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=minCnt){
                minCnt=min(minCnt,cnt);
                maxNode=max(maxNode,i);
            }
        }
        return maxNode;
    }
};