class Solution {
private:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, int m, int n, vector<int>& row, vector<int>& col){
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int ni=i+row[k];
            int nj=j+col[k];

            if(ni>=0 && ni<=m-1 && nj>=0 && nj<=n-1 && !visited[ni][nj] && board[ni][nj]=='O'){
                dfs(board,visited,ni,nj,m,n,row,col);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<int> row={-1,0,1,0};
        vector<int> col={0,-1,0,1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(board[i][j]=='O'){
                        dfs(board,visited,i,j,m,n,row,col);
                    }
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};