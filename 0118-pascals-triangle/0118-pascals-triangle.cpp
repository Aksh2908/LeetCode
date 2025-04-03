class Solution {
public:
    long long nCr(int n, int r){
        long long res=1;
        for(int i=0;i<r;i++){
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int i,j;
        for(i=0;i<numRows;i++){
            vector<int> row;
            for(j=0;j<=i;j++){
                row.push_back(nCr(i,j));
            }
            ans.push_back(row);
        }
        return ans;
    }
};