class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        int i,j,cntFresh=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                } 
                if(grid[i][j]==1) cntFresh++;
            }
        }

        vector<int> delRow={-1,0,1,0};
        vector<int> delCol={0,1,0,-1};
        int t=0; 
        int cnt=0;
        while(!q.empty()){
            pair<pair<int,int>,int> val=q.front();
            q.pop();
            int x=val.first.first;
            int y=val.first.second;
            int time=val.second;
            t=max(t,time);
            for(i=0;i<4;i++){
                int nRow=x+delRow[i];
                int nCol=y+delCol[i];

                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && visited[nRow][nCol]!=2 && grid[nRow][nCol]==1){
                    q.push({{nRow,nCol},time+1});
                    visited[nRow][nCol]=2;
                    cnt++;
                }
            }
        }

        if(cnt!=cntFresh) return -1;
        return t;
    }
};