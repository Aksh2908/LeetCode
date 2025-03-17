class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<vector<int>>& image, int sr, int sc, int iniColor, int color, vector<int>& delRow, vector<int>& delCol, int n, int m){
        int i;
        ans[sr][sc]=color;
        for(i=0;i<4;i++){
            int nRow=sr+delRow[i];
            int nCol=sc+delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol]==iniColor && ans[nRow][nCol]!=color) dfs(ans,image,nRow,nCol,iniColor,color,delRow,delCol,n,m);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor=image[sr][sc];
        vector<vector<int>> ans=image;
        vector<int> delRow={-1,0,1,0};
        vector<int> delCol={0,1,0,-1};
        int n=image.size(),m=image[0].size();
        dfs(ans,image,sr,sc,iniColor, color, delRow, delCol,n,m);
        return ans;
    }
};