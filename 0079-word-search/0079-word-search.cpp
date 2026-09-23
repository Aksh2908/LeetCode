class Solution {
private:
    bool check(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, vector<int>& row, vector<int>& col, int r, int c, int idx, int m, int n){
        if(idx==word.size()){
            return true;
        }

        if(r<0 || r>=m || c>=n || c<0) return false;

        if(visited[r][c]) return false;
    
        if(board[r][c]==word[idx]){
                visited[r][c]=1;
                if(check(board,word,visited,row,col,r,c-1,idx+1,m,n) || check(board,word,visited,row,col,r-1,c,idx+1,m,n) || check(board,word,visited,row,col,r,c+1,idx+1,m,n) || check(board,word,visited,row,col,r+1,c,idx+1,m,n)) return true;
                visited[r][c]=0;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,0));

        vector<int> row={0,-1,0,1};
        vector<int> col={-1,0,1,0};
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == word[0]) {
                    if(check(board,word,visited,row,col,i,j,0,m,n)) return true;
                }
            }
        }
        return false;
    }
};