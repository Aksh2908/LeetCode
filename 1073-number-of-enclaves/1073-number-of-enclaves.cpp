class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, vector<int>& row, vector<int>& col, int i, int j, int m, int n){
        visited[i][j]=1;

        for(int k=0;k<4;k++){
            int ni=i+row[k];
            int nj=j+col[k];

            if(ni>=0 && ni<m && nj>=0 && nj<n && !visited[ni][nj] && grid[ni][nj]){
                dfs(grid,visited,row,col,ni,nj,m,n);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<int> row={-1,0,1,0};
        vector<int> col={0,-1,0,1};

        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && !visited[i][j] && grid[i][j]){
                    dfs(grid,visited,row,col,i,j,m,n);
                }
            }
        }

        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]) cnt++;
            }
        }
        return cnt;
    }
};