class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        if(n==1 && m==1) return 0;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        typedef pair<int,pair<int,int>> pp;
        priority_queue<pp,vector<pp>,greater<pp>> pq; //{effort,{x,y}}
        pq.push({0,{0,0}});
        dist[0][0]=0;

        vector<int> row={0,-1,0,1};
        vector<int> col={-1,0,1,0};

        while(!pq.empty()){
            int d=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if (r == n - 1 && c == m - 1) return d;
            for(int i=0;i<4;i++){
                int ni=row[i]+r;
                int nj=col[i]+c;
                if(ni>=0 && ni<n && nj>=0 && nj<m){
                    int newEffort=max(abs(heights[ni][nj]-heights[r][c]),d);
                    if(newEffort<dist[ni][nj]){
                        dist[ni][nj]=newEffort;
                        pq.push({dist[ni][nj],{ni,nj}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};