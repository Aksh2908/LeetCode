class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        pair<int,int> source={0,0};
        pair<int,int> destination={n-1,n-1};
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(source==destination) return 1;

        vector<vector<int>> visited(n,vector<int>(n,0));
        typedef pair<int,pair<int,int>> pp;
        
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({1,{source.first,source.second}});
        visited[source.first][source.second]=1;
        
        vector<int> row={0,-1,-1,-1,0,1,1,1};
        vector<int> col={-1,-1,0,1,1,1,0,-1};
        
        while(!pq.empty()){
            int dist=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            if(r==destination.first && c==destination.second) return dist;
            pq.pop();
            
            for(int i=0;i<8;i++){
                int ni=row[i]+r;
                int nj=col[i]+c;
                if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==0 && !visited[ni][nj]){
                    pq.push({dist+1,{ni,nj}});
                    visited[ni][nj]=1;
                }
            }
        }
        return -1;
    }
};