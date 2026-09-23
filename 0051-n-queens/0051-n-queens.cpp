class Solution {
private:
    bool isSafe(int r, int c, vector<string>& temp, int n){
        for(int i=r-1;i>=0;i--){
            if(temp[i][c]=='Q') return false;
        }

        int i=r-1,j=c-1;
        while(i>=0 && j>=0){
            if(temp[i][j]=='Q') return false;
            i--;
            j--;
        }
        
        i=r-1,j=c+1;
        while(i>=0 && j>=0){
            if(temp[i][j]=='Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void solve(int n, vector<vector<string>>& ans, vector<string>& temp, int r){
        if(r==n){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(isSafe(r,i,temp,n)){
                temp[r][i]='Q';

                solve(n,ans,temp,r+1);
                temp[r][i]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> temp(n,string(n,'.'));

        solve(n,ans,temp,0);

        return ans;
    }
};