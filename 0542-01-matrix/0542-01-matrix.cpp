class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> dist(m,vector<int>(n,0));

        vector<int> row={-1,0,1,0};
        vector<int> col={0,-1,0,1};

        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!mat[i][j]){
                    q.push({{i,j},0});
                    ans[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int d=q.front().second;

            q.pop();

            dist[i][j]=d;

            for(int k=0;k<4;k++){
                int ni=i+row[k];
                int nj=j+col[k];

                if(ni>=0 && ni<m && nj>=0 && nj<n && !ans[ni][nj]){
                    q.push({{ni,nj},d+1});
                    ans[ni][nj]=1;
                }
            }
        }

        return dist;
    }
};